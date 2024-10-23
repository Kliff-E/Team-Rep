#include <stdio.h>
#include <string.h>

int main(){

int round = 0;
char str[4];

printf("check if a four letter word is a palindrome\n");
scanf("%s", str);

 for (int i = 0 +round; i < sizeof(str)/2; i++)
{
   
    round++;
    

for (int I = sizeof(str) -round; I >= sizeof(str)/2; I--)
{
    

    if(str[i] != str[I])
    {
      printf("is not palindrome\n");
    goto end;
    }
    else if(round == sizeof(str)/2) {

        printf("is a palindrome\n");

    }else{
        break;
    }
    
} 

}
end:
return 0;

}