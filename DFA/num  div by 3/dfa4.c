//Design and implement a DFA to check whether the given decimal number is divisible by 3.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
bool isAccepted(char buffer[]){
	int current_state = 0;
	for(int i = 0; buffer[i] != '\0'; i++){
		if(buffer[i] == '1' || buffer[i] == '4' || buffer[i] == '7'){
			if(current_state == 0){
				current_state = 1;
			}
			else if(current_state == 1){
				current_state = 2;
			}
			else if(current_state == 2){
				current_state = 0;
			}
		}
		else if(buffer[i] == '2' || buffer[i] == '5' || buffer[i] == '8'){
			if(current_state == 0){
				current_state = 2;
			}
			else if(current_state == 1){
				current_state = 0;
			}
			else if(current_state == 2){
				current_state = 1;
			}
		} 
		else if(buffer[i] == '0' || buffer[i] == '3' || buffer[i] == '6' || buffer[i] == '9')	{
			if(current_state == 0){
				current_state = 0;
			}
			else if(current_state == 1){
				current_state = 1;
			}
			else if(current_state == 2){
				current_state = 2;
			}
		} 
	}
	if(current_state == 0)
		return true;
	else
		return false;

}

void main(){
	char buffer[200];
	printf("Enter a digit:");
	scanf("%s", buffer);
	
	if(isAccepted(buffer))
		printf("%s is divisible by 3", buffer);
	else
		printf("%s is not  divisible by 3", buffer);
}
