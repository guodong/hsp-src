%{
  #include "node.h"
  #include <stdio.h>
  #include <vector>
  #include <string>
  NBlock* programBlock;
  extern FILE *yyin;
  extern int yylex();
  void yyerror(const char* s) {
    fprintf(stderr, "yyerror: %s\n", s);
  }
%}

%error-verbose

%union {
  NBlock* block;
  NStatement* stmt;
  NExpression* expr;
  NIdentifier* ident;
  NVariableDeclaration* var_decl;
  std::vector<NVariableDeclaration*>* varvec;
  std::vector<NExpression*>* exprvec;
  std::string* string;
  int token;
  int binary_token;
  int primary_type;
}
%token <string> TIDENTIFIER TINTEGER TIP TMAC
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TEQUAL TIF TELSE TDOT TRETURN
%token <primary_type> TINT
%token <binary_token> TCEQ TCLT TCLE TCGT TCGE
%type <ident> ident
%type <block> program stmts block
%type <stmt> stmt if_stmt var_decl
%type <expr> expr
%type <token> binary
%start program

%%

program : stmts {programBlock = $1; }
;

stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
| stmts stmt { $1->statements.push_back($<stmt>2); }
;

stmt : var_decl
| if_stmt
| expr
;

var_decl : ident ident { $$ = new NVariableDeclaration(*$1, *$2); }
;

ident : TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
;

block : TLBRACE stmts TRBRACE { $$ = $2; }
| TLBRACE TRBRACE { $$ = new NBlock(); }
;

if_stmt : TIF expr block { $$ = new NIfStatement(*$2, *$3); }
| TIF expr block TELSE block { $$ = new NIfStatement(*$2, *$3, *$5); }
| TIF expr block TELSE if_stmt
;

expr : TINTEGER { $$ = new NInteger(atol($1->c_str())); }
| ident { $<ident>$ = $1; }
| TLPAREN expr TRPAREN { $$ = $2; }
| ident TEQUAL expr { $$ = new NAssignment(*$<ident>1, *$3); }
| expr binary expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
;

binary : TCEQ
;



%%
