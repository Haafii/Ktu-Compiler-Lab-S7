/*Write a LEX program to recognize the strings defined over Σ = {a, b} those start with ba.*/

%{
	#include<stdio.h>
%}

%%
^ba[a-b]* printf("%s is Accepted\n", yytext);
(.)* printf("%s is not Accepted\n", yytext);
%%
int yywrap(){return(1);}

void main()
{
	printf("Enter a string : ");
	yylex();
}
