
// Generated from CSubset_2205009.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubset_2205009Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CSubset_2205009Parser.
 */
class  CSubset_2205009Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CSubset_2205009Parser.
   */
    virtual std::any visitStart(CSubset_2205009Parser::StartContext *context) = 0;

    virtual std::any visitUnitRule(CSubset_2205009Parser::UnitRuleContext *context) = 0;

    virtual std::any visitProgUnitRule(CSubset_2205009Parser::ProgUnitRuleContext *context) = 0;

    virtual std::any visitVar_dec(CSubset_2205009Parser::Var_decContext *context) = 0;

    virtual std::any visitFunc_dec(CSubset_2205009Parser::Func_decContext *context) = 0;

    virtual std::any visitFunc_def(CSubset_2205009Parser::Func_defContext *context) = 0;

    virtual std::any visitFuncdec_with_param(CSubset_2205009Parser::Funcdec_with_paramContext *context) = 0;

    virtual std::any visitFuncdec_without_param(CSubset_2205009Parser::Funcdec_without_paramContext *context) = 0;

    virtual std::any visitFuncdef_with_param(CSubset_2205009Parser::Funcdef_with_paramContext *context) = 0;

    virtual std::any visitFuncdef_without_param(CSubset_2205009Parser::Funcdef_without_paramContext *context) = 0;

    virtual std::any visitParam_without_id(CSubset_2205009Parser::Param_without_idContext *context) = 0;

    virtual std::any visitParam_with_id_single(CSubset_2205009Parser::Param_with_id_singleContext *context) = 0;

    virtual std::any visitParam_with_id(CSubset_2205009Parser::Param_with_idContext *context) = 0;

    virtual std::any visitParam_without_id_single(CSubset_2205009Parser::Param_without_id_singleContext *context) = 0;

    virtual std::any visitParam_with_addop(CSubset_2205009Parser::Param_with_addopContext *context) = 0;

    virtual std::any visitCompstat_with_statements(CSubset_2205009Parser::Compstat_with_statementsContext *context) = 0;

    virtual std::any visitCompstat_empty(CSubset_2205009Parser::Compstat_emptyContext *context) = 0;

    virtual std::any visitVar_declaration(CSubset_2205009Parser::Var_declarationContext *context) = 0;

    virtual std::any visitType_int(CSubset_2205009Parser::Type_intContext *context) = 0;

    virtual std::any visitType_float(CSubset_2205009Parser::Type_floatContext *context) = 0;

    virtual std::any visitType_void(CSubset_2205009Parser::Type_voidContext *context) = 0;

    virtual std::any visitDec_with_idarr_single(CSubset_2205009Parser::Dec_with_idarr_singleContext *context) = 0;

    virtual std::any visitDec_with_id_single(CSubset_2205009Parser::Dec_with_id_singleContext *context) = 0;

    virtual std::any visitDec_with_idarr(CSubset_2205009Parser::Dec_with_idarrContext *context) = 0;

    virtual std::any visitDec_with_addop(CSubset_2205009Parser::Dec_with_addopContext *context) = 0;

    virtual std::any visitDec_with_id(CSubset_2205009Parser::Dec_with_idContext *context) = 0;

    virtual std::any visitStat_single(CSubset_2205009Parser::Stat_singleContext *context) = 0;

    virtual std::any visitStat_multiple(CSubset_2205009Parser::Stat_multipleContext *context) = 0;

    virtual std::any visitStat_var_dec(CSubset_2205009Parser::Stat_var_decContext *context) = 0;

    virtual std::any visitStat_expr(CSubset_2205009Parser::Stat_exprContext *context) = 0;

    virtual std::any visitStat_compound(CSubset_2205009Parser::Stat_compoundContext *context) = 0;

    virtual std::any visitStat_for_loop(CSubset_2205009Parser::Stat_for_loopContext *context) = 0;

    virtual std::any visitStat_if(CSubset_2205009Parser::Stat_ifContext *context) = 0;

    virtual std::any visitStat_if_else(CSubset_2205009Parser::Stat_if_elseContext *context) = 0;

    virtual std::any visitStat_while(CSubset_2205009Parser::Stat_whileContext *context) = 0;

    virtual std::any visitStat_println(CSubset_2205009Parser::Stat_printlnContext *context) = 0;

    virtual std::any visitStat_return(CSubset_2205009Parser::Stat_returnContext *context) = 0;

    virtual std::any visitExpr_end(CSubset_2205009Parser::Expr_endContext *context) = 0;

    virtual std::any visitExpr_with_expr(CSubset_2205009Parser::Expr_with_exprContext *context) = 0;

    virtual std::any visitExpr_assign_addop(CSubset_2205009Parser::Expr_assign_addopContext *context) = 0;

    virtual std::any visitVar_id(CSubset_2205009Parser::Var_idContext *context) = 0;

    virtual std::any visitVar_arr(CSubset_2205009Parser::Var_arrContext *context) = 0;

    virtual std::any visitExpr_logic(CSubset_2205009Parser::Expr_logicContext *context) = 0;

    virtual std::any visitExpr_assign(CSubset_2205009Parser::Expr_assignContext *context) = 0;

    virtual std::any visitLogic_rel(CSubset_2205009Parser::Logic_relContext *context) = 0;

    virtual std::any visitLogic_op(CSubset_2205009Parser::Logic_opContext *context) = 0;

    virtual std::any visitRel_simple(CSubset_2205009Parser::Rel_simpleContext *context) = 0;

    virtual std::any visitRel_op(CSubset_2205009Parser::Rel_opContext *context) = 0;

    virtual std::any visitSimp_term(CSubset_2205009Parser::Simp_termContext *context) = 0;

    virtual std::any visitSimp_addop(CSubset_2205009Parser::Simp_addopContext *context) = 0;

    virtual std::any visitTerm_mulop(CSubset_2205009Parser::Term_mulopContext *context) = 0;

    virtual std::any visitTerm_unary(CSubset_2205009Parser::Term_unaryContext *context) = 0;

    virtual std::any visitUnary_addop(CSubset_2205009Parser::Unary_addopContext *context) = 0;

    virtual std::any visitUnary_not(CSubset_2205009Parser::Unary_notContext *context) = 0;

    virtual std::any visitUnary_factor(CSubset_2205009Parser::Unary_factorContext *context) = 0;

    virtual std::any visitFactor_var(CSubset_2205009Parser::Factor_varContext *context) = 0;

    virtual std::any visitFactor_func_call(CSubset_2205009Parser::Factor_func_callContext *context) = 0;

    virtual std::any visitFactor_paren(CSubset_2205009Parser::Factor_parenContext *context) = 0;

    virtual std::any visitFactor_int(CSubset_2205009Parser::Factor_intContext *context) = 0;

    virtual std::any visitFactor_float(CSubset_2205009Parser::Factor_floatContext *context) = 0;

    virtual std::any visitFactor_inc(CSubset_2205009Parser::Factor_incContext *context) = 0;

    virtual std::any visitFactor_dec(CSubset_2205009Parser::Factor_decContext *context) = 0;

    virtual std::any visitArg_list(CSubset_2205009Parser::Arg_listContext *context) = 0;

    virtual std::any visitArg_list_empty(CSubset_2205009Parser::Arg_list_emptyContext *context) = 0;

    virtual std::any visitArgs_multi(CSubset_2205009Parser::Args_multiContext *context) = 0;

    virtual std::any visitArgs_single(CSubset_2205009Parser::Args_singleContext *context) = 0;


};

