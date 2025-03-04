%{ 
#include <stdio.h> 
%}

%token NUMBER

%%

input:
    NUMBER { printf("Number detected: %d\n", $1); } 
   ;

%%

int yyerror(char *s) {
    printf("Error: %s\n", s); 
    return 0; 
}

int main() {
    printf("Enter a number ::\n");
    yyparse();
    return 0;
}