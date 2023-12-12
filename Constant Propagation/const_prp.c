#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    FILE *fp1, *fp2;
    int i = 0, count = 0, num;
    char ch, nums[10] = {0};

    fp1 = fopen("inputfile.c", "r");
    fp2 = fopen("outputfile.c", "w");

    while ((ch = fgetc(fp1)) != EOF) {
        if (ch == 'x') {
        	if(count==0){
        		fprintf(fp2,"%s","x=");
        	}
            ch = fgetc(fp1);
            if (ch == '=') {
                while (ch != ';') {
                    ch = fgetc(fp1);
                    nums[i] = ch;
                    i++;
                }
                nums[i - 1] = '\0';
                num = atoi(nums);
                fprintf(fp2, "%d", num);
                if(ch==';'){
                	fprintf(fp2,"%c",';');
                }
            } else {
                fseek(fp1, -1, SEEK_CUR);
            }

            if (count > 0) {
                fprintf(fp2, "%d", num);
            }
            count++;
        } else {
            fprintf(fp2, "%c", ch);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}




