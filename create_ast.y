/* file: 3.02_create_AST_with_bison.y */


%{
#include <stdio.h>
#include <string.h>
#include "ast_str.h"
#include<iostream>
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
%token VARDECL IFTOK ELSETOK


%token EOL

%type <a> exp factor term var_declaration assign commands

//%start commands
%%


var_declaration: VARDECL assign ';' EOL
    {
        printf("variable declared with calclist \n");
        $$ = newast(NT_VARDECL,{$2});
        std::cout << *(AST_node*)$$;
    }
    | VARDECL IDENTIFIER ';' EOL
    {
        AST_leaf* a = newleaf(NT_IDENT, $2);
        $$ = newast(NT_VARDECL, {a});
    }

    ;

assign: IDENTIFIER '=' exp
    {
        std::cout << "Assign command:\n";
        std::cout << $1 << std::endl;
        //char* ch1 = (char*)malloc($3-$1) * sizeof(char));
        //char* ch3 = (char*)malloc((strlen($3) - strlen($5) - 1) * sizeof(char));
        //strncpy(ch1, $1, strlen($1) - strlen($3) - 1);
        //strncpy(ch3, $3, strlen($3) - strlen($5) - 1);

       // std::cout << "identifier_1: " << ch1 << std::endl;
        //std::cout << "identifier_2: " << ch3 << std::endl;
        //std::cout << "identifier_3: " << $5 << std::endl;

        AST_leaf* a = newleaf(NT_IDENT, $1);
        //AST_leaf* b = newleaf(NT_IDENT, ch3);

        $$ = newast(NT_ASSIGN, std::vector<AST_base*>{a,$3});
    }
    ;
/*
calclist:
    calclist exp
    {
        std::cout << "Calclist command:\n";
        //std::cout << *(AST_leaf*)$2 << std::endl;
        $$ = $1;//newast(NT_CALCLIST, std::vector<AST_base*>{$1, $2});
    }
    ;
*/
exp: factor {$$ = $1;}
    | exp '+' factor {std::cout << "plus\n"; $$ = newast(NT_ADD, {$1, $3}); }
    | exp '-' factor { $$ = newast(NT_SUB, {$1, $3}); }
    ;

factor: term {$$ = $1; std::cout << "TERM\n";}
    | factor '*' term { $$ = newast(NT_MUL, {$1, $3}); }
    | factor '/' term { $$ = newast(NT_DIV, {$1, $3}); }
    ;

term: NUMBER {
                printf("NT_NUM\n");
                //char* ch1 = (char*)malloc(strlen($1) * sizeof(char));
                //strncpy(ch1, $1, strlen($1));
                $$ = newleaf(NT_NUM, $1);
                //$1 = NULL;
             }
    | IDENTIFIER {
                    printf("NT_IDENT\n");
                    //char* ch1 = (char*)malloc(strlen($1) * sizeof(char));
                    //strncpy(ch1, $1, strlen($1));
                    $$ = newleaf(NT_IDENT, $1);
                    //$1 = NULL;
                 }
    | '|' exp '|' { $$ = newast(NT_ABS, {$2}); }     // Syntax rules for using absolute value symbols
    | '(' exp ')' { $$ = $2; }                           // Use parentheses syntax rules
    | '-' term    { $$ = newast(NT_NEG, {$2}); }     // Rules for using negative signs
    ;

/*
init_list: calclist {}
    | init_list','init_list'{}
    | init_list', 'init_list{}
*/
%%
