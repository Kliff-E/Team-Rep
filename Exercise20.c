#include <stdio.h>
#include <ctype.h>
#include <string.h>

char string [20] = {0};

int main(){

printf("Write the date and time YYYY-MM-DD HH:mm:ss\n");
fgets(string,sizeof(string),stdin);


for (int i = 0; i <= strlen(string); i++){
    
        if (!isdigit(string[i]) && i != 4 && i != 7 && i!= 10 && i != 13 && i != 16 && i !=19){

            printf("not correct format %s", string);
            printf("\n%d\n", i);
            break;
        }
        else if(!isblank(string[i]) && i ==10 ){

            printf("not correct format %s", string);
            printf("\n%d\n", i);
            break;
        }
        else if(i == 4 && string[i] != '-'||i == 7 && string[i] != '-'){

            printf("not correct format %s", string);
            printf("\n%d\n", i);
            break;
        }
        else if(i == 13 && string[i] != ':'|| i == 16 && string[i] != ':'){

            printf("not correct format %s", string);
            printf("\n%d\n", i);
            break;
        }

        else if ( i == strlen(string)){

            printf("correct format %s\n", string);
            printf("%c\n", string[i]);
        }
    }
return 0;
}