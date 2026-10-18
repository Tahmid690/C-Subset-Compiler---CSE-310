#include "TreeVisitor.h"
#include <bits/stdc++.h>

using namespace std;
using namespace antlr4;

TreeVisitor::TreeVisitor() : st(30), errcnt(0), skpNxt(false) {
    codeOut.open("code.asm");
    golbOut.open("glb.txt");
    segment_no = 0;
    nextLocalOffset = 4;
    global_flag = 1;
}

TreeVisitor::~TreeVisitor() {
    
}



any TreeVisitor::visitStart(CSubset_2205009Parser::StartContext *ctx) {
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->program()));
    
    codeOut.close();
    golbOut.close();


    ifstream cd_stm("code.asm");
    stringstream cdb;
    cdb << cd_stm.rdbuf();
    cd_stm.close();

    ofstream fOut("code.asm");
    fOut << "format ELF executable 3\n";
    fOut << "entry main\n\n";
    fOut << "segment readable writeable\n";

    

    ifstream golb_stm("glb.txt");
    fOut << golb_stm.rdbuf();
    golb_stm.close();
    fOut.clear(); 

    

    fOut << "segment readable executable\n";

    fOut << cdb.str();
    fOut << "include 'printProc.lib'\n";
    fOut.close();
    
    remove("glb.txt");
    
    return ParseNode{""};
}


any TreeVisitor::visitProgUnitRule(CSubset_2205009Parser::ProgUnitRuleContext *ctx) {
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->program()));
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unit()));
    // printLog(ctx->unit()->getStart()->getLine(), "program : program unit", ruleTxt);
    return ParseNode{};
}

any TreeVisitor::visitUnitRule(CSubset_2205009Parser::UnitRuleContext *ctx) {
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unit()));
    // printLog(ctx->unit()->getStart()->getLine(), "program : unit", uNd.text);
    return ParseNode{uNd.text};
}

any TreeVisitor::visitVar_dec(CSubset_2205009Parser::Var_decContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->var_declaration()));
    // printLog(ctx->getStart()->getLine(), "unit : var_declaration", nd.text);
    return ParseNode{nd.text};
}

any TreeVisitor::visitFunc_dec(CSubset_2205009Parser::Func_decContext *ctx) {
    // ParseNode nd = std::any_cast<ParseNode>(visit(ctx->func_declaration()));
    // printLog(ctx->getStart()->getLine(), "unit : func_declaration", nd.text);
    // logOut << "\n";
    // return ParseNode{nd.text};
    return ParseNode{};
}

any TreeVisitor::visitFunc_def(CSubset_2205009Parser::Func_defContext *ctx) {
    
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->func_definition()));
    // printLog(ctx->getStart()->getLine(), "unit : func_definition", nd.text);
    return ParseNode{};
}


any TreeVisitor::visitType_int(CSubset_2205009Parser::Type_intContext *ctx) {
    // printLog(ctx->getStart()->getLine(), "type_specifier : INT", "int");
    return ParseNode{"int", "INT"};
}

any TreeVisitor::visitType_float(CSubset_2205009Parser::Type_floatContext *ctx) {
    // printLog(ctx->getStart()->getLine(), "type_specifier : FLOAT", "float");
    return ParseNode{"float", "FLOAT"};
}

any TreeVisitor::visitType_void(CSubset_2205009Parser::Type_voidContext *ctx) {
    // printLog(ctx->getStart()->getLine(), "type_specifier : VOID", "void");
    return ParseNode{"void", "VOID"};
}

any TreeVisitor::visitVar_declaration(CSubset_2205009Parser::Var_declarationContext *ctx) {
    
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    currTyp = tNd.type;
    ParseNode dNd = std::any_cast<ParseNode>(visit(ctx->declaration_list()));
    if (tNd.type == "VOID") {
        // printErr(ctx->getStart()->getLine(), "Variable type cannot be void");
    }
    // printLog(ctx->getStart()->getLine(), "var_declaration : type_specifier declaration_list SEMICOLON", ruleTxt);
    return ParseNode{};
}

any TreeVisitor::visitDec_with_id_single(CSubset_2205009Parser::Dec_with_id_singleContext *ctx) {
    string id = ctx->ID()->getText();
    if (currTyp != "VOID") {
        if (st.lookupLocal(id) != NULL) {
            // printErr(ctx->getStart()->getLine(), "Multiple declaration of " + id);
        }
        else{
            SymbolInfo *si = new SymbolInfo(id, "ID");
            si->setVarType(currTyp);

            if(st.getCurrentScope()->getScopeId() == "1"){
                si->setIsGlobal(true);
                golbOut << "\t" << id << " dd 1 DUP (0)" << endl;
            }
            else{
                si->setIsGlobal(false);
                si->setOffset(nextLocalOffset);
                nextLocalOffset += 4;
                codeOut << "\tSUB ESP, 4\n";
                
            }

            
            st.insert(si);
        }
    }
    // printLog(ctx->getStart()->getLine(), "declaration_list : ID", id);
    return ParseNode{};
}

any TreeVisitor::visitDec_with_id(CSubset_2205009Parser::Dec_with_idContext *ctx) {
    ParseNode dNd = std::any_cast<ParseNode>(visit(ctx->declaration_list()));
    string id = ctx->ID()->getText();
    if (currTyp != "VOID"){
        if (st.lookupLocal(id) != NULL) {
            // printErr(ctx->getStart()->getLine(), "Multiple declaration of " + id);
        }
        else{
            SymbolInfo *si = new SymbolInfo(id, "ID");
            si->setVarType(currTyp);

            if(st.getCurrentScope()->getScopeId() == "1"){
                si->setIsGlobal(true);
                golbOut << "\t" << id << " dd 1 DUP (0)" << endl;
            }
            else{
                si->setIsGlobal(false);
                si->setOffset(nextLocalOffset);
                nextLocalOffset += 4;
                codeOut << "\tSUB ESP, 4\n";
            }
            st.insert(si);
        }
    }
    // printLog(ctx->getStart()->getLine(), "declaration_list : declaration_list COMMA ID", ruleTxt);
    return ParseNode{};
}

any TreeVisitor::visitDec_with_idarr_single(CSubset_2205009Parser::Dec_with_idarr_singleContext *ctx) {
    string id = ctx->ID()->getText();
    string szStr = ctx->CONST_INT()->getText();
    int sz = stoi(szStr);
    if (currTyp != "VOID") {
        if (st.lookupLocal(id) == NULL) {
            SymbolInfo *si = new SymbolInfo(id, "ID");
            si->setVarType(currTyp);
            si->setisArr(true);
            si->setarrSz(sz);
            if (st.getCurrentScope()->getScopeId() == "1") {
                si->setIsGlobal(true);
                golbOut << "\t" << id << " dd " << sz << " DUP (0)" << endl;
            } else {
                si->setIsGlobal(false);
                si->setOffset(nextLocalOffset);
                nextLocalOffset += 4 * sz;
                codeOut << "\tSUB ESP, " << (4 * sz) << "\n";
            }
            st.insert(si);
        }
    }
    // string ruleTxt = id + "[" + szStr + "]";
    // printLog(ctx->getStart()->getLine(), "declaration_list : ID LTHIRD CONST_INT RTHIRD", ruleTxt);
    return ParseNode{};
}

any TreeVisitor::visitDec_with_idarr(CSubset_2205009Parser::Dec_with_idarrContext *ctx) {
    ParseNode dNd = std::any_cast<ParseNode>(visit(ctx->declaration_list()));
    string id = ctx->ID()->getText();
    string szStr = ctx->CONST_INT()->getText();
    int sz = stoi(szStr);
    if (currTyp != "VOID") {
        if (st.lookupLocal(id) == NULL) {
            SymbolInfo *si = new SymbolInfo(id, "ID");
            si->setVarType(currTyp);
            si->setisArr(true);
            si->setarrSz(sz);
            if (st.getCurrentScope()->getScopeId() == "1") {
                si->setIsGlobal(true);
                golbOut << "\t" << id << " dd " << sz << " DUP (0)" << endl;
            } else {
                si->setIsGlobal(false);
                si->setOffset(nextLocalOffset);
                nextLocalOffset += 4 * sz;
                codeOut << "\tSUB ESP, " << (4 * sz) << "\n";
            }
            st.insert(si);
        }
    }
    // string ruleTxt = dNd.text + "," + id + "[" + szStr + "]";
    // printLog(ctx->getStart()->getLine(), "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", ruleTxt);
    return ParseNode{};
}



any TreeVisitor::visitDec_with_addop(CSubset_2205009Parser::Dec_with_addopContext *ctx) {
    return ParseNode{};
}

any TreeVisitor::visitParam_with_addop(CSubset_2205009Parser::Param_with_addopContext *ctx) {
    return ParseNode{};
}

any TreeVisitor::visitExpr_assign_addop(CSubset_2205009Parser::Expr_assign_addopContext *ctx) {
    return ParseNode{};
}





any TreeVisitor::visitFuncdec_with_param(CSubset_2205009Parser::Funcdec_with_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();
    
    st.enterScope();
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));
    st.exitScope();

    SymbolInfo *si = new SymbolInfo(funcName, "ID");
    si->setIsFunction(true);
    si->setretType(tNd.type);
    si->setParams(pNd.paramTypes, pNd.paramNames);
    st.insert(si);

    // string ruleTxt = tNd.text + " " + funcName + "(" + pNd.text + ");";
    // printLog(ctx->getStart()->getLine(), "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON", ruleTxt);
    // logOut << "\n";
    return ParseNode{};
}

any TreeVisitor::visitFuncdec_without_param(CSubset_2205009Parser::Funcdec_without_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();
    SymbolInfo *si = new SymbolInfo(funcName, "ID");
    si->setIsFunction(true);
    si->setretType(tNd.type);
    st.insert(si);
    // string ruleTxt = tNd.text + " " + funcName + "();";
    // printLog(ctx->getStart()->getLine(), "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON", ruleTxt);
    // logOut << "\n";
    return ParseNode{};
}




any TreeVisitor::visitFuncdef_with_param(CSubset_2205009Parser::Funcdef_with_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();

    codeOut << funcName << ":\n";
    codeOut << "\tPUSH EBP\n";
    codeOut << "\tMOV EBP, ESP\n";

    nextLocalOffset = 4;
    currentFuncName = funcName;

    st.enterScope();
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));

    SymbolInfo *prv = st.lookupLocal(funcName);
    if (prv == NULL) {
        SymbolInfo *si = new SymbolInfo(funcName, "ID");
        si->setIsFunction(true);
        si->setIsDefined(true);
        si->setretType(tNd.type);
        si->setParams(pNd.paramTypes, pNd.paramNames);
        st.insert(si);
    } else {
        prv->setIsDefined(true);
        prv->setParams(pNd.paramTypes, pNd.paramNames);
    }

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

    // string ruleTxt = tNd.text + " " + funcName + "(" + pNd.text + ")" + cNd.text;
    // printLog(ctx->getStart()->getLine(), "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement", ruleTxt);
    // logOut << "\n";

    if (funcName == "main") {
        codeOut << "\tMOV ESP, EBP\n";
        codeOut << "\tPOP EBP\n";
        codeOut << "\tMOV EAX, 1\n";
        codeOut << "\tXOR EBX, EBX\n";
        codeOut << "\tINT 0x80\n";
    }
    else {
        codeOut << "\tMOV ESP, EBP\n";
        codeOut << "\tPOP EBP\n";
        codeOut << "\tRET\n";
    }

    return ParseNode{};
}



any TreeVisitor::visitFuncdef_without_param(CSubset_2205009Parser::Funcdef_without_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();

    SymbolInfo *prv = st.lookupLocal(funcName);
    if (prv != NULL) {
        if (prv->getIsDefined() || !prv->getIsFunction()) {
            // printErr(ctx->getStart()->getLine(), "Multiple declaration of " + funcName);
        } else {
            if (prv->getretType() != tNd.type) {
                // printErr(ctx->getStart()->getLine(), "Return type mismatch with function declaration in function " + funcName);
            }
            if (prv->getParamCount() != 0) {
                // printErr(ctx->getStart()->getLine(), "Total number of arguments mismatch with declaration in function " + funcName);
            }
            prv->setIsDefined(true);
        }
    } else {

        SymbolInfo *si = new SymbolInfo(funcName, "ID");
        si->setIsFunction(true);
        si->setIsDefined(true);
        si->setretType(tNd.type);
        st.insert(si);
    }
    // codeOut << "segment readable executable\n";
    codeOut << funcName << ":\n";
    codeOut << "\tPUSH EBP\n";
    codeOut << "\tMOV EBP, ESP\n"; 
    
    nextLocalOffset = 4; 
    currentFuncName = funcName;
    ParseNode cNd = std::any_cast<ParseNode>(visit(ctx->compound_statement()));

    // printLog(ctx->getStart()->getLine(), "func_definition : type_specifier ID LPAREN RPAREN compound_statement", ruleTxt);

    if (funcName == "main") {
        codeOut << "\tMOV ESP, EBP\n";
        codeOut << "\tPOP EBP\n";
        codeOut << "\tMOV EAX, 1\n";    
        codeOut << "\tXOR EBX, EBX\n";  
        codeOut << "\tINT 0x80\n";      
    }
    else {
        codeOut << "\tMOV ESP, EBP\n";
        codeOut << "\tPOP EBP\n";
        codeOut << "\tRET\n";
    }

    return ParseNode{};
}





any TreeVisitor::visitParam_with_id_single(CSubset_2205009Parser::Param_with_id_singleContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string id = ctx->ID()->getText();
    ParseNode res;
    res.paramTypes.push_back(tNd.type);
    res.paramNames.push_back(id);
    // string ruleTxt = tNd.text + " " + id;
    // printLog(ctx->getStart()->getLine(), "parameter_list : type_specifier ID", ruleTxt);
    return res;
}

any TreeVisitor::visitParam_with_id(CSubset_2205009Parser::Param_with_idContext *ctx) {
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string id = ctx->ID()->getText();
    ParseNode res = pNd;
    res.paramTypes.push_back(tNd.type);
    res.paramNames.push_back(id);
    // string ruleTxt = pNd.text + "," + tNd.text + " " + id;
    // printLog(ctx->getStart()->getLine(), "parameter_list : parameter_list COMMA type_specifier ID", ruleTxt);
    return res;
}


any TreeVisitor::visitParam_without_id_single(CSubset_2205009Parser::Param_without_id_singleContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    ParseNode res;
    res.paramTypes.push_back(tNd.type);
    res.paramNames.push_back("");
    // printLog(ctx->getStart()->getLine(), "parameter_list : type_specifier", tNd.text);
    return res;
}

any TreeVisitor::visitParam_without_id(CSubset_2205009Parser::Param_without_idContext *ctx) {
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    ParseNode res = pNd;
    res.paramTypes.push_back(tNd.type);
    res.paramNames.push_back("");
    // string ruleTxt = pNd.text + "," + tNd.text;
    // printLog(ctx->getStart()->getLine(), "parameter_list : parameter_list COMMA type_specifier", ruleTxt);
    return res;
}



any TreeVisitor::visitCompstat_with_statements(CSubset_2205009Parser::Compstat_with_statementsContext *ctx) {
    if(!skpNxt) st.enterScope();
    else skpNxt = false;
    

    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->statements()));
    // printLog(ctx->getStart()->getLine(), "compound_statement : LCURL statements RCURL", ruleTxt);
    st.exitScope();

    return ParseNode{};
}

any TreeVisitor::visitCompstat_empty(CSubset_2205009Parser::Compstat_emptyContext *ctx) {
    if(!skpNxt) st.enterScope();
    else skpNxt = false;

    // printLog(ctx->getStart()->getLine(), "compound_statement : LCURL RCURL", ruleTxt);
    st.exitScope();

    return ParseNode{};
}



any TreeVisitor::visitStat_single(CSubset_2205009Parser::Stat_singleContext *ctx) {
    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->statement()));
    // printLog(ctx->getStart()->getLine(), "statements : statement", sNd.text);
    return ParseNode{};
}


any TreeVisitor::visitStat_multiple(CSubset_2205009Parser::Stat_multipleContext *ctx) {
    ParseNode ssNd = std::any_cast<ParseNode>(visit(ctx->statements()));
    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->statement()));
    // printLog(ctx->statement()->getStart()->getLine(), "statements : statements statement", ruleTxt);
    return ParseNode{};
}



any TreeVisitor::visitStat_var_dec(CSubset_2205009Parser::Stat_var_decContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->var_declaration()));
    // printLog(ctx->getStart()->getLine(), "statement : var_declaration", nd.text);
    return ParseNode{};
}

any TreeVisitor::visitStat_expr(CSubset_2205009Parser::Stat_exprContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->expression_statement()));
    // printLog(ctx->getStart()->getLine(), "statement : expression_statement", nd.text);
    return ParseNode{};
}

any TreeVisitor::visitStat_compound(CSubset_2205009Parser::Stat_compoundContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->compound_statement()));
    // printLog(ctx->getStart()->getLine(), "statement : compound_statement", nd.text);
    return ParseNode{};
}

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

    // string ruleTxt = "for(" + ex1.text + ex2.text + ex3.text + ")" + s.text;
    // printLog(ctx->getStart()->getLine(), "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement", ruleTxt);
    // logOut << "\n";
    return ParseNode{};
}

any TreeVisitor::visitStat_if(CSubset_2205009Parser::Stat_ifContext *ctx) {
    ParseNode ex = std::any_cast<ParseNode>(visit(ctx->expression()));
    string lb_exit = "L" + to_string(segment_no++);

    codeOut << "\tCMP EAX, 0\n";
    codeOut << "\tJE " << lb_exit << "\n";

    ParseNode st = std::any_cast<ParseNode>(visit(ctx->statement()));
    codeOut << lb_exit << ":\n";

    // string ruleTxt = "if (" + ex.text + ")" + st.text;
    // printLog(ctx->getStart()->getLine(), "statement : IF LPAREN expression RPAREN statement", ruleTxt);
    // logOut << "\n";
    return ParseNode{};
}

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

    // string ruleTxt = "if (" + e.text + ")" + st1.text + "\nelse\n" + st2.text;
    // printLog(ctx->getStart()->getLine(), "statement : IF LPAREN expression RPAREN statement ELSE statement", ruleTxt);
    // logOut << "\n";
    return ParseNode{};
}

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

    // string ruleTxt = "while (" + ex.text + ")" + st.text;
    // printLog(ctx->getStart()->getLine(), "statement : WHILE LPAREN expression RPAREN statement", ruleTxt);
    // logOut << "\n";
    return ParseNode{};
}

any TreeVisitor::visitStat_println(CSubset_2205009Parser::Stat_printlnContext *ctx) {
    string id = ctx->ID()->getText();
    SymbolInfo *p = st.lookup(id);
    if (p == NULL) {
        // printErr(ctx->getStart()->getLine(), "Undeclared variable " + id);
    }
    // printLog(ctx->getStart()->getLine(), "statement : PRINTLN LPAREN ID RPAREN SEMICOLON", ruleTxt);
    if(p->getIsGlobal()) codeOut << "\tMOV EAX, [" << p->getName() <<  "]" << endl;
    else if(p->getOffset() < 0) codeOut << "\tMOV EAX, [EBP + " << (-p->getOffset()) << "]" << endl;
    else codeOut << "\tMOV EAX, [EBP - " << p->getOffset() << "]" << endl;
    codeOut << "\tCALL print_number\n";
    return ParseNode{};
}

any TreeVisitor::visitStat_return(CSubset_2205009Parser::Stat_returnContext *ctx) {
    ParseNode ex = std::any_cast<ParseNode>(visit(ctx->expression()));
    // printLog(ctx->getStart()->getLine(), "statement : RETURN expression SEMICOLON", ruleTxt);
    codeOut << "\tMOV ESP, EBP\n";
    codeOut << "\tPOP EBP\n";
    if (currentFuncName == "main") {
        codeOut << "\tMOV EBX, EAX\n";
        codeOut << "\tMOV EAX, 1\n";
        codeOut << "\tINT 0x80\n";
    }
    else {
        codeOut << "\tRET\n";
    }
    return ParseNode{};
}



any TreeVisitor::visitExpr_end(CSubset_2205009Parser::Expr_endContext *ctx) {
    // printLog(ctx->getStart()->getLine(), "expression_statement : SEMICOLON", ";");
    return ParseNode{};
}

any TreeVisitor::visitExpr_with_expr(CSubset_2205009Parser::Expr_with_exprContext *ctx) {
    ParseNode ex = std::any_cast<ParseNode>(visit(ctx->expression()));
    // printLog(ctx->getStart()->getLine(), "expression_statement : expression SEMICOLON", ruleTxt);
    return ParseNode{};
}



any TreeVisitor::visitVar_id(CSubset_2205009Parser::Var_idContext *ctx) {
    string id = ctx->ID()->getText();
    SymbolInfo *sym = st.lookup(id);
    if (sym == NULL) {
        // printErr(ctx->getStart()->getLine(), "Undeclared variable " + id);
        // printLog(ctx->getStart()->getLine(), "variable : ID", id);
        return ParseNode{};
    }
    if (sym->getisArr()) {
        // printErr(ctx->getStart()->getLine(), "Type mismatch, " + id + " is an array");
    }

    // printLog(ctx->getStart()->getLine(), "variable : ID", id);
    ParseNode p;
    p.isGlobal = sym->getIsGlobal();
    p.text = sym->getName();
    p.offset = sym->getOffset();
    p.type = sym->getVarType();
    if(p.isGlobal){
        codeOut << "\tMOV EAX, [" << p.text << "]" << endl;
    }
    else if(p.offset < 0){
        codeOut << "\tMOV EAX, [EBP + " << (-p.offset) << "]" << endl;
    }
    else{
        codeOut << "\tMOV EAX, [EBP - " << p.offset << "]" << endl;
    }
    return p;
    
}

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

    // string ruleTxt = id + "[" + eNd.text + "]";
    // printLog(ctx->getStart()->getLine(), "variable : ID LTHIRD expression RTHIRD", ruleTxt);

    ParseNode p;
    p.isArray = true;
    p.text = id;
    p.type = sym->getVarType();
    return p;
}


any TreeVisitor::visitExpr_logic(CSubset_2205009Parser::Expr_logicContext *ctx) {
    ParseNode lNd = std::any_cast<ParseNode>(visit(ctx->logic_expression()));
    // printLog(ctx->getStart()->getLine(), "expression : logic expression", lNd.text);
    return ParseNode{};
}

any TreeVisitor::visitExpr_assign(CSubset_2205009Parser::Expr_assignContext *ctx) {
    ParseNode vNd = std::any_cast<ParseNode>(visit(ctx->variable()));
    ParseNode lNd = std::any_cast<ParseNode>(visit(ctx->logic_expression()));

    if (vNd.type != "ERROR" && lNd.type != "ERROR") {
        if (vNd.isArray) {
            codeOut << "\tPOP EBX\n";
            codeOut << "\tMOV [EBX], EAX\n";
        }
        else if(vNd.isGlobal){
            codeOut << "\tMOV [" << vNd.text << "], EAX\n";
            codeOut << "\tMOV EAX, [" << vNd.text << "]\n";
        }
        else if(vNd.offset < 0){
            codeOut << "\tMOV [EBP + " << (-vNd.offset) << "], EAX\n";
            codeOut << "\tMOV EAX, [EBP + " << (-vNd.offset) << "]\n";
        }
        else{
            codeOut << "\tMOV [EBP - " << vNd.offset << "], EAX\n";
            codeOut << "\tMOV EAX, [EBP - " << vNd.offset << "]\n";
        }
    }

    // printLog(ctx->getStart()->getLine(), "expression : variable ASSIGNOP logic_expression", ruleTxt);
    return ParseNode{};
}


any TreeVisitor::visitLogic_rel(CSubset_2205009Parser::Logic_relContext *ctx) {
    ParseNode rNd = std::any_cast<ParseNode>(visit(ctx->rel_expression()));
    // printLog(ctx->getStart()->getLine(), "logic_expression : rel_expression", rNd.text);
    return ParseNode{};
}

any TreeVisitor::visitLogic_op(CSubset_2205009Parser::Logic_opContext *ctx) {
    ParseNode r1 = std::any_cast<ParseNode>(visit(ctx->rel_expression(0)));
    codeOut << "\tPUSH EAX\n";
    ParseNode r2 = std::any_cast<ParseNode>(visit(ctx->rel_expression(1)));
    codeOut << "\tPOP EBX\n";
    string op = ctx->LOGICOP()->getText();

    string lb_true = "L" + to_string(segment_no++);
    string lb_false = "L" + to_string(segment_no++);
    string lb_exit = "L" + to_string(segment_no++);

    codeOut << "\tXCHG EAX, EBX\n";

    if (op == "&&") {
        codeOut << "\tCMP EAX, 0\n";
        codeOut << "\tJE " << lb_false << "\n";
        codeOut << "\tCMP EBX, 0\n";
        codeOut << "\tJE " << lb_false << "\n";
        codeOut << "\tJMP " << lb_true << "\n";
    } else {
        codeOut << "\tCMP EAX, 0\n";
        codeOut << "\tJNE " << lb_true << "\n";
        codeOut << "\tCMP EBX, 0\n";
        codeOut << "\tJNE " << lb_true << "\n";
        codeOut << "\tJMP " << lb_false << "\n";
    }

    codeOut << lb_false << ":\n";
    codeOut << "\tMOV EAX, 0\n";
    codeOut << "\tJMP " << lb_exit << "\n";
    codeOut << lb_true << ":\n";
    codeOut << "\tMOV EAX, 1\n";
    codeOut << lb_exit << ":\n";

    return ParseNode{};
}

any TreeVisitor::visitRel_simple(CSubset_2205009Parser::Rel_simpleContext *ctx) {
    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->simple_expression()));
    // printLog(ctx->getStart()->getLine(), "rel_expression : simple_expression", sNd.text);
    return ParseNode{};
}


any TreeVisitor::visitRel_op(CSubset_2205009Parser::Rel_opContext *ctx) {
    ParseNode st1 = std::any_cast<ParseNode>(visit(ctx->simple_expression(0)));
    codeOut << "\tPUSH EAX\n";
    ParseNode st2 = std::any_cast<ParseNode>(visit(ctx->simple_expression(1)));
    string op = ctx->RELOP()->getText();
    codeOut << "\tPOP EBX\n";
    
    string lb_true = "L" + to_string(segment_no++);
    string lb_false = "L" + to_string(segment_no++);

    codeOut << "\tXCHG EAX, EBX\n";
    
    codeOut << "\tCMP EAX, EBX\n";
    if(op == "<="){
        codeOut << "\tJLE " << lb_true << "\n";
        
    }
    else if(op == "<"){
        
        codeOut << "\tJL " << lb_true << "\n";
        
    }
    else if(op == ">="){
        
        codeOut << "\tJGE " << lb_true << "\n";
        
    }
    else if(op == ">"){
        
        codeOut << "\tJG " << lb_true << "\n";
        
    }
    else if(op == "=="){
        
        codeOut << "\tJE " << lb_true << "\n";
        
    }
    else if(op == "!="){
        
        codeOut << "\tJNE " << lb_true << "\n";
        
    }
    codeOut << "\tMOV EAX, 0\n";
    codeOut << "\tJMP " << lb_false << "\n";
    codeOut << lb_true << ":\n";
    codeOut << "\tMOV EAX, 1\n";
    codeOut << lb_false << ":\n";
    
    // printLog(ctx->getStart()->getLine(), "rel_expression : simple_expression RELOP simple_expression", ruleTxt);
    return ParseNode{};
}

any TreeVisitor::visitSimp_term(CSubset_2205009Parser::Simp_termContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->term()));
    // printLog(ctx->getStart()->getLine(), "simple_expression : term", tNd.text);
    return ParseNode{};
}

any TreeVisitor::visitSimp_addop(CSubset_2205009Parser::Simp_addopContext *ctx) {
    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->simple_expression()));

    codeOut << "\tPUSH EAX\n";

    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->term()));
    
    codeOut << "\tPOP EBX\n";
    
    string op = ctx->ADDOP()->getText();
    // printLog(ctx->getStart()->getLine(), "simple_expression : simple_expression ADDOP term", ruleTxt);
    if(op == "+"){
        codeOut << "\tADD EAX, EBX\n";
    }
    else{
        codeOut << "\tXCHG EAX, EBX\n";
        codeOut << "\tSUB EAX, EBX\n";
    }
    return ParseNode{};
}

any TreeVisitor::visitTerm_unary(CSubset_2205009Parser::Term_unaryContext *ctx) {
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unary_expression()));
    // printLog(ctx->getStart()->getLine(), "term : unary_expression", uNd.text);
    return ParseNode{};
}

any TreeVisitor::visitTerm_mulop(CSubset_2205009Parser::Term_mulopContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->term()));
    codeOut << "\tPUSH EAX\n";
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unary_expression()));
    string op = ctx->MULOP()->getText();

    codeOut << "\tPOP EBX\n";

    if(op == "*"){
        codeOut << "\tXCHG EAX, EBX\n";
        codeOut << "\tIMUL EBX\n";
    }
    else if(op == "%"){
        codeOut << "\tXCHG EAX, EBX\n";
        codeOut << "\tCDQ\n";
        codeOut << "\tIDIV EBX\n";
        codeOut << "\tMOV EAX, EDX\n";
    }
    else{
        codeOut << "\tXCHG EAX, EBX\n";
        codeOut << "\tCDQ\n";
        codeOut << "\tIDIV EBX\n";
    }
    // printLog(ctx->getStart()->getLine(), "term : term MULOP unary_expression", ruleTxt);
    return ParseNode{};
}

any TreeVisitor::visitUnary_addop(CSubset_2205009Parser::Unary_addopContext *ctx) {
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unary_expression()));
    string op = ctx->ADDOP()->getText();
    if(op == "-"){
        codeOut << "\tNEG EAX\n";
    }
    return ParseNode{};
}

any TreeVisitor::visitUnary_not(CSubset_2205009Parser::Unary_notContext *ctx) {
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unary_expression()));
    
    string op = ctx->NOT()->getText();
    // printLog(ctx->getStart()->getLine(), "unary_expression : NOT unary expression", ruleTxt);
    string lb_true = "L" + to_string(segment_no++);
    string lb_false = "L" + to_string(segment_no++);
    string lb_exit = "L" + to_string(segment_no++);

    codeOut << "\tCMP EAX, 0\n";
    codeOut << "\tJE " << lb_true << "\n";

    codeOut << lb_false << ":\n";
    codeOut << "\tMOV EAX, 0\n";
    codeOut << "\tJMP " << lb_exit << "\n";
    
    codeOut << lb_true << ":\n";
    codeOut << "\tMOV EAX, 1\n";
    
    codeOut << lb_exit << ":\n";
    
    return ParseNode{};
}

any TreeVisitor::visitUnary_factor(CSubset_2205009Parser::Unary_factorContext *ctx) {
    ParseNode fNd = std::any_cast<ParseNode>(visit(ctx->factor()));
    // printLog(ctx->getStart()->getLine(), "unary_expression : factor", fNd.text);
    return ParseNode{};
}

any TreeVisitor::visitFactor_var(CSubset_2205009Parser::Factor_varContext *ctx) {
    ParseNode vNd = std::any_cast<ParseNode>(visit(ctx->variable()));
    if (vNd.isArray) {
        codeOut << "\tADD ESP, 4\n";
    }
    // printLog(ctx->getStart()->getLine(), "factor : variable", vNd.text);
    return ParseNode{};
}

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

    // string ruleTxt = funcName + "(" + aNd.text + ")";
    // printLog(ctx->getStart()->getLine(), "factor : ID LPAREN argument_list RPAREN", ruleTxt);
    return ParseNode{};
}




any TreeVisitor::visitFactor_paren(CSubset_2205009Parser::Factor_parenContext *ctx) {
    ParseNode eNd = std::any_cast<ParseNode>(visit(ctx->expression()));
    // printLog(ctx->getStart()->getLine(), "factor : LPAREN expression RPAREN", ruleTxt);
    return ParseNode{};
}

any TreeVisitor::visitFactor_int(CSubset_2205009Parser::Factor_intContext *ctx) {
    string val = ctx->CONST_INT()->getText();
    // printLog(ctx->getStart()->getLine(), "factor : CONST_INT", val);
    codeOut << "\tMOV EAX, " << val << "\n";
    return ParseNode{};
}

any TreeVisitor::visitFactor_float(CSubset_2205009Parser::Factor_floatContext *ctx) {
    string val = ctx->CONST_FLOAT()->getText();
    // printLog(ctx->getStart()->getLine(), "factor : CONST_FLOAT", val);
    codeOut << "\tMOV EAX, " << val << "\n";
    return ParseNode{};
}


any TreeVisitor::visitFactor_inc(CSubset_2205009Parser::Factor_incContext *ctx) {
    ParseNode vNd = std::any_cast<ParseNode>(visit(ctx->variable()));
    // printLog(ctx->getStart()->getLine(), "factor : variable INCOP", ruleTxt);
    if (vNd.isArray) {
        codeOut << "\tPOP EBX\n";
        codeOut << "\tINC dword [EBX]\n";
    } else if (vNd.isGlobal) {
        codeOut << "\tINC dword [" << vNd.text << "]\n";
    } else {
        codeOut << "\tINC dword [EBP - " << vNd.offset << "]\n";
    }
    return ParseNode{};
}

any TreeVisitor::visitFactor_dec(CSubset_2205009Parser::Factor_decContext *ctx) {
    ParseNode vNd = std::any_cast<ParseNode>(visit(ctx->variable()));
    // printLog(ctx->getStart()->getLine(), "factor : variable DECOP", ruleTxt);
    if (vNd.isArray) {
        codeOut << "\tPOP EBX\n";
        codeOut << "\tDEC dword [EBX]\n";
    } else if (vNd.isGlobal) {
        codeOut << "\tDEC dword [" << vNd.text << "]\n";
    } else {
        codeOut << "\tDEC dword [EBP - " << vNd.offset << "]\n";
    }
    return ParseNode{};
}

any TreeVisitor::visitArg_list(CSubset_2205009Parser::Arg_listContext *ctx) {
    if (ctx->arguments()) {
        return visit(ctx->arguments());
    }
    // printLog(ctx->getStart()->getLine(), "argument_list : arguments", aNd.text);
    return ParseNode{};
}

any TreeVisitor::visitArg_list_empty(CSubset_2205009Parser::Arg_list_emptyContext *ctx) {
    // printLog(ctx->getStart()->getLine(), "argument_list : ", "");
    ParseNode res;
    res.intVal = 0;
    return res;
}

any TreeVisitor::visitArgs_single(CSubset_2205009Parser::Args_singleContext *ctx) {
    visit(ctx->logic_expression());
    codeOut << "\tPUSH EAX\n";
    ParseNode res;
    res.intVal = 1;
    // printLog(ctx->getStart()->getLine(), "arguments : logic_expression", lNd.text);
    return res;
}

any TreeVisitor::visitArgs_multi(CSubset_2205009Parser::Args_multiContext *ctx) {
    // Right-to-left evaluation for cdecl calling convention
    visit(ctx->logic_expression());
    codeOut << "\tPUSH EAX\n";

    ParseNode aNd = std::any_cast<ParseNode>(visit(ctx->arguments()));
    ParseNode res;
    res.intVal = aNd.intVal + 1;
    // string ruleTxt = aNd.text + "," + lNd.text;
    // printLog(ctx->getStart()->getLine(), "arguments : arguments COMMA logic_expression", ruleTxt);
    return res;
}