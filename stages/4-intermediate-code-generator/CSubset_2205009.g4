grammar CSubset_2205009;
import Lexer_2205009;

start : program ;

program
    : program unit  #ProgUnitRule
    | unit          #UnitRule
    ;

unit
    : var_declaration   #var_dec
    | func_declaration  #func_dec
    | func_definition   #func_def
    ;

func_declaration
    : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  #funcdec_with_param
    | type_specifier ID LPAREN RPAREN SEMICOLON                 #funcdec_without_param
    ;

func_definition
    : type_specifier ID LPAREN parameter_list RPAREN compound_statement #funcdef_with_param
    | type_specifier ID LPAREN RPAREN compound_statement                #funcdef_without_param 
    ;

parameter_list
    : parameter_list COMMA type_specifier ID    #param_with_id
    | parameter_list COMMA type_specifier       #param_without_id
    | type_specifier ID                         #param_with_id_single
    | type_specifier                            #param_without_id_single
    | type_specifier ADDOP                      #param_with_addop
    ;

compound_statement
    : LCURL statements RCURL                    #compstat_with_statements
    | LCURL RCURL                               #compstat_empty
    ;

var_declaration
    : type_specifier declaration_list SEMICOLON ;

type_specifier
    : INT                                       #type_int 
    | FLOAT                                     #type_float        
    | VOID                                      #type_void                             
    ;

declaration_list
    : declaration_list COMMA ID                             #dec_with_id
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD     #dec_with_idarr
    | ID                                                    #dec_with_id_single
    | ID LTHIRD CONST_INT RTHIRD                            #dec_with_idarr_single
    | declaration_list ADDOP ID                             #dec_with_addop
    ;

statements
    : statement                                             #stat_single
    | statements statement                                  #stat_multiple
    ;

statement
    : var_declaration                                                                       #stat_var_dec
    | expression_statement                                                                  #stat_expr
    | compound_statement                                                                    #stat_compound
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement      #stat_for_loop
    | IF LPAREN expression RPAREN statement                                                 #stat_if
    | IF LPAREN expression RPAREN statement ELSE statement                                  #stat_if_else
    | WHILE LPAREN expression RPAREN statement                                              #stat_while
    | PRINTLN LPAREN ID RPAREN SEMICOLON                                                    #stat_println
    | RETURN expression SEMICOLON                                                           #stat_return
    ;

expression_statement
    : SEMICOLON                                 #expr_end
    | expression SEMICOLON                      #expr_with_expr
    | expression ADDOP ASSIGNOP expression      #expr_assign_addop
    ;

variable
    : ID                                #var_id
    | ID LTHIRD expression RTHIRD       #var_arr
    ;

expression
    : logic_expression                      #expr_logic
    | variable ASSIGNOP logic_expression    #expr_assign
    ;

logic_expression
    : rel_expression                            #logic_rel
    | rel_expression LOGICOP rel_expression     #logic_op
    ;

rel_expression
    : simple_expression                            #rel_simple
    | simple_expression RELOP simple_expression    #rel_op
    ;

simple_expression
    : term                                          #simp_term
    | simple_expression ADDOP term                  #simp_addop
    ;

term
    : unary_expression                              #term_unary
    | term MULOP unary_expression                   #term_mulop
    ;

unary_expression
    : ADDOP unary_expression                        #unary_addop
    | NOT unary_expression                          #unary_not
    | factor                                        #unary_factor
    ;

factor
    : variable                                      #factor_var
    | ID LPAREN argument_list RPAREN                #factor_func_call
    | LPAREN expression RPAREN                      #factor_paren
    | CONST_INT                                     #factor_int
    | CONST_FLOAT                                   #factor_float
    | variable INCOP                                #factor_inc
    | variable DECOP                                #factor_dec
    ;

argument_list
    : arguments                                     #arg_list
    |                                               #arg_list_empty
    ;

arguments
    : arguments COMMA logic_expression              #args_multi
    | logic_expression                              #args_single
    ;
