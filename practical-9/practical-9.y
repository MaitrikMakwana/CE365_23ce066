%{
#include <stdio.h>
#include <stdlib.h>

int valid = 1;

void yyerror(const char *s);
int yylex();
%}

%token I T E_SYM B A

%%

S : I E T S S1
  | A
  ;

S1 : E_SYM S
   | /* epsilon */
   ;

E : B
  ;

%%

void yyerror(const char *s) {
    printf("Invalid string\n");
    valid = 0;
}

int main() {
    printf("Enter string: ");
    yyparse();

    if(valid)
        printf("Valid string\n");

    printf("Press Enter to exit...");
    getchar();
    return 0;
}