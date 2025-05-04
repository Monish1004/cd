%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define YYSTYPE double

int yyerror(char *s);
int yylex(void);
%}

%token NUM
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

Statement:
    E { printf("Answer: %g\n", $$); }
    | Statement '\n'
    ;

E:
    E '+' E { $$ = $1 + $3; printf("Add: %g + %g = %g\n", $1, $3, $$); }
  | E '-' E { $$ = $1 - $3; printf("Subtract: %g - %g = %g\n", $1, $3, $$); }
  | E '*' E { $$ = $1 * $3; printf("Multiply: %g * %g = %g\n", $1, $3, $$); }
  | E '/' E {
      if ($3 == 0) {
          yyerror("Division by zero");
          $$ = 0;
      } else {
          $$ = $1 / $3;
          printf("Divide: %g / %g = %g\n", $1, $3, $$);
      }
  }
  | '-' E %prec UMINUS { $$ = -$2; printf("Unary Minus: -%g = %g\n", $2, $$); }
  | '(' E ')' { $$ = $2; }
  | NUM { $$ = $1; printf("NUM: %g\n", $$); }
  ;

%%

int main() {
    printf("Enter arithmetic expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error -> %s\n", s);
    exit(1);
}
