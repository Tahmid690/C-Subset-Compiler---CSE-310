%option noyywrap
%x STR
%x CHARC
%x SLCOMMENT
%x MLCOMMENT


%{

#include<bits/stdc++.h>
#include "2205009_SymbolInfo.h"
#include "2205009_ScopeTable.h"
#include "2205009_SymbolTable.h"
using namespace std;

int line_count = 1;
int error_count = 0;

ofstream logout;
ofstream tokenout;

string lexbuf;
string rawbuf;
int tokStartLine; 

SymbolTable* st;

void printToken(const string &type, const string &lexeme){
    tokenout << "<" << type << ", " << lexeme << "> ";
    logout << "Line no " << line_count << ": Token <" << type << "> Lexeme " ;
    
    if(type == "STRING") logout << "\"";
    logout << lexeme;
    if(type == "STRING") logout << "\"";
    logout << " found";
    if(type == "STRING"){
        logout << " --> <" << type << ", " << lexeme << ">"; 
    }
    logout << endl << endl;
}

void printCharToken(const string &yytext_str, const string &char_val){
    tokenout << "<CONST_CHAR, " << char_val << "> ";
    logout << "Line no " << tokStartLine 
           << ": Token <CONST_CHAR> Lexeme " << yytext_str 
           << " found --> <CONST_CHAR, " << char_val << ">" << endl << endl;
}

void printStringToken(const string &raw_str, const string &val_str){
    tokenout << "<STRING, " << val_str << "> ";
    logout << "Line no " << line_count 
           << ": Token <STRING> Lexeme " << raw_str 
           << " found --> <STRING, " << val_str << ">" << endl << endl;
}


void printSoloToken(const string &type, const string &lexeme){
    tokenout << "<" << type << "> ";
    logout << "Line no " << line_count << ": Token <" << type << "> Lexeme " << lexeme << " found" << endl << endl;
}

void logComment(const string &lexeme, int startLine){
    logout << "Line no " << startLine << ": Token <COMMENT> Lexeme " << lexeme << " found" << endl << endl;
}

void reportError(const string &msg, int atLine){
    error_count++;
    logout << "Error at line no " << atLine << ": " << msg << endl << endl;
    
}

void insertIdentifier(string name,string type){    
    SymbolInfo* r = new SymbolInfo(name, type);
    int idx, pos; string scope_id;
    if(st->insert(r, idx, pos, scope_id)){
        // logout << "\tInserted in ScopeTable# " << scope_id << " at position " << idx+1 << ", " << pos+1 << endl;
        st->printAll(logout);
        logout << endl;
    }
    else{
        r->printSymbolInfo(logout);
        st->lookup(name, idx, pos, scope_id);
        logout << " already exists in ScopeTable# " << scope_id << " at position " << idx << ", " << pos << endl << endl;
        delete r; 
    }
}


%}


DIGIT   [0-9]
LETTER  [a-zA-Z_]
ALNUM   [a-zA-Z0-9_]
ID      {LETTER}{ALNUM}*

FLOAT1  {DIGIT}*"."{DIGIT}+((E|e)[+-]?{DIGIT}+)?
FLOAT2  {DIGIT}+"."((E|e)[+-]?{DIGIT}+)?
FLOAT3  {DIGIT}+(E|e)[+-]?{DIGIT}+
TOOMANYDOT {DIGIT}*("."{DIGIT}*){2,}
ILLFORMED  {DIGIT}+(E|e)[+-]?{DIGIT}+"."{DIGIT}+
NUMERR  {DIGIT}({ALNUM}|"."|(E|e)[+-]?)*

%%

"if"        { printSoloToken("IF", yytext); }
"else"      { printSoloToken("ELSE", yytext); }
"goto"      { printSoloToken("GOTO", yytext); }
"for"       { printSoloToken("FOR", yytext); }
"while"     { printSoloToken("WHILE", yytext); }
"long"      { printSoloToken("LONG", yytext); }
"do"        { printSoloToken("DO", yytext); }
"break"     { printSoloToken("BREAK", yytext); }
"int"       { printSoloToken("INT", yytext); }
"char"      { printSoloToken("CHAR", yytext); }
"static"    { printSoloToken("STATIC", yytext); }
"float"     { printSoloToken("FLOAT", yytext); }
"double"    { printSoloToken("DOUBLE", yytext); }
"unsigned"  { printSoloToken("UNSIGNED", yytext); }
"void"      { printSoloToken("VOID", yytext); }
"return"    { printSoloToken("RETURN", yytext); }
"switch"    { printSoloToken("SWITCH", yytext); }
"case"      { printSoloToken("CASE", yytext); }
"default"   { printSoloToken("DEFAULT", yytext); }
"continue"  { printSoloToken("CONTINUE", yytext); }
"short"     { printSoloToken("SHORT", yytext); }

{FLOAT1}    {
                printToken("CONST_FLOAT", yytext);
                insertIdentifier(yytext,"CONST_FLOAT");    
            }
{FLOAT2}    {
                printToken("CONST_FLOAT", yytext);
                insertIdentifier(yytext,"CONST_FLOAT");    
            }
{FLOAT3}    {
                printToken("CONST_FLOAT", yytext);
                insertIdentifier(yytext,"CONST_FLOAT");    
            }
{TOOMANYDOT} { reportError(string("Too many decimal points ") + yytext, line_count); logout << endl;}
{ILLFORMED}  { reportError(string("Ill formed number ") + yytext, line_count); logout << endl;}
{DIGIT}+    {
                printToken("CONST_INT", yytext);
                insertIdentifier(yytext,"CONST_INT");    
            }
{NUMERR}    { reportError(string("Invalid prefix on ID or invalid suffix on Number ") + yytext, line_count); }



"++"        { printToken("INCOP", yytext); }
"--"        { printToken("INCOP", yytext); }
"+"         { printToken("ADDOP", yytext); }
"-"         { printToken("ADDOP", yytext); }
"*"         { printToken("MULOP", yytext); }
"/"         { printToken("MULOP", yytext); }
"%"         { printToken("MULOP", yytext); }
"<="        { printToken("RELOP", yytext); }
">="        { printToken("RELOP", yytext); }
"=="        { printToken("RELOP", yytext); }
"!="        { printToken("RELOP", yytext); }
"<"         { printToken("RELOP", yytext); }
">"         { printToken("RELOP", yytext); }
"="         { printToken("ASSIGNOP", yytext); }
"&&"        { printToken("LOGICOP", yytext); }
"||"        { printToken("LOGICOP", yytext); }
"!"         { printToken("NOT", yytext); }
"("         { printToken("LPAREN", yytext); }
")"         { printToken("RPAREN", yytext); }
"{"         { printToken("LCURL", yytext); st->enterScope(); }
"}"         {
                printToken("RCURL", yytext);
                if(st->getCurrentScope()->getParentScope() != NULL) st->exitScope();
            }
"["         { printToken("LTHIRD", yytext); }
"]"         { printToken("RTHIRD", yytext); }
","         { printToken("COMMA", yytext); }
";"         { printToken("SEMICOLON", yytext); }

{ID}        {
                printToken("ID", yytext);
                insertIdentifier(yytext,"ID");
            }

\'          { lexbuf.clear(); rawbuf = "'"; tokStartLine = line_count; BEGIN(CHARC); }


<CHARC>{
    \\n  { lexbuf += '\n'; rawbuf += "\\n"; }
    \\t  { lexbuf += '\t'; rawbuf += "\\t"; }
    \\\\ { lexbuf += '\\'; rawbuf += "\\\\"; }
    \\\' { lexbuf += '\''; rawbuf += "\\'"; }
    \\a  { lexbuf += '\a'; rawbuf += "\\a"; }
    \\f  { lexbuf += '\f'; rawbuf += "\\f"; }
    \\r  { lexbuf += '\r'; rawbuf += "\\r"; }
    \\b  { lexbuf += '\b'; rawbuf += "\\b"; }
    \\v  { lexbuf += '\v'; rawbuf += "\\v"; }
    \\0  { lexbuf += '\0'; rawbuf += "\\0"; }
    \'   {
            rawbuf += "'"; 
            BEGIN(INITIAL);
            if(lexbuf.size() == 0){
                reportError("Empty character constant error " + rawbuf, tokStartLine);
                logout << endl;
            }
            else if(lexbuf.size() > 1){
                reportError("Multi character constant error " + rawbuf, tokStartLine);
                logout << endl;
            }
            else{
                int savedLine = line_count;
                line_count = tokStartLine;
                printCharToken(rawbuf, lexbuf);
                insertIdentifier(rawbuf, "CONST_CHAR");
                line_count = savedLine;
            }
         }
    \n   {
            reportError("Unterminated character " + rawbuf, tokStartLine);
            logout << endl;
            line_count++;
            BEGIN(INITIAL);
         }
    .    { lexbuf += yytext[0]; rawbuf += yytext[0]; }
    <<EOF>> {
            reportError(string("Unterminated character '") + lexbuf, tokStartLine);
            logout << endl;
            BEGIN(INITIAL);
         }
}


\"        { lexbuf.clear(); rawbuf = "\""; tokStartLine = line_count; BEGIN(STR); }

<STR>{
    \\n   { lexbuf += '\n'; rawbuf += "\\n"; }
    \\t   { lexbuf += '\t'; rawbuf += "\\t"; }
    \\\\  { lexbuf += '\\'; rawbuf += "\\\\"; }
    \\\"  { lexbuf += '\"'; rawbuf += "\\\""; }
    \\a   { lexbuf += '\a'; rawbuf += "\\a"; }
    \\f   { lexbuf += '\f'; rawbuf += "\\f"; }
    \\r   { lexbuf += '\r'; rawbuf += "\\r"; }
    \\b   { lexbuf += '\b'; rawbuf += "\\b"; }
    \\v   { lexbuf += '\v'; rawbuf += "\\v"; }
    \\0   { lexbuf += '\0'; rawbuf += "\\0"; }
    \\\n  { rawbuf += "\\\n"; line_count++; }
    \"    {
             rawbuf += "\"";
             BEGIN(INITIAL);
             printStringToken(rawbuf, lexbuf);
            //  insertIdentifier(lexbuf,"STRING");
          }
    \n    {
             reportError("Unterminated string " + rawbuf, tokStartLine);
             line_count++;
             BEGIN(INITIAL);
          }
    .     { lexbuf += yytext[0]; rawbuf += yytext[0]; }
    <<EOF>> {
             reportError("Unterminated string \"" + rawbuf, tokStartLine);
             BEGIN(INITIAL);
          }
}



"//"        { lexbuf = "//"; tokStartLine = line_count; BEGIN(SLCOMMENT); }
<SLCOMMENT>{
    \\\n    { lexbuf += "\\\n"; line_count++; }
    \n      { logComment(lexbuf, line_count); line_count++; BEGIN(INITIAL); }
    .       { lexbuf += yytext[0]; }
    <<EOF>> { logComment(lexbuf, line_count); BEGIN(INITIAL); }
}


"/*"        { lexbuf = "/*"; tokStartLine = line_count; BEGIN(MLCOMMENT); }
<MLCOMMENT>{
    "*/"    { lexbuf += "*/"; logComment(lexbuf, line_count); BEGIN(INITIAL); }
    \n      { lexbuf += '\n'; line_count++; }
    .       { lexbuf += yytext[0]; }
    <<EOF>> { reportError("Unterminated comment " + lexbuf, tokStartLine); BEGIN(INITIAL); }
}

\n          { line_count++; }

[ \t\r]+    { }

.           { reportError(string("Unrecognized character ") + yytext, line_count); }


%%


int main(int argc, char *argv[]){
    if(argc < 2){
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL){
        cout << "Cannot open input file " << argv[1] << endl;
        return 1;
    }

    string base = "2205009";
    tokenout.open(base + "_token.txt");
    logout.open(base + "_log.txt");

    st = new SymbolTable(7);

    yylex();

    st->printAll(logout);

    logout << endl << "Total lines: " << line_count << endl;
    logout << "Total errors: " << error_count << endl;

    delete st;
    tokenout.close();
    logout.close();
    fclose(yyin);
    return 0;
}
