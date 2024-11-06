#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char string [10];
char *ptr = string;

int main(){

printf("Write a max 10 letter string with lowecase and uppercase letters\n");
fgets(ptr,sizeof(ptr),stdin);


for (int i = 0; i < sizeof(ptr);i++){

if (isupper(*(ptr +i))){

    *(ptr +i) = tolower(*(ptr +i));
   
}
else if (islower(*(ptr +i))){

    *(ptr +i) = toupper(*(ptr +i));
}
    
    
}
 
printf("%s", string);

return 0;
}