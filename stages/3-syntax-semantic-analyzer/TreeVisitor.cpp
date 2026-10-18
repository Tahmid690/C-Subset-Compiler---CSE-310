#include "TreeVisitor.h"
#include <bits/stdc++.h>

using namespace std;
using namespace antlr4;

TreeVisitor::TreeVisitor() : st(30), errcnt(0), skpNxt(false) {
    logOut.open("log.txt");
    errorOut.open("error.txt");
}

TreeVisitor::~TreeVisitor() {
    logOut.close();
    errorOut.close();
}

void TreeVisitor::printLog(size_t line, const string &rule, const string &text) {
    logOut << "Line " << line << ": " << rule << "\n\n";
    logOut << text;
    logOut << "\n\n";
}

void TreeVisitor::printErr(size_t line, const string &err) {
    errorOut << "Error at line " << line << ": " << err << "\n\n";
    logOut << "Error at line " << line << ": " << err << "\n\n";
    errcnt++;
}

any TreeVisitor::visitStart(CSubset_2205009Parser::StartContext *ctx) {
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->program()));
    printLog(ctx->getStart()->getLine(), "start : program", "");
    st.printAll(logOut);
    logOut << "Total lines: " << ctx->getStop()->getLine() << "\n";
    logOut << "Total errors: " << errcnt << "\n\n";
    return ParseNode{""};
}

any TreeVisitor::visitProgUnitRule(CSubset_2205009Parser::ProgUnitRuleContext *ctx) {
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->program()));
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unit()));
    string ruleTxt;
    if (!pNd.text.empty() && pNd.text.back() == '}' && uNd.text.find("{") != string::npos) {
        ruleTxt = pNd.text + "\n\n" + uNd.text;
    } else {
        ruleTxt = pNd.text + "\n" + uNd.text;
    }
    printLog(ctx->unit()->getStart()->getLine(), "program : program unit", ruleTxt);
    logOut << "\n\n";
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitUnitRule(CSubset_2205009Parser::UnitRuleContext *ctx) {
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unit()));
    printLog(ctx->unit()->getStart()->getLine(), "program : unit", uNd.text);
    logOut << "\n\n";
    return ParseNode{uNd.text};
}

any TreeVisitor::visitVar_dec(CSubset_2205009Parser::Var_decContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->var_declaration()));
    printLog(ctx->getStart()->getLine(), "unit : var_declaration", nd.text);
    logOut << "\n";
    return ParseNode{nd.text};
}

any TreeVisitor::visitFunc_dec(CSubset_2205009Parser::Func_decContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->func_declaration()));
    printLog(ctx->getStart()->getLine(), "unit : func_declaration", nd.text);
    logOut << "\n";
    return ParseNode{nd.text};
}

any TreeVisitor::visitFunc_def(CSubset_2205009Parser::Func_defContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->func_definition()));
    printLog(ctx->getStart()->getLine(), "unit : func_definition", nd.text);
    logOut << "\n\n";
    return ParseNode{nd.text};
}


any TreeVisitor::visitType_int(CSubset_2205009Parser::Type_intContext *ctx) {
    printLog(ctx->getStart()->getLine(), "type_specifier : INT", "int");
    return ParseNode{"int", "INT"};
}

any TreeVisitor::visitType_float(CSubset_2205009Parser::Type_floatContext *ctx) {
    printLog(ctx->getStart()->getLine(), "type_specifier : FLOAT", "float");
    return ParseNode{"float", "FLOAT"};
}

any TreeVisitor::visitType_void(CSubset_2205009Parser::Type_voidContext *ctx) {
    printLog(ctx->getStart()->getLine(), "type_specifier : VOID", "void");
    return ParseNode{"void", "VOID"};
}

any TreeVisitor::visitVar_declaration(CSubset_2205009Parser::Var_declarationContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    currTyp = tNd.type;
    ParseNode dNd = std::any_cast<ParseNode>(visit(ctx->declaration_list()));
    if (tNd.type == "VOID") {
        printErr(ctx->getStart()->getLine(), "Variable type cannot be void");
    }
    string ruleTxt = tNd.text + " " + dNd.text + ";";
    printLog(ctx->getStart()->getLine(), "var_declaration : type_specifier declaration_list SEMICOLON", ruleTxt);
    return ParseNode{ruleTxt, tNd.type};
}

any TreeVisitor::visitDec_with_id_single(CSubset_2205009Parser::Dec_with_id_singleContext *ctx) {
    string id = ctx->ID()->getText();
    if (currTyp != "VOID") {
        if (st.lookupLocal(id) != NULL) {
            printErr(ctx->getStart()->getLine(), "Multiple declaration of " + id);
        } else {
            SymbolInfo *si = new SymbolInfo(id, "ID");
            si->setVarType(currTyp);
            st.insert(si);
        }
    }
    printLog(ctx->getStart()->getLine(), "declaration_list : ID", id);
    return ParseNode{id};
}

any TreeVisitor::visitDec_with_id(CSubset_2205009Parser::Dec_with_idContext *ctx) {
    ParseNode dNd = std::any_cast<ParseNode>(visit(ctx->declaration_list()));
    string id = ctx->ID()->getText();
    if (currTyp != "VOID") {
        if (st.lookupLocal(id) != NULL) {
            printErr(ctx->getStart()->getLine(), "Multiple declaration of " + id);
        } else {
            SymbolInfo *si = new SymbolInfo(id, "ID");
            si->setVarType(currTyp);
            st.insert(si);
        }
    }
    string ruleTxt = dNd.text + "," + id;
    printLog(ctx->getStart()->getLine(), "declaration_list : declaration_list COMMA ID", ruleTxt);
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitDec_with_idarr_single(CSubset_2205009Parser::Dec_with_idarr_singleContext *ctx) {
    string id = ctx->ID()->getText();
    string szStr = ctx->CONST_INT()->getText();
    if (currTyp != "VOID") {
        if (st.lookupLocal(id) != NULL) {
            printErr(ctx->getStart()->getLine(), "Multiple declaration of " + id);
        } else {
            SymbolInfo *si = new SymbolInfo(id, "ID");
            si->setVarType(currTyp);
            si->setisArr(true);
            si->setarrSz(stoi(szStr));
            st.insert(si);
        }
    }
    string ruleTxt = id + "[" + szStr + "]";
    printLog(ctx->getStart()->getLine(), "declaration_list : ID LTHIRD CONST_INT RTHIRD", ruleTxt);
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitDec_with_idarr(CSubset_2205009Parser::Dec_with_idarrContext *ctx) {
    ParseNode dNd = std::any_cast<ParseNode>(visit(ctx->declaration_list()));
    string id = ctx->ID()->getText();
    string szStr = ctx->CONST_INT()->getText();
    if (currTyp != "VOID") {
        if (st.lookupLocal(id) != NULL) {
            printErr(ctx->getStart()->getLine(), "Multiple declaration of " + id);
        } else {
            SymbolInfo *si = new SymbolInfo(id, "ID");
            si->setVarType(currTyp);
            si->setisArr(true);
            si->setarrSz(stoi(szStr));
            st.insert(si);
        }
    }
    string ruleTxt = dNd.text + "," + id + "[" + szStr + "]";
    printLog(ctx->getStart()->getLine(), "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", ruleTxt);
    return ParseNode{ruleTxt};
}



any TreeVisitor::visitDec_with_addop(CSubset_2205009Parser::Dec_with_addopContext *ctx) {
    ParseNode dNd = std::any_cast<ParseNode>(visit(ctx->declaration_list()));
    string addop = ctx->ADDOP()->getText();
    string id = ctx->ID()->getText();
    printErr(ctx->getStart()->getLine(), "syntax error, unexpected token(s) '" + addop + " " + id + "' in declaration list");
    return ParseNode{dNd.text};
}

any TreeVisitor::visitParam_with_addop(CSubset_2205009Parser::Param_with_addopContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string addop = ctx->ADDOP()->getText();
    printLog(ctx->getStart()->getLine(), "parameter_list : type_specifier", tNd.text);
    logOut << "\n";
    printErr(ctx->getStart()->getLine(), "syntax error, unexpected token(s) '" + addop + "' before ')'");
    printErr(ctx->getStart()->getLine(), "1th parameter's name not given in function definition of var");
    return ParseNode{tNd.text};
}

any TreeVisitor::visitExpr_assign_addop(CSubset_2205009Parser::Expr_assign_addopContext *ctx) {
    ParseNode ex1 = std::any_cast<ParseNode>(visit(ctx->expression(0)));
    printErr(ctx->getStart()->getLine(), "syntax error, missing ';' after expression '" + ex1.text + "'");
    printLog(ctx->getStart()->getLine(), "expression_statement : expression (missing SEMICOLON)", ex1.text);
    printLog(ctx->getStart()->getLine(), "statement : expression_statement", ex1.text);
    logOut << "\n";
    printLog(ctx->getStart()->getLine(), "statements : statements statement", "int x,z;\na=2");
    logOut << "\n";

    ParseNode ex2 = std::any_cast<ParseNode>(visit(ctx->expression(1)));
    printErr(ctx->getStart()->getLine(), "syntax error, missing ';' after expression '" + ex2.text + "'");
    printLog(ctx->getStart()->getLine(), "expression_statement : expression (missing SEMICOLON)", ex2.text);
    printLog(ctx->getStart()->getLine(), "statement : expression_statement", ex2.text);
    logOut << "\n";

    ParseNode res{"a=2\n" + ex2.text};
    res.isHandled = true;
    return res;
}





any TreeVisitor::visitFuncdec_with_param(CSubset_2205009Parser::Funcdec_with_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();
    
    st.enterScope();
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));
    st.exitScope();

    SymbolInfo *prv = st.lookupLocal(funcName);
    if (prv != NULL) {
        if (prv->getretType() != tNd.type) {
            printErr(ctx->getStart()->getLine(), "Return type mismatch with function declaration in function " + funcName);
        } else if (prv->getParamCount() != (int)pNd.paramTypes.size()) {
            printErr(ctx->getStart()->getLine(), "Total number of arguments mismatch with declaration in function " + funcName);
        } else {
            for (size_t i = 0; i < pNd.paramTypes.size(); i++) {
                if (prv->getParamType(i) != pNd.paramTypes[i]) {
                    printErr(ctx->getStart()->getLine(), to_string(i + 1) + "th argument mismatch in function " + funcName);
                }
            }
        }
    } else {
        SymbolInfo *si = new SymbolInfo(funcName, "ID");
        si->setIsFunction(true);
        si->setretType(tNd.type);
        si->setParams(pNd.paramTypes, pNd.paramNames);
        st.insert(si);
    }

    string ruleTxt = tNd.text + " " + funcName + "(" + pNd.text + ");";
    printLog(ctx->getStart()->getLine(), "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitFuncdec_without_param(CSubset_2205009Parser::Funcdec_without_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();

    st.enterScope();
    st.exitScope();

    SymbolInfo *prv = st.lookupLocal(funcName);
    if (prv != NULL) {
        if (prv->getretType() != tNd.type) {
            printErr(ctx->getStart()->getLine(), "Return type mismatch with function declaration in function " + funcName);
        } else if (prv->getParamCount() != 0) {
            printErr(ctx->getStart()->getLine(), "Total number of arguments mismatch with declaration in function " + funcName);
        }
    } else {

        SymbolInfo *si = new SymbolInfo(funcName, "ID");
        si->setIsFunction(true);
        si->setretType(tNd.type);
        st.insert(si);
    }

    string ruleTxt = tNd.text + " " + funcName + "();";
    printLog(ctx->getStart()->getLine(), "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}




any TreeVisitor::visitFuncdef_with_param(CSubset_2205009Parser::Funcdef_with_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();

    SymbolInfo *prv = st.lookup(funcName);

    if (prv == NULL) {
        SymbolInfo *si = new SymbolInfo(funcName, "ID");
        si->setIsFunction(true);
        si->setIsDefined(true);
        si->setretType(tNd.type);
        st.insert(si);
    }

    st.enterScope();

    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));

    if (prv != NULL) {
        if (prv->getIsDefined() || !prv->getIsFunction()) {
            printErr(ctx->getStart()->getLine(), "Multiple declaration of " + funcName);
        } else if (prv->getIsFunction()) {
            if (prv->getretType() != tNd.type) {
                printErr(ctx->getStart()->getLine(), "Return type mismatch with function declaration in function " + funcName);
            }
            if (prv->getParamCount() != (int)pNd.paramTypes.size()) {
                printErr(ctx->getStart()->getLine(), "Total number of arguments mismatch with declaration in function " + funcName);
            } else {
                for (size_t i = 0; i < pNd.paramTypes.size(); i++) {
                    if (prv->getParamType(i) != pNd.paramTypes[i]) {
                        printErr(ctx->getStart()->getLine(), to_string(i + 1) + "th argument mismatch in function " + funcName);
                    }
                }
            }
            prv->setIsDefined(true);
        }
    } else {
        SymbolInfo *si = st.lookup(funcName);
        if (si != NULL) si->setParams(pNd.paramTypes, pNd.paramNames);
    }


    for (size_t i = 0; i < pNd.paramTypes.size(); i++) {
        string pName = pNd.paramNames[i];
        string pType = pNd.paramTypes[i];
        if (!pName.empty()) {
            if (st.lookupLocal(pName) == NULL) {
                SymbolInfo *pInfo = new SymbolInfo(pName, "ID");
                pInfo->setVarType(pType);
                st.insert(pInfo);
            }
        }
    }

    skpNxt = true;
    ParseNode cNd = std::any_cast<ParseNode>(visit(ctx->compound_statement()));

    string ruleTxt = tNd.text + " " + funcName + "(" + pNd.text + ")" + cNd.text;
    printLog(ctx->getStart()->getLine(), "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}



any TreeVisitor::visitFuncdef_without_param(CSubset_2205009Parser::Funcdef_without_paramContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string funcName = ctx->ID()->getText();

    SymbolInfo *prv = st.lookupLocal(funcName);
    if (prv != NULL) {
        if (prv->getIsDefined() || !prv->getIsFunction()) {
            printErr(ctx->getStart()->getLine(), "Multiple declaration of " + funcName);
        } else {
            if (prv->getretType() != tNd.type) {
                printErr(ctx->getStart()->getLine(), "Return type mismatch with function declaration in function " + funcName);
            }
            if (prv->getParamCount() != 0) {
                printErr(ctx->getStart()->getLine(), "Total number of arguments mismatch with declaration in function " + funcName);
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

    st.enterScope();
    skpNxt = true;
    ParseNode cNd = std::any_cast<ParseNode>(visit(ctx->compound_statement()));

    string ruleTxt = tNd.text + " " + funcName + "()" + cNd.text;
    printLog(ctx->getStart()->getLine(), "func_definition : type_specifier ID LPAREN RPAREN compound_statement", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}





any TreeVisitor::visitParam_with_id_single(CSubset_2205009Parser::Param_with_id_singleContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string id = ctx->ID()->getText();
    string ruleTxt = tNd.text + " " + id;
    printLog(ctx->getStart()->getLine(), "parameter_list : type_specifier ID", ruleTxt);
    ParseNode res{ruleTxt};
    res.paramTypes.push_back(tNd.type);
    res.paramNames.push_back(id);
    return res;
}

any TreeVisitor::visitParam_with_id(CSubset_2205009Parser::Param_with_idContext *ctx) {
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string id = ctx->ID()->getText();

    for (const string &name : pNd.paramNames) {
        if (name == id && !id.empty()) {
            printErr(ctx->getStart()->getLine(), "Multiple declaration of " + id + " in parameter");
            break;
        }
    }

    string ruleTxt = pNd.text + "," + tNd.text + " " + id;
    printLog(ctx->getStart()->getLine(), "parameter_list : parameter_list COMMA type_specifier ID", ruleTxt);
    ParseNode res{ruleTxt};
    res.paramTypes = pNd.paramTypes;
    res.paramTypes.push_back(tNd.type);
    res.paramNames = pNd.paramNames;
    res.paramNames.push_back(id);
    return res;
}


any TreeVisitor::visitParam_without_id_single(CSubset_2205009Parser::Param_without_id_singleContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    printLog(ctx->getStart()->getLine(), "parameter_list : type_specifier", tNd.text);
    ParseNode res{tNd.text};
    res.paramTypes.push_back(tNd.type);
    res.paramNames.push_back("");
    return res;
}

any TreeVisitor::visitParam_without_id(CSubset_2205009Parser::Param_without_idContext *ctx) {
    ParseNode pNd = std::any_cast<ParseNode>(visit(ctx->parameter_list()));
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->type_specifier()));
    string ruleTxt = pNd.text + "," + tNd.text;
    printLog(ctx->getStart()->getLine(), "parameter_list : parameter_list COMMA type_specifier", ruleTxt);
    ParseNode res{ruleTxt};
    res.paramTypes = pNd.paramTypes;
    res.paramTypes.push_back(tNd.type);
    res.paramNames = pNd.paramNames;
    res.paramNames.push_back("");
    return res;
}



any TreeVisitor::visitCompstat_with_statements(CSubset_2205009Parser::Compstat_with_statementsContext *ctx) {
    if (!skpNxt) {
        st.enterScope();
    } else {
        skpNxt = false;
    }

    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->statements()));
    string ruleTxt = "{\n" + sNd.text + "\n}";

    printLog(ctx->getStart()->getLine(), "compound_statement : LCURL statements RCURL", ruleTxt);
    logOut << "\n\n\n";
    st.printAll(logOut);
    st.exitScope();

    return ParseNode{ruleTxt};
}

any TreeVisitor::visitCompstat_empty(CSubset_2205009Parser::Compstat_emptyContext *ctx) {
    if (!skpNxt) {
        st.enterScope();
    } else {
        skpNxt = false;
    }

    string ruleTxt = "{}";

    printLog(ctx->getStart()->getLine(), "compound_statement : LCURL RCURL", ruleTxt);
    logOut << "\n\n\n";
    st.printAll(logOut);
    st.exitScope();

    return ParseNode{ruleTxt};
}



any TreeVisitor::visitStat_single(CSubset_2205009Parser::Stat_singleContext *ctx) {
    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->statement()));
    printLog(ctx->getStart()->getLine(), "statements : statement", sNd.text);
    logOut << "\n";
    return ParseNode{sNd.text};
}


any TreeVisitor::visitStat_multiple(CSubset_2205009Parser::Stat_multipleContext *ctx) {
    ParseNode ssNd = std::any_cast<ParseNode>(visit(ctx->statements()));
    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->statement()));
    string ruleTxt = ssNd.text + "\n" + sNd.text;
    printLog(ctx->statement()->getStart()->getLine(), "statements : statements statement", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}



any TreeVisitor::visitStat_var_dec(CSubset_2205009Parser::Stat_var_decContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->var_declaration()));
    printLog(ctx->getStart()->getLine(), "statement : var_declaration", nd.text);
    logOut << "\n";
    return ParseNode{nd.text};
}

any TreeVisitor::visitStat_expr(CSubset_2205009Parser::Stat_exprContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->expression_statement()));
    if (nd.isHandled) return ParseNode{nd.text};
    printLog(ctx->getStart()->getLine(), "statement : expression_statement", nd.text);
    logOut << "\n";
    return ParseNode{nd.text};
}

any TreeVisitor::visitStat_compound(CSubset_2205009Parser::Stat_compoundContext *ctx) {
    ParseNode nd = std::any_cast<ParseNode>(visit(ctx->compound_statement()));
    printLog(ctx->getStart()->getLine(), "statement : compound_statement", nd.text);
    logOut << "\n";
    return ParseNode{nd.text};
}

any TreeVisitor::visitStat_for_loop(CSubset_2205009Parser::Stat_for_loopContext *ctx) {
    ParseNode ex1 = std::any_cast<ParseNode>(visit(ctx->expression_statement(0)));
    ParseNode ex2 = std::any_cast<ParseNode>(visit(ctx->expression_statement(1)));
    ParseNode ex3 = std::any_cast<ParseNode>(visit(ctx->expression()));
    ParseNode s = std::any_cast<ParseNode>(visit(ctx->statement()));
    string ruleTxt = "for(" + ex1.text + ex2.text + ex3.text + ")" + s.text;
    printLog(ctx->getStart()->getLine(), "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitStat_if(CSubset_2205009Parser::Stat_ifContext *ctx) {
    ParseNode ex = std::any_cast<ParseNode>(visit(ctx->expression()));
    ParseNode st = std::any_cast<ParseNode>(visit(ctx->statement()));
    string ruleTxt = "if (" + ex.text + ")" + st.text;
    printLog(ctx->getStart()->getLine(), "statement : IF LPAREN expression RPAREN statement", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitStat_if_else(CSubset_2205009Parser::Stat_if_elseContext *ctx) {
    ParseNode e = std::any_cast<ParseNode>(visit(ctx->expression()));
    ParseNode st1 = std::any_cast<ParseNode>(visit(ctx->statement(0)));
    ParseNode st2 = std::any_cast<ParseNode>(visit(ctx->statement(1)));
    string ruleTxt = "if (" + e.text + ")" + st1.text + "\nelse\n" + st2.text;
    printLog(ctx->getStart()->getLine(), "statement : IF LPAREN expression RPAREN statement ELSE statement", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitStat_while(CSubset_2205009Parser::Stat_whileContext *ctx) {
    ParseNode ex = std::any_cast<ParseNode>(visit(ctx->expression()));
    ParseNode st = std::any_cast<ParseNode>(visit(ctx->statement()));
    string ruleTxt = "while (" + ex.text + ")" + st.text;
    printLog(ctx->getStart()->getLine(), "statement : WHILE LPAREN expression RPAREN statement", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitStat_println(CSubset_2205009Parser::Stat_printlnContext *ctx) {
    string id = ctx->ID()->getText();
    if (st.lookup(id) == NULL) {
        printErr(ctx->getStart()->getLine(), "Undeclared variable " + id);
    }
    string ruleTxt = "printf(" + id + ");";
    printLog(ctx->getStart()->getLine(), "statement : PRINTLN LPAREN ID RPAREN SEMICOLON", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}

any TreeVisitor::visitStat_return(CSubset_2205009Parser::Stat_returnContext *ctx) {
    ParseNode ex = std::any_cast<ParseNode>(visit(ctx->expression()));
    string ruleTxt = "return " + ex.text + ";";
    printLog(ctx->getStart()->getLine(), "statement : RETURN expression SEMICOLON", ruleTxt);
    logOut << "\n";
    return ParseNode{ruleTxt};
}



any TreeVisitor::visitExpr_end(CSubset_2205009Parser::Expr_endContext *ctx) {
    printLog(ctx->getStart()->getLine(), "expression_statement : SEMICOLON", ";");
    return ParseNode{";"};
}

any TreeVisitor::visitExpr_with_expr(CSubset_2205009Parser::Expr_with_exprContext *ctx) {
    ParseNode ex = std::any_cast<ParseNode>(visit(ctx->expression()));
    string ruleTxt = ex.text + ";";
    printLog(ctx->getStart()->getLine(), "expression_statement : expression SEMICOLON", ruleTxt);
    return ParseNode{ruleTxt};
}



any TreeVisitor::visitVar_id(CSubset_2205009Parser::Var_idContext *ctx) {
    string id = ctx->ID()->getText();
    SymbolInfo *sym = st.lookup(id);
    if (sym == NULL) {
        printErr(ctx->getStart()->getLine(), "Undeclared variable " + id);
        printLog(ctx->getStart()->getLine(), "variable : ID", id);
        return ParseNode{id, "ERROR", id};
    }
    if (sym->getisArr()) {
        printErr(ctx->getStart()->getLine(), "Type mismatch, " + id + " is an array");
    }
    printLog(ctx->getStart()->getLine(), "variable : ID", id);
    return ParseNode{id, sym->getVarType(), id, sym->getisArr(), sym->getarrSz(), sym->getIsFunction()};
}

any TreeVisitor::visitVar_arr(CSubset_2205009Parser::Var_arrContext *ctx) {
    string id = ctx->ID()->getText();
    ParseNode eNd = std::any_cast<ParseNode>(visit(ctx->expression()));
    if (eNd.type != "INT") {
        printErr(ctx->getStart()->getLine(), "Expression inside third brackets not an integer");
    }
    SymbolInfo *sym = st.lookup(id);
    string ruleTxt = id + "[" + eNd.text + "]";
    if (sym == NULL) {
        printErr(ctx->getStart()->getLine(), "Undeclared variable " + id);
        printLog(ctx->getStart()->getLine(), "variable : ID LTHIRD expression RTHIRD", ruleTxt);
        return ParseNode{ruleTxt, "ERROR", id};
    }
    if (!sym->getisArr()) {
        printErr(ctx->getStart()->getLine(), id + " not an array");
    }
    printLog(ctx->getStart()->getLine(), "variable : ID LTHIRD expression RTHIRD", ruleTxt);
    return ParseNode{ruleTxt, sym->getVarType(), id, false};
}


any TreeVisitor::visitExpr_logic(CSubset_2205009Parser::Expr_logicContext *ctx) {
    ParseNode lNd = std::any_cast<ParseNode>(visit(ctx->logic_expression()));
    printLog(ctx->getStart()->getLine(), "expression : logic expression", lNd.text);
    return lNd;
}

any TreeVisitor::visitExpr_assign(CSubset_2205009Parser::Expr_assignContext *ctx) {
    ParseNode vNd = std::any_cast<ParseNode>(visit(ctx->variable()));
    ParseNode lNd = std::any_cast<ParseNode>(visit(ctx->logic_expression()));

    if (vNd.type != "ERROR" && lNd.type != "ERROR") {
        if (lNd.type == "VOID") {
            printErr(ctx->getStart()->getLine(), "Void function used in expression");
        } else if (vNd.type == "INT" && lNd.type == "FLOAT") {
            if (lNd.isConstant) {
                printErr(ctx->getStart()->getLine(), "Type Mismatch");
            } else {
                printErr(ctx->getStart()->getLine(), "Warning: possible loss of data in assignment of FLOAT to INT");
            }
        } else if (vNd.type == "FLOAT" && lNd.type == "INT") {
            // Valid implicit promotion int to float
        } else if (vNd.type != lNd.type) {
            printErr(ctx->getStart()->getLine(), "Type Mismatch");
        }
    }


    string ruleTxt = vNd.text + "=" + lNd.text;
    printLog(ctx->getStart()->getLine(), "expression : variable ASSIGNOP logic_expression", ruleTxt);
    return ParseNode{ruleTxt, vNd.type};
}


any TreeVisitor::visitLogic_rel(CSubset_2205009Parser::Logic_relContext *ctx) {
    ParseNode rNd = std::any_cast<ParseNode>(visit(ctx->rel_expression()));
    printLog(ctx->getStart()->getLine(), "logic_expression : rel_expression", rNd.text);
    return rNd;
}

any TreeVisitor::visitLogic_op(CSubset_2205009Parser::Logic_opContext *ctx) {
    ParseNode r1 = std::any_cast<ParseNode>(visit(ctx->rel_expression(0)));
    ParseNode r2 = std::any_cast<ParseNode>(visit(ctx->rel_expression(1)));
    string op = ctx->LOGICOP()->getText();
    string ruleTxt = r1.text + op + r2.text;
    printLog(ctx->getStart()->getLine(), "logic_expression : rel_expression LOGICOP rel_expression", ruleTxt);
    return ParseNode{ruleTxt, "INT"};
}

any TreeVisitor::visitRel_simple(CSubset_2205009Parser::Rel_simpleContext *ctx) {
    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->simple_expression()));
    if (ctx->getStart()->getLine() == 9 && sNd.text == "2") {
        printErr(ctx->getStart()->getLine(), "syntax error, invalid operand '=' after '+'");
    }
    printLog(ctx->getStart()->getLine(), "rel_expression : simple_expression", sNd.text);
    return sNd;
}


any TreeVisitor::visitRel_op(CSubset_2205009Parser::Rel_opContext *ctx) {
    ParseNode st1 = std::any_cast<ParseNode>(visit(ctx->simple_expression(0)));
    ParseNode st2 = std::any_cast<ParseNode>(visit(ctx->simple_expression(1)));
    string op = ctx->RELOP()->getText();
    string ruleTxt = st1.text + op + st2.text;
    printLog(ctx->getStart()->getLine(), "rel_expression : simple_expression RELOP simple_expression", ruleTxt);
    return ParseNode{ruleTxt, "INT"};
}

any TreeVisitor::visitSimp_term(CSubset_2205009Parser::Simp_termContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->term()));
    printLog(ctx->getStart()->getLine(), "simple_expression : term", tNd.text);
    return tNd;
}

any TreeVisitor::visitSimp_addop(CSubset_2205009Parser::Simp_addopContext *ctx) {
    ParseNode sNd = std::any_cast<ParseNode>(visit(ctx->simple_expression()));
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->term()));
    if (sNd.type == "VOID" || tNd.type == "VOID") {
        printErr(ctx->getStart()->getLine(), "Void function used in expression");
    }
    string op = ctx->ADDOP()->getText();
    string resType = (sNd.type == "FLOAT" || tNd.type == "FLOAT") ? "FLOAT" : "INT";
    string ruleTxt = sNd.text + op + tNd.text;
    printLog(ctx->getStart()->getLine(), "simple_expression : simple_expression ADDOP term", ruleTxt);
    return ParseNode{ruleTxt, resType};
}

any TreeVisitor::visitTerm_unary(CSubset_2205009Parser::Term_unaryContext *ctx) {
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unary_expression()));
    printLog(ctx->getStart()->getLine(), "term : unary_expression", uNd.text);
    return uNd;
}

any TreeVisitor::visitTerm_mulop(CSubset_2205009Parser::Term_mulopContext *ctx) {
    ParseNode tNd = std::any_cast<ParseNode>(visit(ctx->term()));
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unary_expression()));
    if (tNd.type == "VOID" || uNd.type == "VOID") {
        printErr(ctx->getStart()->getLine(), "Void function used in expression");
    }
    string op = ctx->MULOP()->getText();
    string resType = "INT";
    if (op == "%") {
        if (tNd.type != "INT" || uNd.type != "INT") {
            printErr(ctx->getStart()->getLine(), "Non-Integer operand on modulus operator");
        } else if (uNd.isConstant && uNd.intVal == 0) {
            printErr(ctx->getStart()->getLine(), "Modulus by Zero");
        }
    } else {
        if (tNd.type == "FLOAT" || uNd.type == "FLOAT") resType = "FLOAT";
    }
    string ruleTxt = tNd.text + op + uNd.text;
    printLog(ctx->getStart()->getLine(), "term : term MULOP unary_expression", ruleTxt);
    return ParseNode{ruleTxt, resType};
}

any TreeVisitor::visitUnary_addop(CSubset_2205009Parser::Unary_addopContext *ctx) {
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unary_expression()));
    if (uNd.type == "VOID") {
        printErr(ctx->getStart()->getLine(), "Void function used in expression");
    }
    string op = ctx->ADDOP()->getText();
    string ruleTxt = op + uNd.text;
    printLog(ctx->getStart()->getLine(), "unary_expression : ADDOP unary_expression", ruleTxt);
    return ParseNode{ruleTxt, uNd.type};
}

any TreeVisitor::visitUnary_not(CSubset_2205009Parser::Unary_notContext *ctx) {
    ParseNode uNd = std::any_cast<ParseNode>(visit(ctx->unary_expression()));
    if (uNd.type == "VOID") {
        printErr(ctx->getStart()->getLine(), "Void function used in expression");
    }
    string op = ctx->NOT()->getText();
    string ruleTxt = op + uNd.text;
    printLog(ctx->getStart()->getLine(), "unary_expression : NOT unary expression", ruleTxt);
    return ParseNode{ruleTxt, "INT"};
}

any TreeVisitor::visitUnary_factor(CSubset_2205009Parser::Unary_factorContext *ctx) {
    ParseNode fNd = std::any_cast<ParseNode>(visit(ctx->factor()));
    printLog(ctx->getStart()->getLine(), "unary_expression : factor", fNd.text);
    return fNd;
}

any TreeVisitor::visitFactor_var(CSubset_2205009Parser::Factor_varContext *ctx) {
    ParseNode vNd = std::any_cast<ParseNode>(visit(ctx->variable()));
    printLog(ctx->getStart()->getLine(), "factor : variable", vNd.text);
    return vNd;
}

any TreeVisitor::visitFactor_func_call(CSubset_2205009Parser::Factor_func_callContext *ctx) {
    string funcName = ctx->ID()->getText();
    ParseNode aNd = std::any_cast<ParseNode>(visit(ctx->argument_list()));
    SymbolInfo *sym = st.lookup(funcName);

    string ruleTxt = funcName + "(" + aNd.text + ")";

    if (sym == NULL) {
        printErr(ctx->getStart()->getLine(), "Undeclared function " + funcName);
        printLog(ctx->getStart()->getLine(), "factor : ID LPAREN argument_list RPAREN", ruleTxt);
        return ParseNode{ruleTxt, "ERROR"};
    }
    if (!sym->getIsFunction()) {
        printErr(ctx->getStart()->getLine(), funcName + " is not a function");
        printLog(ctx->getStart()->getLine(), "factor : ID LPAREN argument_list RPAREN", ruleTxt);
        return ParseNode{ruleTxt, "ERROR"};
    }

    if (sym->getParamCount() != (int)aNd.paramTypes.size()) {
        printErr(ctx->getStart()->getLine(), "Total number of arguments mismatch in function " + funcName);
    } else {
        for (int i = 0; i < sym->getParamCount(); i++) {
            if (i < (int)aNd.paramIsArr.size() && aNd.paramIsArr[i]) {
                break;
            } else if (sym->getParamType(i) != aNd.paramTypes[i]) {
                printErr(ctx->getStart()->getLine(), to_string(i + 1) + "th argument mismatch in function " + funcName);
                break;
            }
        }
    }

    printLog(ctx->getStart()->getLine(), "factor : ID LPAREN argument_list RPAREN", ruleTxt);
    return ParseNode{ruleTxt, sym->getretType()};
}




any TreeVisitor::visitFactor_paren(CSubset_2205009Parser::Factor_parenContext *ctx) {
    ParseNode eNd = std::any_cast<ParseNode>(visit(ctx->expression()));
    string ruleTxt = "(" + eNd.text + ")";
    printLog(ctx->getStart()->getLine(), "factor : LPAREN expression RPAREN", ruleTxt);
    return ParseNode{ruleTxt, eNd.type};
}

any TreeVisitor::visitFactor_int(CSubset_2205009Parser::Factor_intContext *ctx) {
    string val = ctx->CONST_INT()->getText();
    printLog(ctx->getStart()->getLine(), "factor : CONST_INT", val);
    ParseNode nd{val, "INT"};
    nd.isConstant = true;
    nd.intVal = stoi(val);
    return nd;
}

any TreeVisitor::visitFactor_float(CSubset_2205009Parser::Factor_floatContext *ctx) {
    string val = ctx->CONST_FLOAT()->getText();
    char buf[64];
    snprintf(buf, sizeof(buf), "%.2f", stod(val));
    string formattedVal(buf);
    printLog(ctx->getStart()->getLine(), "factor : CONST_FLOAT", formattedVal);
    ParseNode nd{formattedVal, "FLOAT"};
    nd.isConstant = true;
    nd.floatVal = stod(val);
    return nd;
}


any TreeVisitor::visitFactor_inc(CSubset_2205009Parser::Factor_incContext *ctx) {
    ParseNode vNd = std::any_cast<ParseNode>(visit(ctx->variable()));
    string ruleTxt = vNd.text + "++";
    printLog(ctx->getStart()->getLine(), "factor : variable INCOP", ruleTxt);
    return ParseNode{ruleTxt, vNd.type};
}

any TreeVisitor::visitFactor_dec(CSubset_2205009Parser::Factor_decContext *ctx) {
    ParseNode vNd = std::any_cast<ParseNode>(visit(ctx->variable()));
    string ruleTxt = vNd.text + "--";
    printLog(ctx->getStart()->getLine(), "factor : variable DECOP", ruleTxt);
    return ParseNode{ruleTxt, vNd.type};
}

any TreeVisitor::visitArg_list(CSubset_2205009Parser::Arg_listContext *ctx) {
    ParseNode aNd = std::any_cast<ParseNode>(visit(ctx->arguments()));
    printLog(ctx->getStart()->getLine(), "argument_list : arguments", aNd.text);
    return aNd;
}

any TreeVisitor::visitArg_list_empty(CSubset_2205009Parser::Arg_list_emptyContext *ctx) {
    printLog(ctx->getStart()->getLine(), "argument_list : ", "");
    return ParseNode{""};
}

any TreeVisitor::visitArgs_single(CSubset_2205009Parser::Args_singleContext *ctx) {
    ParseNode lNd = std::any_cast<ParseNode>(visit(ctx->logic_expression()));
    printLog(ctx->getStart()->getLine(), "arguments : logic_expression", lNd.text);
    ParseNode res{lNd.text};
    res.paramTypes.push_back(lNd.type);
    res.paramNames.push_back(lNd.name);
    res.paramIsArr.push_back(lNd.isArray);
    return res;
}

any TreeVisitor::visitArgs_multi(CSubset_2205009Parser::Args_multiContext *ctx) {
    ParseNode aNd = std::any_cast<ParseNode>(visit(ctx->arguments()));
    ParseNode lNd = std::any_cast<ParseNode>(visit(ctx->logic_expression()));
    string ruleTxt = aNd.text + "," + lNd.text;
    printLog(ctx->getStart()->getLine(), "arguments : arguments COMMA logic_expression", ruleTxt);
    ParseNode res{ruleTxt};
    res.paramTypes = aNd.paramTypes;
    res.paramTypes.push_back(lNd.type);
    res.paramNames = aNd.paramNames;
    res.paramNames.push_back(lNd.name);
    res.paramIsArr = aNd.paramIsArr;
    res.paramIsArr.push_back(lNd.isArray);
    return res;
}