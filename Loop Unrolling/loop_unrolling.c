/* Write a program to perform loop unrolling. */
#include<stdio.h>
#include<string.h>

int main(){
	FILE *input,*output;
	int fact=0,i=0;
	char ch,str[20];
	input=fopen("inputfile.c","r");
	output=fopen("output.c","w+");
	while(!feof(input)){
		ch=fgetc(input);
		if(ch=='+'){
			fprintf(output,"%c",ch);
			ch=fgetc(input);
			if(ch=='+'){
				printf("\nEnter the increment factor: ");
				scanf("%d",&fact);
				fprintf(output,"=%d",fact);
				ch=fgetc(input);
			}
		}
		if(ch=='d'){
			i=0;
			while(ch!='\n'){
				str[i]=ch;
				i++;
				ch=fgetc(input);
			}
			str[i]='\0';
			if(strcmp(str,"delete(x);")==0){
				fprintf(output,"%s\n",str);
				for(int i=0;i<fact-1;i++){
					fprintf(output,"\t\tdelete(x+%d);\n",i+1);
				}
			}else{
				fprintf(output,"%s",str);
			}
		}
		fprintf(output,"%c",ch);

	}
	fclose(input);
	fclose(output);
	return 0;
}

