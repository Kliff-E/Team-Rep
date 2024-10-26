#include <stdio.h>
#include <string.h>

int main(){

char str[20];
char temp;


printf("Write a five letter word\n");
scanf("%s", &str[0]);
int last = strlen(str);
int last2 = strlen(str);

for(int i = 0; i < last2/2 +1 ; i++){

    temp = str[i];
    str[i] = str[last];
    str[last] = temp;
    last--;
    printf("1\n");
}

for(int j = 0; j < last2 +1; j++){

    printf("%c", str[j]);
}
printf("\n");

return 0;

}