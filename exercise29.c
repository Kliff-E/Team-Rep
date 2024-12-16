#include <stdio.h>
#include <ctype.h>


unsigned int x;
unsigned int y;
int flag;



int prime_function();

int main(){

    printf("Finding prime numbers within a range \n");
    printf("Write the number the range should start from\n");
    scanf("%d", &x);
    printf("Write the number the range should end at\n");
    scanf("%d", &y);

    prime_function();
    printf("\n");


}


int prime_function()
{
   

    for(int i = x; i <= y; i++)
    {
        if (i == 0 || i == 1)
        {
            continue;
        }

        flag =1;

        for(int j = 2; j <= i/2; j++)
        {

        if(i % j == 0)
        {
            flag = 0;
            break;
            
        }
        
        }
    if(flag == 1){
       printf("%d ", i); 
    }
    } 

}