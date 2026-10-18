
// Generated from CSubset_2205009.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubset_2205009Visitor.h"


/**
 * This class provides an empty implementation of CSubset_2205009Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CSubset_2205009BaseVisitor : public CSubset_2205009Visitor {
public:

  virtual std::any visitStart(CSubset_2205009Parser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitRule(CSubset_2205009Parser::UnitRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgUnitRule(CSubset_2205009Parser::ProgUnitRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_dec(CSubset_2205009Parser::Var_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_dec(CSubset_2205009Parser::Func_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_def(CSubset_2205009Parser::Func_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncdec_with_param(CSubset_2205009Parser::Funcdec_with_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncdec_without_param(CSubset_2205009Parser::Funcdec_without_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncdef_with_param(CSubset_2205009Parser::Funcdef_with_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncdef_without_param(CSubset_2205009Parser::Funcdef_without_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_without_id(CSubset_2205009Parser::Param_without_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_with_id_single(CSubset_2205009Parser::Param_with_id_singleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_with_id(CSubset_2205009Parser::Param_with_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_without_id_single(CSubset_2205009Parser::Param_without_id_singleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_with_addop(CSubset_2205009Parser::Param_with_addopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompstat_with_statements(CSubset_2205009Parser::Compstat_with_statementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompstat_empty(CSubset_2205009Parser::Compstat_emptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declaration(CSubset_2205009Parser::Var_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_int(CSubset_2205009Parser::Type_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_float(CSubset_2205009Parser::Type_floatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_void(CSubset_2205009Parser::Type_voidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDec_with_idarr_single(CSubset_2205009Parser::Dec_with_idarr_singleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDec_with_id_single(CSubset_2205009Parser::Dec_with_id_singleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDec_with_idarr(CSubset_2205009Parser::Dec_with_idarrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDec_with_addop(CSubset_2205009Parser::Dec_with_addopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDec_with_id(CSubset_2205009Parser::Dec_with_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_single(CSubset_2205009Parser::Stat_singleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_multiple(CSubset_2205009Parser::Stat_multipleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_var_dec(CSubset_2205009Parser::Stat_var_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_expr(CSubset_2205009Parser::Stat_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_compound(CSubset_2205009Parser::Stat_compoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_for_loop(CSubset_2205009Parser::Stat_for_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_if(CSubset_2205009Parser::Stat_ifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_if_else(CSubset_2205009Parser::Stat_if_elseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_while(CSubset_2205009Parser::Stat_whileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_println(CSubset_2205009Parser::Stat_printlnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStat_return(CSubset_2205009Parser::Stat_returnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_end(CSubset_2205009Parser::Expr_endContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_with_expr(CSubset_2205009Parser::Expr_with_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_assign_addop(CSubset_2205009Parser::Expr_assign_addopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_id(CSubset_2205009Parser::Var_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_arr(CSubset_2205009Parser::Var_arrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_logic(CSubset_2205009Parser::Expr_logicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_assign(CSubset_2205009Parser::Expr_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_rel(CSubset_2205009Parser::Logic_relContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_op(CSubset_2205009Parser::Logic_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel_simple(CSubset_2205009Parser::Rel_simpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel_op(CSubset_2205009Parser::Rel_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimp_term(CSubset_2205009Parser::Simp_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimp_addop(CSubset_2205009Parser::Simp_addopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm_mulop(CSubset_2205009Parser::Term_mulopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm_unary(CSubset_2205009Parser::Term_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_addop(CSubset_2205009Parser::Unary_addopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_not(CSubset_2205009Parser::Unary_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_factor(CSubset_2205009Parser::Unary_factorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_var(CSubset_2205009Parser::Factor_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_func_call(CSubset_2205009Parser::Factor_func_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_paren(CSubset_2205009Parser::Factor_parenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_int(CSubset_2205009Parser::Factor_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_float(CSubset_2205009Parser::Factor_floatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_inc(CSubset_2205009Parser::Factor_incContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor_dec(CSubset_2205009Parser::Factor_decContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg_list(CSubset_2205009Parser::Arg_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg_list_empty(CSubset_2205009Parser::Arg_list_emptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs_multi(CSubset_2205009Parser::Args_multiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs_single(CSubset_2205009Parser::Args_singleContext *ctx) override {
    return visitChildren(ctx);
  }


};

