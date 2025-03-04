%{ 
#include <math.h> 
%} 
DIGIT [0-9] 
ID [a-zA-Z][a-z0-9]* 


%% 
{DIGIT}+ { printf("An integer: %s (%d)\n", yytext, atoi(yytext)); } 
{DIGIT}+"."{DIGIT}+ { printf("A float: %s (%g)\n", yytext, atof(yytext)); } 
int|main|return|if|then|begin|end|procedure|function { printf("A keyword: %s\n", yytext); } 
{ID} { printf("An identifier: %s\n", yytext); } 
"+"|"-"|"*"|"/" { printf("An operator: %s\n", yytext); } 
"/*"[^*]*"*/" { /* eat up one-line comments */ } 
[ \t\n]+ { /* eat up whitespace */ } 
[.;\(\)\{\}\[\]] { printf("Special symbol: %s\n", yytext); } 
"#" { printf("Preprocessor symbol: %s\n", yytext); } 
"<" { printf("Less-than symbol: %s\n", yytext); } 
">" { printf("Greater-than symbol: %s\n", yytext); } 
"_" { printf("Underscore symbol: %s\n", yytext); } 
":" { printf("Colon symbol: %s\n", yytext); } 
"," { printf("Comma symbol: %s\n", yytext); } 
"=" { printf("Equality symbol: %s\n", yytext); } 
"!" { printf("Exclamation mark: %s\n", yytext); } 
"&" { printf("Ampersand symbol: %s\n", yytext); } 
"|" { printf("Pipe symbol: %s\n", yytext); } 
"^" { printf("Caret symbol: %s\n", yytext); } 
"?" { printf("Question mark: %s\n", yytext); } 
"~" { printf("Tilde symbol: %s\n", yytext); } 
. { printf("Unrecognized character: %s\n", yytext); }  // This handles any unrecognized character
%% 


int yywrap() { return 1; } 
int main(int argc, char **argv) { 
 FILE *fp; 
 char filename[50]; 
 printf("Enter the filename: \n"); 
 scanf("%s", filename); 
 fp = fopen(filename, "r"); 
 if (!fp) { 
 	printf("Error opening file.\n"); 
 	return 1; 
 } 
 yyin = fp; 
 yylex(); 
 fclose(fp); 
 return 0; 
}
