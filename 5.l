%{
#include<stdio.h>
int amt;
%}

letter[a-zA-z]
digit[0-9]
sign[+-]

%%
{letter}+ {
	printf("Found an identifier -> %s\n" , yytext);
}

{sign}?{digit}+ {
	sscanf(yytext , "%d" , &amt);
	printf("Found an constant -> %s\n" , yytext);
}

%%

int yywrap(){
	return 1;
}

int main(){
	yylex();
	return 0;
}


