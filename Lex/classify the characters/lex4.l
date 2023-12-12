/*Write a LEX program to classify the characters in a given text in to uppercase or lower
case letters, digits, special characters etc,.*/

%{
	#include<stdio.h>
	int upper_count = 0;
	int lower_count = 0;
	int digit_count = 0;
	int spcl_count = 0;
	
%}

%%
[A-Z] {printf("%s is a upper case\n", yytext);upper_count++;}
[a-z] {printf("%s is a lower case\n", yytext);lower_count++;}
[0-9] {printf("%s is a digit\n", yytext);digit_count++;}
[^ A-Za-z0-9\n\t\r\f\v] {printf("%s is a special charecter\n", yytext);spcl_count++;}
%%


int yywrap(){return(1);}

void main()
{
	printf("Enter a string : ");
	yylex();
	printf("upper count : %d\n",upper_count);
	printf("lower count : %d\n",lower_count);
	printf("digit count : %d\n",digit_count);
	printf("special char count : %d\n",spcl_count);
}
