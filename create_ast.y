/* file: 3.02_create_AST_with_bison.y */


%{
#include <stdio.h>
#include <string.h>
#include "ast_str.h"
extern "C" int yylex();
void yyerror(const char *str)
{
    fprintf(stderr,"ошибка: %s\n",str);
}
int yywrap()
{
    return 1;
}

%}

%union {
    AST_base *a;
    char* d;
}
%token <d> NUMBER IDENTIFIER
//%token <a> ASSIGNMENT
%token VARDECL


%token EOL

%type <a> exp factor term var_declaration assign calclist// commands command


%%
/*
commands:
        | commands command
        ;
command:
        | var_declaration
        ;
*/
var_declaration: VARDECL assign ';' EOL
    {
        printf("variable declared with calclist \n");
        $$ = newast(NT_VARDECL,{$2});
    }
    ;

assign:
    |  IDENTIFIER '=' calclist
    {
        std::cout << "Assign command:\n";
        std::cout << "identifier:   " << $1 <<std::endl;
        AST_leaf* a = newleaf(NT_IDENT, $1);
        $$ = newast(NT_ASSIGN, std::vector<AST_base*>{a,$3});
    }
    ;

calclist:
    | calclist exp
    {
        std::cout << "Calclist command:\n";
        $$ = newast(NT_CALCLIST, std::vector<AST_base*>{$2});
    }
    | calclist { printf("> "); } /* Blank line or comment */
    ;

exp: factor
    | exp '+' factor {std::cout << "plus\n"; $$ = newast(NT_ADD, {$1, $3}); }
    | exp '-' factor { $$ = newast(NT_SUB, {$1, $3}); }
    ;

factor: term
    | factor '*' term { $$ = newast(NT_MUL, {$1, $3}); }
    | factor '/' term { $$ = newast(NT_DIV, {$1, $3}); }
    ;

term: NUMBER { printf("NT_NUM\n"); $$ = newleaf(NT_NUM, $1); std::cout << $1 << std::endl;}
/*  | IDENTIFIER'('init_list')' {}*/
    | IDENTIFIER { printf("NT_IDENT\n"); $$ = newleaf(NT_IDENT, $1); std::cout << $1 << std::endl;}
    | '|' exp '|' { $$ = newast(NT_ABS, {$2, NULL}); }     // Syntax rules for using absolute value symbols
    | '(' exp ')' { $$ = $2; }                           // Use parentheses syntax rules
    | '-' term    { $$ = newast(NT_NEG, {$2, NULL}); }     // Rules for using negative signs
    ;
/*
init_list: calclist {}
    | init_list','init_list'{}
    | init_list', 'init_list{}
*/
%%
