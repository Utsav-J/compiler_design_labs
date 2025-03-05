%{
#include <stdio.h>
int lines = 0, spaces = 0, tabs = 0;
int wordcount = 0;
%}


%%
\n { lines++; }
" " { spaces++; }
\t { tabs++; }
[a-zA-Z]+ { wordcount++ ; }
%%


int main() {
    yylex();
    
    printf("Lines: %d\nSpaces: %d\nTabs: %d\n", lines, spaces, tabs);
    printf("words count: %d", wordcount);


    return 0;
}
int yywrap() {
    return 1;
}
