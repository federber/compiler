%option noyywrap

%{
#include "ast_str.h"
#include "create_ast.tab.h"
extern "C" int yylex();
%}

EXP ([Ee][-+]?[0-9]+)




identif [_a-zA-Z][_a-zA-Z0-9]*
loops "for"|"while"
types "i8"|"u8"|"i16"|"u16"|"i32"|"u32"|"i64"|"u64"|"i128"|"u128"|"isize"|"usize"|"f32"|"f64"|"bool"|"char"


%%
"+" |
"-" |
"*" |
"/" |
"|" |
"(" |
";" |
"{" |
"}" |
")" { return yytext[0]; }

[0-9]+ {
        char* ch1 = (char*)malloc(strlen(yytext) * sizeof(char));
        strncpy(ch1, yytext, strlen(yytext));
        yylval.d = ch1; return NUMBER;
       }

let			{
                printf("LET\n");
                //yylval.d = yytext;
                return VARDECL;
            }
"if"        {
                return IFTOK;
            }
"else"      {
                return ELSETOK;
            }



[_a-zA-Z][_a-zA-Z0-9]*	{
                printf("IDENTIFIER\n");
                char* ch1 = (char*)malloc(strlen(yytext) * sizeof(char));
                strncpy(ch1, yytext, strlen(yytext));
                yylval.d = ch1;
                std::cout << "ident:  " << yylval.d << std::endl;
                return IDENTIFIER;
            }


"="   		{
                printf("ASSIGNMENT\n");
                yylval.d=yytext;
                return yytext[0];
            }

"\n"      { std::cout << "EOL\n" << std::endl; return EOL; }
[ \t]+			/*ignored*/;
%%
