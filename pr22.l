%{
#include <stdio.h>
#include "pr22.tab.h"
%}

identifier [_a-zA-Z][_a-zA-Z0-9]*
loops "for"|"while"
types "i8"|"u8"|"i16"|"u16"|"i32"|"u32"|"i64"|"u64"|"i128"|"u128"|"isize"|"usize"|"f32"|"f64"|"bool"|"char"

%%
[0-9]+                  {
				yylval = yytext;
				return NUMBER;
			}

let			{
				yylval = yytext;
				return VARDECL;
			}
fn			{
				yylval = yytext;
				return FNDECL;
			}
":"			yylval = yytext; return COLON;
"."			yylval = yytext; return DOT;
","			yylval = yytext; return COMMA;
";"			yylval = yytext; return SEMICOLON;



"("			yylval = yytext; return LCBRACE;
")"			yylval = yytext; return RCBRACE;

"{"			yylval = yytext; return LFBRACE;
"}"			yylval = yytext; return RFBRACE;

"["			yylval = yytext; return LRBRACE;
"]"			yylval = yytext; return RRBRACE;

if			yylval = yytext; return CONDTOK;
else			yylval = yytext; return ELSETOK;

{loops}			yylval = yytext; return LOOPTOK;
{types}			yylval = yytext; return TYPETOK;

"="			yylval = yytext; return ASSIGNMENT;
\n			/*ignored*/;
[ \t]+			/*ignored*/;

	
{identifier}		{
				yylval = yytext;
				return IDENTIFIER;
			}
%%

