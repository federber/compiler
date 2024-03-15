%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *str)
{
        fprintf(stderr,"ошибка: %s\n",str);
}
int yywrap()
{
        return 1;
} 
main()
{
        yyparse();
} 
%}

%token NUMBER IDENTIFIER CONDTOK IFTOK ELSETOK LOOPTOK TYPETOK DOT COMMA COLON SEMICOLON LCBRACE RCBRACE LFBRACE RFBRACE LRBRACE RRBRACE FNDECL VARDECL ASSIGNMENT
%%

commands: /* empty */
        | commands command
        ;

command:
        var_declaration
        |
        func_declaration
        ;
var_declaration:
	VARDECL IDENTIFIER ASSIGNMENT NUMBER SEMICOLON
	{
		printf("variable declared with number \n");
	}
	VARDECL IDENTIFIER ASSIGNMENT IDENTIFIER SEMICOLON
	{
		printf("variable declared with identifier \n");
	};
func_declaration:
	FNDECL IDENTIFIER
	{printf("fndecl");};

%%
