# Intermediate Code Generation (ICG) Implementation & Technical Presentation Tutorial

## 1. System Overview & Architecture

The compiler translates a subset of C (`CSubset`) into 32-bit x86 assembly formatted for the Flat Assembler (FASM).

### Pipeline Flow
```
+------------------+     +------------------+     +------------------+
| C Subset Source  | --> | ANTLR4 Lexer &   | --> | ANTLR Parse Tree |
|     Code (.c)    |     | Parser (.g4)     |     |   (AST Nodes)    |
+------------------+     +------------------+     +------------------+
                                                           |
                                                           v
+------------------+     +------------------+     +------------------+
|  FASM Executable | <-- | Peephole         | <-- | TreeVisitor      |
|    (a.out / ELF) |     | Optimizer        |     | (Code Generator) |
+------------------+     +------------------+     +------------------+
```

---

## 2. Register Usage & Memory Model

### Register Roles
- `EAX`: Primary Accumulator. Holds expression evaluation results, arithmetic operands, and function return values.
- `EBX`: Secondary Register. Holds array element memory addresses, right-hand operands during binary operations, and syscall parameters.
- `EDX`: High 32 bits for division (`IDIV`) and remainder storage.
- `EBP`: Base Pointer. Establishes the base of the current stack frame.
- `ESP`: Stack Pointer. Tracks the top of the stack.

### Stack Layout (32-bit `cdecl`)
```
                     +-----------------------+
                     |  Argument N           |  [EBP + 8 + 4*(N-1)]
                     |  ...                  |
                     |  Argument 1           |  [EBP + 8]
                     +-----------------------+
                     |  Return Address       |  [EBP + 4]
                     +-----------------------+
      EBP Pointer -> |  Old EBP              |  [EBP + 0]
                     +-----------------------+
                     |  Local Variable 1     |  [EBP - 4]
                     |  Local Variable 2     |  [EBP - 8]
                     |  ...                  |
      ESP Pointer -> |  Local Variable M     |  [EBP - 4*M]
                     +-----------------------+
```

---

## 3. Detailed Component Implementation

### 3.1 Function Definitions & Stack Frame Setup

#### Code Implementation (`TreeVisitor::visitFuncdef_with_param`)
```cpp
any TreeVisitor::visitFuncdef_with_param(CSubset_2205009Parser::Funcdef_with_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();

    SymbolInfo *prv = st.lookupLocal(funcName);
    if (prv == NULL) {
        SymbolInfo *si = new SymbolInfo(funcName, "ID");
        si->setIsFunction(true);
        si->setIsDefined(true);
        si->setretType(tNd.type);
        st.insert(si);
    }
    codeOut << funcName << ":\n";
    codeOut << "\tPUSH EBP\n";
    codeOut << "\tMOV EBP, ESP\n";

    nextLocalOffset = 4;
    currentFuncName = funcName;

    st.enterScope();
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));

    for (size_t i = 0; i < pNd.paramNames.size(); i++) {
        string pName = pNd.paramNames[i];
        string pType = pNd.paramTypes[i];
        if (!pName.empty()) {
            if (st.lookupLocal(pName) == NULL) {
                SymbolInfo *pInfo = new SymbolInfo(pName, "ID");
                pInfo->setVarType(pType);
                pInfo->setIsGlobal(false);
                pInfo->setOffset(-(8 + 4 * (int)i));
                st.insert(pInfo);
            }
        }
    }

    skpNxt = true;
    ParseNode cNd = std::any_cast<ParseNode>(visit(ctx->compound_statement()));

    if (funcName == "main") {
        codeOut << "\tMOV ESP, EBP\n";
        codeOut << "\tPOP EBP\n";
        codeOut << "\tMOV EAX, 1\n";
        codeOut << "\tXOR EBX, EBX\n";
        codeOut << "\tINT 0x80\n";
    } else {
        codeOut << "\tMOV ESP, EBP\n";
        codeOut << "\tPOP EBP\n";
        codeOut << "\tRET\n";
    }

    return ParseNode{};
}
```

#### Assembly Output Breakdown
- Parameter `i` is bound at offset `-(8 + 4*i)`. Because local lookups generate `[EBP - offset]`, `[EBP - (-(8 + 4*i))]` evaluates directly to `[EBP + 8 + 4*i]`.
- Callee prolog:
  ```assembly
  func:
      PUSH EBP
      MOV EBP, ESP
  ```
- Callee epilog:
  ```assembly
      MOV ESP, EBP
      POP EBP
      RET
  ```

---

### 3.2 Function Calls & On-The-Fly Argument Evaluation

#### Code Implementation (`TreeVisitor::visitFactor_func_call`, `visitArgs_multi`, `visitArgs_single`)
```cpp
any TreeVisitor::visitFactor_func_call(CSubset_2205009Parser::Factor_func_callContext *ctx) {
    string funcName = ctx->ID()->getText();
    ParseNode aNd;
    if (ctx->argument_list()) {
        aNd = std::any_cast<ParseNode>(visit(ctx->argument_list()));
    }

    int numArgs = aNd.intVal;

    codeOut << "\tCALL " << funcName << "\n";
    if (numArgs > 0) {
        codeOut << "\tADD ESP, " << (numArgs * 4) << "\n";
    }

    return ParseNode{};
}

any TreeVisitor::visitArgs_multi(CSubset_2205009Parser::Args_multiContext *ctx) {
    // Right-to-left evaluation for cdecl calling convention on-the-fly
    visit(ctx->logic_expression());
    codeOut << "\tPUSH EAX\n";

    ParseNode aNd = std::any_cast<ParseNode>(visit(ctx->arguments()));
    ParseNode res;
    res.intVal = aNd.intVal + 1;
    return res;
}

any TreeVisitor::visitArgs_single(CSubset_2205009Parser::Args_singleContext *ctx) {
    visit(ctx->logic_expression());
    codeOut << "\tPUSH EAX\n";
    ParseNode res;
    res.intVal = 1;
    return res;
}
```

#### Key Mechanics
- **On-The-Fly Generation**: Arguments are evaluated and pushed onto the stack during parse tree traversal without storing lists or AST node pointers in `ParseNode`.
- **Right-to-Left Traversal**: In `visitArgs_multi`, visiting `logic_expression` before `arguments` ensures rightmost arguments are evaluated and pushed first (`PUSH EAX`), strictly conforming to the 32-bit `cdecl` calling convention.
- **Stack Cleanup**: The caller cleans up the stack post-call via `ADD ESP, 4 * numArgs`.

---

### 3.3 Control Flow Translation

#### 1. If-Else Statements (`TreeVisitor::visitStat_if_else`)
```cpp
any TreeVisitor::visitStat_if_else(CSubset_2205009Parser::Stat_if_elseContext *ctx) {
    ParseNode e = std::any_cast<ParseNode>(visit(ctx->expression()));
    string lb_else = "L" + to_string(segment_no++);
    string lb_exit = "L" + to_string(segment_no++);

    codeOut << "\tCMP EAX, 0\n";
    codeOut << "\tJE " << lb_else << "\n";

    ParseNode st1 = std::any_cast<ParseNode>(visit(ctx->statement(0)));
    codeOut << "\tJMP " << lb_exit << "\n";

    codeOut << lb_else << ":\n";
    ParseNode st2 = std::any_cast<ParseNode>(visit(ctx->statement(1)));
    codeOut << lb_exit << ":\n";

    return ParseNode{};
}
```

#### 2. While Loops (`TreeVisitor::visitStat_while`)
```cpp
any TreeVisitor::visitStat_while(CSubset_2205009Parser::Stat_whileContext *ctx) {
    string lb_start = "L" + to_string(segment_no++);
    string lb_exit = "L" + to_string(segment_no++);

    codeOut << lb_start << ":\n";
    ParseNode ex = std::any_cast<ParseNode>(visit(ctx->expression()));
    codeOut << "\tCMP EAX, 0\n";
    codeOut << "\tJE " << lb_exit << "\n";

    ParseNode st = std::any_cast<ParseNode>(visit(ctx->statement()));
    codeOut << "\tJMP " << lb_start << "\n";
    codeOut << lb_exit << ":\n";

    return ParseNode{};
}
```

#### 3. For Loops (`TreeVisitor::visitStat_for_loop`)
```cpp
any TreeVisitor::visitStat_for_loop(CSubset_2205009Parser::Stat_for_loopContext *ctx) {
    ParseNode ex1 = std::any_cast<ParseNode>(visit(ctx->expression_statement(0)));
    string lb_start = "L" + to_string(segment_no++);
    string lb_exit = "L" + to_string(segment_no++);

    codeOut << lb_start << ":\n";
    ParseNode ex2 = std::any_cast<ParseNode>(visit(ctx->expression_statement(1)));
    codeOut << "\tCMP EAX, 0\n";
    codeOut << "\tJE " << lb_exit << "\n";

    ParseNode s = std::any_cast<ParseNode>(visit(ctx->statement()));
    ParseNode ex3 = std::any_cast<ParseNode>(visit(ctx->expression()));

    codeOut << "\tJMP " << lb_start << "\n";
    codeOut << lb_exit << ":\n";

    return ParseNode{};
}
```

---

### 3.4 Array Subscripting & Memory Calculation

#### Pointer Arithmetic & Address Resolution (`TreeVisitor::visitVar_arr`)
```cpp
any TreeVisitor::visitVar_arr(CSubset_2205009Parser::Var_arrContext *ctx) {
    string id = ctx->ID()->getText();
    SymbolInfo *sym = st.lookup(id);
    if (sym == NULL) return ParseNode{};

    ParseNode eNd = std::any_cast<ParseNode>(visit(ctx->expression()));
    codeOut << "\tSHL EAX, 2\n";

    if (sym->getIsGlobal()) {
        codeOut << "\tLEA EBX, [" << id << "]\n";
        codeOut << "\tADD EBX, EAX\n";
    } else {
        int baseOffset = sym->getOffset();
        codeOut << "\tMOV EBX, EBP\n";
        codeOut << "\tSUB EBX, " << baseOffset << "\n";
        codeOut << "\tSUB EBX, EAX\n";
    }

    codeOut << "\tMOV EAX, [EBX]\n";
    codeOut << "\tPUSH EBX\n";

    ParseNode p;
    p.isArray = true;
    p.text = id;
    p.type = sym->getVarType();
    return p;
}
```

#### Array Assignment Handling (`TreeVisitor::visitExpr_assign`)
```cpp
    if (vNd.isArray) {
        codeOut << "\tPOP EBX\n";
        codeOut << "\tMOV [EBX], EAX\n";
    }
```

---

## 4. Peephole Optimization Phase

The `optimizer` function in `2205009_Optimizer.h` performs iterative pass optimizations:

1. **Redundant Stack Operations**:
   ```assembly
   PUSH EAX     --> (Eliminated)
   POP EAX
   ```
2. **Redundant Moves**:
   ```assembly
   MOV EAX, EBX --> MOV EAX, EBX
   MOV EBX, EAX --> (Eliminated)
   ```
3. **Identity Operations**:
   - `ADD EAX, 0` / `SUB EAX, 0` $\rightarrow$ (Eliminated)
   - `IMUL EAX, 1` $\rightarrow$ (Eliminated)
4. **Unreachable Label Cleanup**: Merges consecutive labels pointing to identical code positions.

---

## 5. Test Suite Verification Summary

All 12 benchmark test cases run and verify against expected output:

| Test Case File | Feature Tested | Result Status |
| :--- | :--- | :--- |
| `test1_i.c` | Basic arithmetic, logic ops, unary neg, post-inc | PASSED |
| `test2_i.c` | If / else-if / else branching | PASSED |
| `test3_i.c` | For loop, while loop, condition post-dec | PASSED |
| `test4_i.c` | Void functions, parameters, complex expression calls | PASSED |
| `test5_i.c` | Nested loops, multi-argument functions, modulo arithmetic | PASSED |
| `test6_i.c` | Global & local 1D arrays, array indexing, array post-inc | PASSED |
| `test7_i.c` | Complex nested boolean condition expressions | PASSED |
| `func.c` | Multi-level function invocation | PASSED |
| `loop.c` | Nested while in for loop with post-decrement | PASSED |
| `exp.c` | Array assignment inside conditionals | PASSED |
| `recursion1_i.c` | Mutual/tree recursion with multi-parameter functions | PASSED (Result: `63`) |
| `recursion2_i.c` | Single linear recursion with local scope variables | PASSED (Result: `28`) |
