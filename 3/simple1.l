%{ 
#include <stdio.h>
#include <stdlib.h> 
%}

%%

[0-9]+ { 
     printf("Number detected: %s\n", yytext);
}
\n      ; // Ignore new lines 
.       { printf("Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1; 
}