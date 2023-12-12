/*Write a LEX program to recognize valid identifiers of C language..*/

%{
	#include<stdio.h>
%}

%%
(_|[a-z]|[A-Z])(_|[a-z]|[A-Z]|[0-9])* printf("%s is Accepted\n", yytext);
(.)* printf("%s is not Accepted\n", yytext);
%%


int yywrap(){return(1);}

void main()
{
	printf("Enter a string : ");
	yylex();
}
