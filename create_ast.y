%{
#include <stdio.h>
#include <string.h>
#include "ast_str.h"
#include<iostream>
#include <math.h>
extern "C" int yylex();
extern AST_base* last_node;
%}

%union {
    AST_base *a;
    char* d;
}
%token <d> NUMBER IDENTIFIER DATA_TYPE COMPARE_TOK LOOP_TOK
%token VARDECL IFTOK ELSETOK FNDECL IN_TOK

%type <a> exp factor term var_declaration assign if_else condition commands init_list fn_decl var_type fn_call IL_conc loop interv in_interv


%%

commands:
    if_else
    {
        //std::cout << std::endl << "IFELS_zero" << std::endl;
        $$ = $1;
        last_node = $$;
    }
    | if_else commands
    {
        //std::cout << "IFELSE_COMMA" << std::endl;
        ((AST_node*)$1)->next = $2;
        //std::cout << "NEXT: \n" << *(AST_node*)(((AST_node*)$1)->next) << std::endl;
        ((AST_node*)$2)->prev = $1; $$ = $1;
        last_node = $$;
    }
    | var_declaration commands
    {
        //std::cout << "var_decl commands" << std::endl;
        ((AST_node*)$1)->next = $2;
        //std::cout << "NEXT: \n" << *(AST_node*)(((AST_node*)$1)->next) << std::endl;
        ((AST_node*)$2)->prev = $1; $$ = $1;
        last_node = $$;
    }
    | var_declaration
    {
        //std::cout << "c _ VAR DECL\n" << std::endl;
        $$ = $1;
        last_node = $$;
    }
    | fn_decl
    {
        $$ = $1;
        last_node = $$;
    }
    | fn_decl commands
    {
        ((AST_node*)$1)->next = $2;
        ((AST_node*)$2)->prev = $1;
        $$ = $1;
        last_node = $$;
    }
    | fn_call ';'
    {
        $$ = $1;
        last_node = $$;
    }
    | assign ';'
    {
        //printf("ASSIGN\n");
        $$ = $1;
        last_node = $$;
    }
    | assign ';' commands
    {
        //printf("ASSIGN_COMMANDS\n");
        ((AST_node*)$1)->next = $3;
        ((AST_node*)$3)->prev = $1;
        $$ = $1;
        last_node = $$;
    }
    | fn_call ';' commands
    {
        ((AST_node*)$1)->next = $3;
        ((AST_node*)$3)->prev = $1;
        $$ = $1;
        last_node = $$;
    }
    | loop
    {
        $$ = $1;
        last_node = $$;
    }
    | loop commands
    {
        ((AST_node*)$1)->next = $2;
        ((AST_node*)$2)->prev = $1;
        $$ = $1;
        last_node = $$;
    }


fn_call: IDENTIFIER '(' init_list ')'
    {
        auto a = newleaf(NT_IDENT, $1);
        $$ = newast(NT_FN_CALL, {a, $3});
    }
fn_decl: FNDECL IDENTIFIER '(' IL_conc ')' ';'
    {
        //printf("FNDECL wtht commands\n");
        auto a = newleaf(NT_IDENT, $2);
        auto b = newast(NT_NULL, {});
        $$ = newast(NT_FNDECL,{a, $4, b});

    }
    | FNDECL IDENTIFIER '(' init_list ')' '{' commands '}'
    {
        //printf("FNDECL\n");
        auto a = newleaf(NT_IDENT, $2);
        $$ = newast(NT_FNDECL,{a, $4, $7});
        ((AST_node*)$7)->prev = $$; // см. readme


    }
var_type: IDENTIFIER ':' DATA_TYPE
    {
        auto a = newleaf(NT_IDENT, $1);
        auto b = newleaf(NT_DATA_TYPE, $3);
        $$ = newast(NT_TYPED_VAR, {a,b});
    }
IL_conc: {$$ = newast(NT_NULL,{});}
    | var_type {$$ = newast(NT_IL_conc, {$1});}
    | var_type ',' IL_conc
    {
        printf("ident + inlist in INITLIST\n");
        std::vector<AST_base*> vec = {$1};
        vec.insert(vec.end(),(((AST_node*)$3)->subtrees).begin(), (((AST_node*)$3)->subtrees).end());
        $$ = newast(NT_IL_conc, vec);
    }
init_list: {$$ = newast(NT_NULL,{});}
    | assign {$$ = newast(NT_INIT_LIST, {$1});}
    | assign ',' init_list
    {
        std::vector<AST_base*> vec = {$1};
        vec.insert(vec.end(),(((AST_node*)$3)->subtrees).begin(), (((AST_node*)$3)->subtrees).end());
        $$ = newast(NT_INIT_LIST, vec);
    }
    | exp {$$ = newast(NT_INIT_LIST, {$1});}
    | exp ',' init_list
    {
        std::vector<AST_base*> vec = {$1};
        vec.insert(vec.end(),(((AST_node*)$3)->subtrees).begin(), (((AST_node*)$3)->subtrees).end());
        $$ = newast(NT_INIT_LIST, vec);
    }


if_else: IFTOK condition '{' commands '}'
    {
        auto b = newast(NT_NULL, {});
        $$ = newast(NT_IFELSE, {$2, $4, b});
        ((AST_node*)$4)->prev = $$; // см. readme
       // printf("IFELSE\n");
    }
    | IFTOK condition '{' commands '}' ELSETOK '{' commands '}'
    {
        //printf("IFELSE_WITH_ELSE\n");
        $$ = newast(NT_IFELSE, {$2, $4, $8});
        ((AST_node*)$4)->prev = $$;
        ((AST_node*)$8)->prev = $$;


    }
loop: LOOP_TOK condition '{' commands '}'
    {
       // printf("LOOP\n");
        auto a = newleaf(NT_IDENT,$1);
        $$ = newast(NT_LOOP, {a,$2,$4});
        ((AST_node*)$4)->prev = $$;

    }
    | LOOP_TOK in_interv '{' commands '}'
    {
        auto a = newleaf(NT_IDENT,$1);
        $$ = newast(NT_LOOP, {a,$2,$4});
        ((AST_node*)$4)->prev = $$;
    }

condition: exp COMPARE_TOK exp
    {
        char* ch1 = (char*)malloc(strlen($2) * sizeof(char));
        strncpy(ch1, $2, strlen($2));
        auto a = newleaf(NT_COMPARE, ch1);
        $$ = newast(NT_COND, {a, $1, $3});
    }
interv: exp '.''.' exp
    {
        $$ = newast(NT_INTERV,{$1,$4});
    }
in_interv: exp IN_TOK interv
    {
        $$ = newast(NT_ININT,{$1,$3});
    }

var_declaration: VARDECL assign ';'
    {
        //printf("variable declared \n");
        $$ = newast(NT_VARDECL,{$2});
    }
    | VARDECL IDENTIFIER ';'
    {
        AST_leaf* a = newleaf(NT_IDENT, $2);
        $$ = newast(NT_VARDECL, {a});
    }

    ;

assign: IDENTIFIER '=' exp
    {
        char* ch1 = (char*)calloc(strlen($1), sizeof(char));
        strncpy(ch1, $1, strlen($1));
        AST_leaf* a = newleaf(NT_IDENT, ch1);

        $$ = newast(NT_ASSIGN, std::vector<AST_base*>{a,$3});
    }
    ;
exp: factor {$$ = $1;}
    | exp '+' factor { $$ = newast(NT_ADD, {$1, $3}); }
    | exp '-' factor { $$ = newast(NT_SUB, {$1, $3}); }
    ;

factor: term {$$ = $1;}
    | factor '*' term { $$ = newast(NT_MUL, {$1, $3}); }
    | factor '/' term { $$ = newast(NT_DIV, {$1, $3}); }
    ;

term: NUMBER
    {
        //printf("NT_NUM\n");
        char* ch1 = (char*)malloc(strlen($1) * sizeof(char));
        strncpy(ch1, $1, strlen($1));
        $$ = newleaf(NT_NUM, $1);
    }
    | IDENTIFIER
    {
        // printf("NT_IDENT\n");
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
