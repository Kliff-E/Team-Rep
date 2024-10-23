#include <stdio.h>
#include <string.h>

int main(){

char str[5];


printf("Write a five letter word\n");
scanf("%s", str);

for(int i = 0; i <= sizeof(str); i++)
{
  int length = sizeof(str);
  char temp[length];
  int j = 0;
  j = length -i;
  temp[j] = str[j]; 
  str[i] = temp[j];

}


printf("%s\n", str);


return 0;

}