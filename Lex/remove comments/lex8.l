%{
	#include<stdio.h>
		
%}


%%
\/\/(.*) {};					
\/\*(.*\n)*.*\*\/  {};			
%%

int yywrap(){return 1;}

int main()
{
	yyin=fopen("Hello.c","r");
	yyout=fopen("new.c","w");
	yylex();
	return 0;
} 
