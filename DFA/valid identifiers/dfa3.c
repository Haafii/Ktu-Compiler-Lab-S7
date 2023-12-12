//Design and implement a DFA to recognize valid identifiers of C language.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
bool isAccepted(char string[]){
	int current_state = 0;
	for(int i = 0; string[i] != '\0'; i++){
		if(isalpha(string[i]) || string[i] == '_'){
			if(current_state == 0){
				current_state = 1;
			}
			else if(current_state == 1){
				current_state = 1;
			}
		}
		else if(isdigit(string[i]))	{
			if(current_state == 0){
				current_state = 2;
			}
			else if(current_state == 1){
				current_state = 1;	
			}
		} 
		else {
			current_state = 2;
		}
	}
	if(current_state == 1)
		return true;
	else
		return false;

}

void main(){
	char buffer[200];
	printf("Enter the string:");
	scanf("%s", buffer);
	
	if(isAccepted(buffer))
		printf("%s is a valid identifier", buffer);
	else
		printf("%s is a invalid identifier", buffer);
}
