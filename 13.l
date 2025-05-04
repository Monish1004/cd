%{
#include "y.tab.h"
#include<stdlib.h>

%}

%%

[0-9]+			{ yylval = atoi(yytext); return NUM; }
[a-zA-Z_][a-zA-Z0-9_]*	{ return ID; }
[ \t\n] 		;
.			{ return yytext[0]; }

%%

int yywrap(){
	return 1;
}


