%{
#include<stdio.h>
#include<stdlib.h>

int yylex(void);
int yyerror(char *s);

%}

%token ID NUM
%left '+' '-'
%left '*' '/'


%%

E : E '+' T { printf("E -> E + T\n"); }
  | E '-' T { printf("E -> E - T\n"); }
  | T	    { printf("E -> T\n"); }
  ;


T : T '*' F { printf("T -> T * F\n"); }
  | T '/' F { printf("T -> T / F\n"); }
  | F 	    { printf("T -> F\n"); }
  ;


F : '(' E ')' { printf("F -> (E)\n"); }
  | ID	      { printf("F -> id\n"); }
  | NUM	      { printf("F -> num\n"); }
  ;

%%

int main(){

	printf("Enter an expression : ");
	yyparse();
	return 0;
}

int yyerror(char *s){
	fprintf(stderr , "Error : %s\n",s);
	return 0;
}


