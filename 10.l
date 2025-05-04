%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

DIGIT [0-9]+

%%

{DIGIT}    { 
                yylval = atof(yytext); 
                printf("Token: NUM, Value: %s\n", yytext); 
                return NUM; 
            }

[ \t\n]    ; // Ignore whitespace

.          { 
                printf("Token: %s\n", yytext); 
                return yytext[0]; 
            }

%%

int yywrap() {
    return 1;
}
