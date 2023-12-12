#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    FILE *fp1,*fp2;
    int i=0,flag=0,num;
    char ch,nums[10]={0};
    fp1=fopen("inputfile.c","r");
    fp2=fopen("outputfile.c","w");
    while(!feof(fp1)){
        ch = fgetc(fp1);
        if(ch == 'x'){
            if(flag == 0){
                fprintf(fp2, "%c", ch);
                ch = fgetc(fp1);
                if(ch == '='){
                    flag = 1;
                    fprintf(fp2, "%c", ch);
                    ch = fgetc(fp1);
                    while(ch != ';'){
                        fprintf(fp2, "%c", ch);
                        nums[i] = ch;
                        i++;
                        ch = fgetc(fp1);
                    }
                    nums[i] = '\0';
                }
                num = atoi(nums);
            }
            else if(flag == 1){
                fprintf(fp2, "%d", num);
            }
        }
        if(ch != 'x')
            fprintf(fp2, "%c", ch);
        if(ch == '}')
            break;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}



