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
%token <d> NUMBER IDENTIFIER DATA_TYPE COMPARE_TOK LOOP_TOK
//%token <a> ASSIGNMENT
%token VARDECL IFTOK ELSETOK FNDECL


%token EOL END

%type <a> exp factor term var_declaration assign if_else condition commands init_list fn_decl var_type fn_call IL_conc loop

//%start commands
%%

commands:
    if_else{ $$ = $1; }
    | if_else commands { ((AST_node*)$2)->subtrees[0] = $1; $$ = $1; }
    | var_declaration commands { std::cout << "var_decl commands" << std::endl; ((AST_node*)$2)->subtrees[0] = $1; $$ = $1; std::cout << *(AST_node*)$$ << *(AST_node*)$2; }
    | var_declaration{ std::cout << "c _ VAR DECL" << std::endl; $$ = $1; }
    | fn_decl { $$ = $1; }
    | fn_decl commands { ((AST_node*)$2)->subtrees[0] = $1; }
    | commands END { std::cout << "COMMANDS END" << std::endl; $$ = $1; }
    | fn_call ';' { $$ = $1; }
    | assign ';' { $$ = $1; }
    | assign ';' commands { ((AST_node*)$3)->subtrees[0] = $1; $$ = $1; }
    | fn_call ';' commands { ((AST_node*)$3)->subtrees[0] = $1; $$ = $1; }
    | loop {$$ = $1; }
    | loop commands { ((AST_node*)$2)->subtrees[0] = $1; $$ = $1; }

fn_call: IDENTIFIER '(' init_list ')'
    {
        auto a = newleaf(NT_IDENT, $1);
        std::vector<AST_base*> vec = {a};
        vec.insert(vec.end(),(((AST_node*)$3)->subtrees).begin(), (((AST_node*)$3)->subtrees).end());
        $$ = newast(NT_FN_CALL, vec);
    }
fn_decl: FNDECL IDENTIFIER '(' IL_conc ')' ';'
    {
        printf("FNDECL wtht commands\n");
        auto a = newleaf(NT_IDENT, $2);
        auto b = newast(NT_NULL, {});
        $$ = newast(NT_FNDECL,{nullptr,a, $4, b});
    }
    | FNDECL IDENTIFIER '(' init_list ')' '{' commands '}'
    {
        printf("FNDECL\n");
        auto a = newleaf(NT_IDENT, $2);
        $$ = newast(NT_FNDECL,{nullptr,a, $4, $7});
    }
var_type: IDENTIFIER ':' DATA_TYPE
    {
        auto a = newleaf(NT_IDENT, $1);
        auto b = newleaf(NT_DATA_TYPE, $3);
        $$ = newast(NT_TYPED_VAR, {nullptr,a,b});
    }
IL_conc: {$$ = newast(NT_NULL,{});}
    | var_type {$$ = newast(NT_IL_conc, {nullptr,$1});}
    | var_type ',' IL_conc
    {
        printf("ident + inlist in INITLIST\n");
        std::vector<AST_base*> vec = {nullptr,$1};
        vec.insert(vec.end(),(((AST_node*)$3)->subtrees).begin()+1, (((AST_node*)$3)->subtrees).end());
        $$ = newast(NT_IL_conc, vec);
    }
init_list: {$$ = newast(NT_NULL,{});}
    | assign {$$ = newast(NT_INIT_LIST, {$1});}
    | assign ',' init_list
    {
        std::vector<AST_base*> vec = {nullptr,$1};
        vec.insert(vec.end(),(((AST_node*)$3)->subtrees).begin()+1, (((AST_node*)$3)->subtrees).end());
        $$ = newast(NT_INIT_LIST, vec);
    }
    | exp {$$ = newast(NT_INIT_LIST, {nullptr,$1});}
    | exp ',' init_list
    {
        std::vector<AST_base*> vec = {nullptr,$1};
        vec.insert(vec.end(),(((AST_node*)$3)->subtrees).begin()+1, (((AST_node*)$3)->subtrees).end());
        $$ = newast(NT_INIT_LIST, vec);
    }


if_else: IFTOK condition '{' commands '}'
    {
        auto b = newast(NT_NULL, {});
        $$ = newast(NT_IFELSE, {nullptr,$2, $4, b});
        printf("IFELSE\n");
    }
    | IFTOK condition '{' commands '}' ELSETOK '{' commands '}'
    {
        printf("IFELSE_WITH_ELSE\n");
        $$ = newast(NT_IFELSE, {nullptr,$2, $4, $8});
    }
loop: LOOP_TOK condition '{' commands '}'
    {
        printf("LOOP\n");
        auto a = newleaf(NT_IDENT,$1);
        $$ = newast(NT_LOOP, {nullptr,a,$2,$4});
    }

condition: exp COMPARE_TOK exp
    {
        auto a = newleaf(NT_COMPARE, $2);
        $$ = newast(NT_COND, {nullptr,a, $1, $3});
    }

var_declaration: VARDECL assign ';'
    {
        printf("variable declared with calclist \n");
        $$ = newast(NT_VARDECL,{nullptr, $2});
        std::cout << *(AST_node*)$$;
    }
    | VARDECL IDENTIFIER ';'
    {
        AST_leaf* a = newleaf(NT_IDENT, $2);
        $$ = newast(NT_VARDECL, {nullptr, a});
    }

    ;

assign: IDENTIFIER '=' exp
    {
        std::cout << "Assign command:\n";
        char* ch1 = (char*)calloc(strlen($1), sizeof(char));
        strncpy(ch1, $1, strlen($1));
        std::cout << ch1 << std::endl;
        AST_leaf* a = newleaf(NT_IDENT, ch1);

        $$ = newast(NT_ASSIGN, std::vector<AST_base*>{nullptr,a,$3});
    }
    ;
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
                char* ch1 = (char*)malloc(strlen($1) * sizeof(char));
                strncpy(ch1, $1, strlen($1));
                $$ = newleaf(NT_NUM, $1);
             }
    | IDENTIFIER {
                    printf("NT_IDENT\n");
                    char* ch1 = (char*)calloc(strlen($1), sizeof(char));
                    strncpy(ch1, $1, strlen($1));
                    $$ = newleaf(NT_IDENT, ch1);
                 }
    | '|' exp '|' { $$ = newast(NT_ABS, {$2}); }     // Syntax rules for using absolute value symbols
    | '(' exp ')' { $$ = $2; }                           // Use parentheses syntax rules
    | '-' term    { $$ = newast(NT_NEG, {$2}); }     // Rules for using negative signs
    | '!' exp     { $$ = newast(NT_NOT, {$2});}
    | fn_call     { $$ = $1; }
    ;

%%
