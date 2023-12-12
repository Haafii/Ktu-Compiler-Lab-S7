/* Design and implement a lexical analyzer using LEX to recognize valid tokens (identifiers,
keywords, operators, constants etc. . .) in the input C program. The lexical analyzer should
ignore redundant spaces, tabs and newlines. It should also ignore comments. */

%{
#include <stdio.h>
#include <stdlib.h>
%}

%{
FILE *output_file;
%}

%%
"//".* {
    // Do nothing; ignore single-line comments
}

"/*"([^*]|"*"[^/])*"*/" {
    // Do nothing; ignore multi-line comments
}

[ \t\n]+    { /* Ignore whitespace, tabs, and newlines */ }

if|else|while|do|break|continue|int|double|float|return|char|case|sizeof|long|short|typedef|switch|unsigned|void|static|goto|for    { fprintf(output_file,"Keyword: %s \n",yytext);}

[0-9]+(\.[0-9]+)? { fprintf(output_file,"constant: %s \n",yytext); }

(_|[a-z]|[A-Z])(_|[a-z]|[A-Z]|[0-9])* { fprintf(output_file,"identifier: %s \n",yytext); }


"++"|"--"|"=="|"!="|"<="|">="|"<"|">"|"="|"+="|"-="|"*="|"/="|"%="|"+"|"-"|"*"|"/"|"%"    { fprintf(output_file,"operator: %s \n",yytext); }

\"[^"]*\"    { fprintf(output_file,"string: %s \n",yytext); }

.       { fprintf(output_file,"specialchar: %s \n",yytext); }

%%
int yywrap(void) {}
int main() {
    FILE *input_file = fopen("Hello.c", "r");
    output_file = fopen("out.txt", "w");
    yyin = input_file;
    yylex();
    fclose(input_file);
    fclose(output_file);
    return 0;
}

