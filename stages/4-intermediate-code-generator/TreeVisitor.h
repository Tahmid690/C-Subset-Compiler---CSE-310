#pragma once

#include "antlr4-runtime.h"
#include "CSubset_2205009BaseVisitor.h"
#include "2205009_SymbolTable.h"
#include <bits/stdc++.h>

using namespace std;

struct ParseNode {
    string text;
    string type;
    string name;
    bool isArray = false;
    int arrSz = 0;
    bool isFunction = false;
    string returnType;
    vector<string> paramTypes;
    vector<string> paramNames;
    vector<bool> paramIsArr;
    bool isConstant = false;
    int intVal = 0;
    double floatVal = 0.0;
    bool isHandled = false;
    bool isGlobal = false;
    int offset;
};


class TreeVisitor : public CSubset_2205009BaseVisitor {
private:
    SymbolTable st;
    ofstream codeOut,golbOut;
    int errcnt;
    string currTyp;
    bool skpNxt;
    int segment_no;
    int nextLocalOffset;
    int global_flag;
    string currentFuncName;

public:
    TreeVisitor();
    virtual ~TreeVisitor();

    virtual std::any visitStart(CSubset_2205009Parser::StartContext *ctx) override;
    virtual std::any visitUnitRule(CSubset_2205009Parser::UnitRuleContext *ctx) override;
    virtual std::any visitProgUnitRule(CSubset_2205009Parser::ProgUnitRuleContext *ctx) override;
    virtual std::any visitVar_dec(CSubset_2205009Parser::Var_decContext *ctx) override;
    virtual std::any visitFunc_dec(CSubset_2205009Parser::Func_decContext *ctx) override;
    virtual std::any visitFunc_def(CSubset_2205009Parser::Func_defContext *ctx) override;

    virtual std::any visitFuncdec_with_param(CSubset_2205009Parser::Funcdec_with_paramContext *ctx) override;
    virtual std::any visitFuncdec_without_param(CSubset_2205009Parser::Funcdec_without_paramContext *ctx) override;
    virtual std::any visitFuncdef_with_param(CSubset_2205009Parser::Funcdef_with_paramContext *ctx) override;
    virtual std::any visitFuncdef_without_param(CSubset_2205009Parser::Funcdef_without_paramContext *ctx) override;

    virtual std::any visitParam_without_id(CSubset_2205009Parser::Param_without_idContext *ctx) override;
    virtual std::any visitParam_with_id_single(CSubset_2205009Parser::Param_with_id_singleContext *ctx) override;
    virtual std::any visitParam_with_id(CSubset_2205009Parser::Param_with_idContext *ctx) override;
    virtual std::any visitParam_without_id_single(CSubset_2205009Parser::Param_without_id_singleContext *ctx) override;
    virtual std::any visitParam_with_addop(CSubset_2205009Parser::Param_with_addopContext *ctx) override;

    virtual std::any visitCompstat_with_statements(CSubset_2205009Parser::Compstat_with_statementsContext *ctx) override;
    virtual std::any visitCompstat_empty(CSubset_2205009Parser::Compstat_emptyContext *ctx) override;

    virtual std::any visitVar_declaration(CSubset_2205009Parser::Var_declarationContext *ctx) override;
    virtual std::any visitType_int(CSubset_2205009Parser::Type_intContext *ctx) override;
    virtual std::any visitType_float(CSubset_2205009Parser::Type_floatContext *ctx) override;
    virtual std::any visitType_void(CSubset_2205009Parser::Type_voidContext *ctx) override;

    virtual std::any visitDec_with_idarr_single(CSubset_2205009Parser::Dec_with_idarr_singleContext *ctx) override;
    virtual std::any visitDec_with_id_single(CSubset_2205009Parser::Dec_with_id_singleContext *ctx) override;
    virtual std::any visitDec_with_idarr(CSubset_2205009Parser::Dec_with_idarrContext *ctx) override;
    virtual std::any visitDec_with_addop(CSubset_2205009Parser::Dec_with_addopContext *ctx) override;
    virtual std::any visitDec_with_id(CSubset_2205009Parser::Dec_with_idContext *ctx) override;

    virtual std::any visitStat_single(CSubset_2205009Parser::Stat_singleContext *ctx) override;
    virtual std::any visitStat_multiple(CSubset_2205009Parser::Stat_multipleContext *ctx) override;
    virtual std::any visitStat_var_dec(CSubset_2205009Parser::Stat_var_decContext *ctx) override;
    virtual std::any visitStat_expr(CSubset_2205009Parser::Stat_exprContext *ctx) override;
    virtual std::any visitStat_compound(CSubset_2205009Parser::Stat_compoundContext *ctx) override;
    virtual std::any visitStat_for_loop(CSubset_2205009Parser::Stat_for_loopContext *ctx) override;
    virtual std::any visitStat_if(CSubset_2205009Parser::Stat_ifContext *ctx) override;
    virtual std::any visitStat_if_else(CSubset_2205009Parser::Stat_if_elseContext *ctx) override;
    virtual std::any visitStat_while(CSubset_2205009Parser::Stat_whileContext *ctx) override;
    virtual std::any visitStat_println(CSubset_2205009Parser::Stat_printlnContext *ctx) override;
    virtual std::any visitStat_return(CSubset_2205009Parser::Stat_returnContext *ctx) override;

    virtual std::any visitExpr_end(CSubset_2205009Parser::Expr_endContext *ctx) override;
    virtual std::any visitExpr_with_expr(CSubset_2205009Parser::Expr_with_exprContext *ctx) override;
    virtual std::any visitExpr_assign_addop(CSubset_2205009Parser::Expr_assign_addopContext *ctx) override;

    virtual std::any visitVar_id(CSubset_2205009Parser::Var_idContext *ctx) override;
    virtual std::any visitVar_arr(CSubset_2205009Parser::Var_arrContext *ctx) override;

    virtual std::any visitExpr_logic(CSubset_2205009Parser::Expr_logicContext *ctx) override;
    virtual std::any visitExpr_assign(CSubset_2205009Parser::Expr_assignContext *ctx) override;

    virtual std::any visitLogic_rel(CSubset_2205009Parser::Logic_relContext *ctx) override;
    virtual std::any visitLogic_op(CSubset_2205009Parser::Logic_opContext *ctx) override;

    virtual std::any visitRel_simple(CSubset_2205009Parser::Rel_simpleContext *ctx) override;
    virtual std::any visitRel_op(CSubset_2205009Parser::Rel_opContext *ctx) override;

    virtual std::any visitSimp_term(CSubset_2205009Parser::Simp_termContext *ctx) override;
    virtual std::any visitSimp_addop(CSubset_2205009Parser::Simp_addopContext *ctx) override;

    virtual std::any visitTerm_mulop(CSubset_2205009Parser::Term_mulopContext *ctx) override;
    virtual std::any visitTerm_unary(CSubset_2205009Parser::Term_unaryContext *ctx) override;

    virtual std::any visitUnary_addop(CSubset_2205009Parser::Unary_addopContext *ctx) override;
    virtual std::any visitUnary_not(CSubset_2205009Parser::Unary_notContext *ctx) override;
    virtual std::any visitUnary_factor(CSubset_2205009Parser::Unary_factorContext *ctx) override;

    virtual std::any visitFactor_var(CSubset_2205009Parser::Factor_varContext *ctx) override;
    virtual std::any visitFactor_func_call(CSubset_2205009Parser::Factor_func_callContext *ctx) override;
    virtual std::any visitFactor_paren(CSubset_2205009Parser::Factor_parenContext *ctx) override;
    virtual std::any visitFactor_int(CSubset_2205009Parser::Factor_intContext *ctx) override;
    virtual std::any visitFactor_float(CSubset_2205009Parser::Factor_floatContext *ctx) override;
    virtual std::any visitFactor_inc(CSubset_2205009Parser::Factor_incContext *ctx) override;
    virtual std::any visitFactor_dec(CSubset_2205009Parser::Factor_decContext *ctx) override;

    virtual std::any visitArg_list(CSubset_2205009Parser::Arg_listContext *ctx) override;
    virtual std::any visitArg_list_empty(CSubset_2205009Parser::Arg_list_emptyContext *ctx) override;
    virtual std::any visitArgs_multi(CSubset_2205009Parser::Args_multiContext *ctx) override;
    virtual std::any visitArgs_single(CSubset_2205009Parser::Args_singleContext *ctx) override;
};
