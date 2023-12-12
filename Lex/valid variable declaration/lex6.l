/*Write a LEX program to recognize a valid variable declaration of C language.*/

%{
	#include<stdio.h>
%}

%%
(int|char|float|bool)(" ")("*")*(_|[a-z]|[A-Z])(_|[a-z]|[A-Z]|[0-9])*(([)([0-9])*(]))*((,)(" ")*("*")*(_|[a-z]|[A-Z])(_|[a-z]|[A-Z]|[0-9])*(([)([0-9])*(]))*)*(;) printf("%s is Accepted\n", yytext);
(.)* printf("%s is not Accepted\n", yytext);
%%


int yywrap(){return(1);}

void main()
{
	printf("Enter a string : ");
	yylex();
}
