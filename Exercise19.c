#include <stdio.h>
#include <ctype.h>
#include <string.h>

char string [33] = {0};
int onespace = 0;

int main(){

printf("Write your full name\n");
fgets(string,sizeof(string),stdin);


for (int i = 0; i < strlen(string); i++)
    {
        if (isalpha(string[i]))
        {
            (void)putchar(string[i]);
            onespace = 0;
        }
        else if(isblank(string[i]) && onespace == 0)
        {
            onespace++;
            printf("\n");
        }
    }

 
printf("\n");
return 0;
}