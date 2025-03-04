%{
#include <stdio.h>
%}

%%
if | then | for | while | printf | scanf { printf("%s is a keyword", yytext);}
[0-9]+ {printf("%s is a number", yytext);}
[a-zA-Z]+ {printf("%s is a word", yytext);}
.|\n {printf(" ");}
%%

int main(){
printf("Enter the string");
yylex();
}

int yywrap(){
return 1;
}