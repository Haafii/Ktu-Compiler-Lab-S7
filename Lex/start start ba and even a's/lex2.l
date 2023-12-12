/*Write a LEX program to recognize the strings defined over Σ = {a, b} those start with ba
and contains an even number of a’s.*/

%{
	#include<stdio.h>
%}

%%
bab*a(b*ab*a)*b* printf("%s is Accepted\n", yytext);
(.)* printf("%s is not Accepted\n", yytext);
%%


int yywrap(){return(1);}

void main()
{
	printf("Enter a string : ");
	yylex();
}
