
// Generated from CSubset_2205009.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  CSubset_2205009Parser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, LTHIRD = 18, 
    RTHIRD = 19, SEMICOLON = 20, COMMA = 21, ADDOP = 22, MULOP = 23, INCOP = 24, 
    DECOP = 25, NOT = 26, RELOP = 27, LOGICOP = 28, ASSIGNOP = 29, ID = 30, 
    CONST_INT = 31, CONST_FLOAT = 32
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleParameter_list = 5, RuleCompound_statement = 6, 
    RuleVar_declaration = 7, RuleType_specifier = 8, RuleDeclaration_list = 9, 
    RuleStatements = 10, RuleStatement = 11, RuleExpression_statement = 12, 
    RuleVariable = 13, RuleExpression = 14, RuleLogic_expression = 15, RuleRel_expression = 16, 
    RuleSimple_expression = 17, RuleTerm = 18, RuleUnary_expression = 19, 
    RuleFactor = 20, RuleArgument_list = 21, RuleArguments = 22
  };

  explicit CSubset_2205009Parser(antlr4::TokenStream *input);

  CSubset_2205009Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CSubset_2205009Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_listContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProgramContext() = default;
    void copyFrom(ProgramContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnitRuleContext : public ProgramContext {
  public:
    UnitRuleContext(ProgramContext *ctx);

    UnitContext *unit();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ProgUnitRuleContext : public ProgramContext {
  public:
    ProgUnitRuleContext(ProgramContext *ctx);

    ProgramContext *program();
    UnitContext *unit();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnitContext() = default;
    void copyFrom(UnitContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Var_decContext : public UnitContext {
  public:
    Var_decContext(UnitContext *ctx);

    Var_declarationContext *var_declaration();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Func_decContext : public UnitContext {
  public:
    Func_decContext(UnitContext *ctx);

    Func_declarationContext *func_declaration();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Func_defContext : public UnitContext {
  public:
    Func_defContext(UnitContext *ctx);

    Func_definitionContext *func_definition();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Func_declarationContext() = default;
    void copyFrom(Func_declarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Funcdec_without_paramContext : public Func_declarationContext {
  public:
    Funcdec_without_paramContext(Func_declarationContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Funcdec_with_paramContext : public Func_declarationContext {
  public:
    Funcdec_with_paramContext(Func_declarationContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Func_definitionContext() = default;
    void copyFrom(Func_definitionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Funcdef_without_paramContext : public Func_definitionContext {
  public:
    Funcdef_without_paramContext(Func_definitionContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Funcdef_with_paramContext : public Func_definitionContext {
  public:
    Funcdef_with_paramContext(Func_definitionContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Func_definitionContext* func_definition();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Parameter_listContext() = default;
    void copyFrom(Parameter_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Param_without_idContext : public Parameter_listContext {
  public:
    Param_without_idContext(Parameter_listContext *ctx);

    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *COMMA();
    Type_specifierContext *type_specifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Param_with_id_singleContext : public Parameter_listContext {
  public:
    Param_with_id_singleContext(Parameter_listContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Param_with_idContext : public Parameter_listContext {
  public:
    Param_with_idContext(Parameter_listContext *ctx);

    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *COMMA();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Param_without_id_singleContext : public Parameter_listContext {
  public:
    Param_without_id_singleContext(Parameter_listContext *ctx);

    Type_specifierContext *type_specifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Param_with_addopContext : public Parameter_listContext {
  public:
    Param_with_addopContext(Parameter_listContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ADDOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Compound_statementContext() = default;
    void copyFrom(Compound_statementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Compstat_emptyContext : public Compound_statementContext {
  public:
    Compstat_emptyContext(Compound_statementContext *ctx);

    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Compstat_with_statementsContext : public Compound_statementContext {
  public:
    Compstat_with_statementsContext(Compound_statementContext *ctx);

    antlr4::tree::TerminalNode *LCURL();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *RCURL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Compound_statementContext* compound_statement();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Type_specifierContext() = default;
    void copyFrom(Type_specifierContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Type_floatContext : public Type_specifierContext {
  public:
    Type_floatContext(Type_specifierContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_voidContext : public Type_specifierContext {
  public:
    Type_voidContext(Type_specifierContext *ctx);

    antlr4::tree::TerminalNode *VOID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Type_intContext : public Type_specifierContext {
  public:
    Type_intContext(Type_specifierContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Declaration_listContext() = default;
    void copyFrom(Declaration_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Dec_with_idarr_singleContext : public Declaration_listContext {
  public:
    Dec_with_idarr_singleContext(Declaration_listContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dec_with_id_singleContext : public Declaration_listContext {
  public:
    Dec_with_id_singleContext(Declaration_listContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dec_with_idarrContext : public Declaration_listContext {
  public:
    Dec_with_idarrContext(Declaration_listContext *ctx);

    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dec_with_addopContext : public Declaration_listContext {
  public:
    Dec_with_addopContext(Declaration_listContext *ctx);

    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Dec_with_idContext : public Declaration_listContext {
  public:
    Dec_with_idContext(Declaration_listContext *ctx);

    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementsContext() = default;
    void copyFrom(StatementsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Stat_singleContext : public StatementsContext {
  public:
    Stat_singleContext(StatementsContext *ctx);

    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_multipleContext : public StatementsContext {
  public:
    Stat_multipleContext(StatementsContext *ctx);

    StatementsContext *statements();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Stat_var_decContext : public StatementContext {
  public:
    Stat_var_decContext(StatementContext *ctx);

    Var_declarationContext *var_declaration();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_compoundContext : public StatementContext {
  public:
    Stat_compoundContext(StatementContext *ctx);

    Compound_statementContext *compound_statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_ifContext : public StatementContext {
  public:
    Stat_ifContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_returnContext : public StatementContext {
  public:
    Stat_returnContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_for_loopContext : public StatementContext {
  public:
    Stat_for_loopContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_printlnContext : public StatementContext {
  public:
    Stat_printlnContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_whileContext : public StatementContext {
  public:
    Stat_whileContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_if_elseContext : public StatementContext {
  public:
    Stat_if_elseContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Stat_exprContext : public StatementContext {
  public:
    Stat_exprContext(StatementContext *ctx);

    Expression_statementContext *expression_statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expression_statementContext() = default;
    void copyFrom(Expression_statementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Expr_endContext : public Expression_statementContext {
  public:
    Expr_endContext(Expression_statementContext *ctx);

    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_assign_addopContext : public Expression_statementContext {
  public:
    Expr_assign_addopContext(Expression_statementContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *ASSIGNOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_with_exprContext : public Expression_statementContext {
  public:
    Expr_with_exprContext(Expression_statementContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VariableContext() = default;
    void copyFrom(VariableContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Var_arrContext : public VariableContext {
  public:
    Var_arrContext(VariableContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RTHIRD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Var_idContext : public VariableContext {
  public:
    Var_idContext(VariableContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Expr_assignContext : public ExpressionContext {
  public:
    Expr_assignContext(ExpressionContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGNOP();
    Logic_expressionContext *logic_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr_logicContext : public ExpressionContext {
  public:
    Expr_logicContext(ExpressionContext *ctx);

    Logic_expressionContext *logic_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Logic_expressionContext() = default;
    void copyFrom(Logic_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Logic_relContext : public Logic_expressionContext {
  public:
    Logic_relContext(Logic_expressionContext *ctx);

    Rel_expressionContext *rel_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Logic_opContext : public Logic_expressionContext {
  public:
    Logic_opContext(Logic_expressionContext *ctx);

    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Rel_expressionContext() = default;
    void copyFrom(Rel_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Rel_simpleContext : public Rel_expressionContext {
  public:
    Rel_simpleContext(Rel_expressionContext *ctx);

    Simple_expressionContext *simple_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Rel_opContext : public Rel_expressionContext {
  public:
    Rel_opContext(Rel_expressionContext *ctx);

    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Simple_expressionContext() = default;
    void copyFrom(Simple_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Simp_termContext : public Simple_expressionContext {
  public:
    Simp_termContext(Simple_expressionContext *ctx);

    TermContext *term();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Simp_addopContext : public Simple_expressionContext {
  public:
    Simp_addopContext(Simple_expressionContext *ctx);

    Simple_expressionContext *simple_expression();
    antlr4::tree::TerminalNode *ADDOP();
    TermContext *term();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermContext() = default;
    void copyFrom(TermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Term_mulopContext : public TermContext {
  public:
    Term_mulopContext(TermContext *ctx);

    TermContext *term();
    antlr4::tree::TerminalNode *MULOP();
    Unary_expressionContext *unary_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Term_unaryContext : public TermContext {
  public:
    Term_unaryContext(TermContext *ctx);

    Unary_expressionContext *unary_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Unary_expressionContext() = default;
    void copyFrom(Unary_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Unary_notContext : public Unary_expressionContext {
  public:
    Unary_notContext(Unary_expressionContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    Unary_expressionContext *unary_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Unary_factorContext : public Unary_expressionContext {
  public:
    Unary_factorContext(Unary_expressionContext *ctx);

    FactorContext *factor();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Unary_addopContext : public Unary_expressionContext {
  public:
    Unary_addopContext(Unary_expressionContext *ctx);

    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FactorContext() = default;
    void copyFrom(FactorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Factor_func_callContext : public FactorContext {
  public:
    Factor_func_callContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Argument_listContext *argument_list();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Factor_varContext : public FactorContext {
  public:
    Factor_varContext(FactorContext *ctx);

    VariableContext *variable();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Factor_floatContext : public FactorContext {
  public:
    Factor_floatContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *CONST_FLOAT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Factor_decContext : public FactorContext {
  public:
    Factor_decContext(FactorContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *DECOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Factor_intContext : public FactorContext {
  public:
    Factor_intContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *CONST_INT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Factor_incContext : public FactorContext {
  public:
    Factor_incContext(FactorContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *INCOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Factor_parenContext : public FactorContext {
  public:
    Factor_parenContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Argument_listContext() = default;
    void copyFrom(Argument_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Arg_list_emptyContext : public Argument_listContext {
  public:
    Arg_list_emptyContext(Argument_listContext *ctx);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Arg_listContext : public Argument_listContext {
  public:
    Arg_listContext(Argument_listContext *ctx);

    ArgumentsContext *arguments();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ArgumentsContext() = default;
    void copyFrom(ArgumentsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Args_multiContext : public ArgumentsContext {
  public:
    Args_multiContext(ArgumentsContext *ctx);

    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *COMMA();
    Logic_expressionContext *logic_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Args_singleContext : public ArgumentsContext {
  public:
    Args_singleContext(ArgumentsContext *ctx);

    Logic_expressionContext *logic_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

