%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
int yyerror(char *s);
%}

%token ID DIG
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

stmt : 
     expn
     ;
expn :
      expn '+' expn
     |expn '-' expn
     |expn '*' expn
     |expn '/' expn
     |'-'expn	%prec UMINUS
     |'(' expn ')'
     |DIG
     |ID
     ;

%%

int main(){
	printf("Enter an expression : ");
	yyparse();
	printf("Valid Expression\n");
	return 0;
}

int yyerror(char *s){
	printf("Invalid expression\n");
	exit(1);
}
