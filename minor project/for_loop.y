%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%token FOR DATATYPE ID NUM
%token INC DEC ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token EQ NEQ LE GE LT GT
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON ASSIGN COMMA

%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left '+' '-'
%left '*' '/'
%right INC DEC

%%

program:
    for_loop { printf("Valid C++ for loop syntax matches the grammar.\n"); }
    ;

for_loop:
    FOR LPAREN init_stmt SEMICOLON cond_expr SEMICOLON update_expr RPAREN body
    ;

init_stmt:
    /* empty */
    | decl_list
    | expr_list
    ;

decl_list:
    DATATYPE decl_item
    | decl_list COMMA decl_item
    ;

decl_item:
    ID
    | ID ASSIGN expr
    ;

expr_list:
    expr
    | expr_list COMMA expr
    ;

cond_expr:
    /* empty */
    | expr
    ;

update_expr:
    /* empty */
    | expr_list
    ;

body:
    stmt
    | LBRACE stmt_list RBRACE
    ;

stmt_list:
    /* empty */
    | stmt_list stmt
    ;

stmt:
    SEMICOLON
    | expr SEMICOLON
    | for_loop
    ;

expr:
    ID
    | NUM
    | ID INC
    | ID DEC
    | INC ID
    | DEC ID
    | expr ASSIGN expr
    | expr ADD_ASSIGN expr
    | expr SUB_ASSIGN expr
    | expr MUL_ASSIGN expr
    | expr DIV_ASSIGN expr
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr EQ expr
    | expr NEQ expr
    | expr LE expr
    | expr GE expr
    | expr LT expr
    | expr GT expr
    | LPAREN expr RPAREN
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}

int main(void) {
    printf("Enter C++ for loop to parse:\n");
    yyparse();
    return 0;
}
