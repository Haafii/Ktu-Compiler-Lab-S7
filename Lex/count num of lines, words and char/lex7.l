/*Write a LEX program to count the number of lines, words and characters in a given file.*/


	#include<stdio.h>
	int line_count = 0;
	int word_count = 0;
	int char_count = 0;
	

%%
[\n] {line_count++;}
[(" ")] {word_count++;}
[0-9]|[A-Z]|[a-z] {char_count++;}
%%


int yywrap(){return 1;}

int main()
{	
	FILE *fp;
	fp = fopen("file.txt", "r");
	yyin = fp;
	yylex();
	printf("\nline count : %d\n",line_count);
	printf("word count : %d\n",word_count+line_count);
	printf("charecter count : %d\n",char_count);
	return 1;
}
