#include<stdio.h>
#include<string.h>
#include<ctype.h>

void printFile(FILE *fp){
	char contents[1000] = {0};
	while(1){
		fgets(contents, 1000, fp);
		if(feof(fp))
			break;
		printf("%s",contents);
	}
}

int main(){
	char keywords[15][15] = {"if", "else", "while", "do", "int", "return"}; 
	char str[20], ch, contents[1000];
	int flag, i, line = 1;
	FILE *fp;
	FILE *keyword = fopen("keyword.txt", "w");
	FILE *special_char = fopen("special_char.txt", "w");
	FILE *digit = fopen("digit.txt", "w");
	FILE *operator = fopen("operator.txt", "w");
	FILE *identifer = fopen("identifer.txt", "w");
	fp = fopen("sample.c", "r");
	
	while(!feof(fp)){
		i = 0;
		flag = 0;
		ch = fgetc(fp);
		//printf("%c",ch);
		if(ch == '/'){
			ch = fgetc(fp);
			if(ch == '/'){
				ch = fgetc(fp);
				while(ch != '\n')
					ch = fgetc(fp);
			}
			ungetc(ch, fp);
		}
		
		
		
		else if(ch == '+' || ch == '-' || ch == '*' ||ch == '/' || ch =='%' || ch == '=' || ch == '<' || ch == '>'){
			str[i] = ch;
			i++;
			ch = fgetc(fp);
			if(ch == '+' || ch == '-' || ch == '*' ||ch == '/' || ch =='%' || ch == '=' || ch == '<' || ch == '>'){
				str[i] = ch;
				i++;
			}
			str[i] = '\0';
			//printf("%s is a operator\n",str);
			fprintf(operator, "line: %d\t", line);
			fprintf(operator, "%s\n", str);	
		}
		
		
		
		else if(isdigit(ch)){
			str[i] = ch;
			i++;
			ch = fgetc(fp);
			
			while(isdigit(ch) && ch != ' '){
				str[i] = ch;
				i++;
				ch = fgetc(fp);
			}
			ungetc(ch, fp);
			str[i] = '\0';
			
			fprintf(digit, "line: %d\t", line);
			//printf("%s is a digit\n",str);
			fprintf(digit, "%s\n", str);
		}
		
		
		else if(ch == '(' || ch == ')' || ch == '{' || ch == ',' || ch == ':' || ch == '}' || ch == ';'){
			//printf("%c is a special char\n",ch);
			fprintf(special_char, "line: %d\t", line);
			fprintf(special_char, "%c\n", ch);
		}
			
			
		else if(isalpha(ch)){
			str[i] = ch;
			i++;
			ch = fgetc(fp);
			
			while(isalnum(ch) && ch != ' '){
				str[i] = ch;
				i++;
				ch = fgetc(fp);
			}
			ungetc(ch, fp);
			str[i] = '\0';
			
			
			for(int j =0; j<=15; j++){
				if(strcmp(str, keywords[j]) == 0){
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				//printf("%s is a keyword\n",str);
				fprintf(keyword, "line: %d\t", line);
				fprintf(keyword, "%s\n", str);
				
			}
			else{
				//printf("%s is a identifer\n",str);
				fprintf(identifer, "line: %d\t", line);
				fprintf(identifer, "%s\n", str);
			}
		}
		if(ch == '\n')
			line++;
					
	}
	fclose(fp);
	fclose(keyword);
	fclose(special_char);
	fclose(digit);
	fclose(operator);
	fclose(identifer);
	
	
	FILE *keyword_final = fopen("keyword.txt", "r");
	printf("\nKeywords\n");	
	printFile(keyword_final);
	
	FILE *special_char_final = fopen("special_char.txt", "r");
	printf("\nspecial charecter\n");	
	printFile(special_char_final);
	
	FILE *digit_final = fopen("digit.txt", "r");
	printf("\ndigits\n");	
	printFile(digit_final);
	
	FILE *operator_final = fopen("operator.txt", "r");
	printf("\noperators\n");	
	printFile(operator_final);
	
	FILE *identifer_final = fopen("identifer.txt", "r");
	printf("\nidentifers\n");	
	printFile(identifer_final);

	
}

