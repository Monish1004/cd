%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
int yyerror(char *s);
%}

%token DIG LET

%%
variable:
	var
	;
  var : 
	var DIG
      | var LET
      | LET
      ;

%%

int main(){
	printf("Enter a variable : ");
	yyparse();
	printf("Valid variable\n");
	return 0;
}

int yyerror(char *s){
	printf("Invalid variable\n");
	exit(1);
}

