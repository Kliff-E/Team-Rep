#include <stdio.h>
#include <ctype.h>


unsigned int x;
unsigned int y;



int prime_function();

int main(){

    printf("Finding prime numbers within a range \n");
    printf("Write the number the range should start from\n");
    scanf("%d", &x);
    printf("Write the number the range should end at\n");
    scanf("%d", &y);
    printf("\n");

    prime_function();


}


int prime_function()
{
   
    if(x < 2)
    {
        x = 2;
    }

    while (x <= y)
    {

        for(int i = 2; i <= x/ 2; i++){

        if(x % i == 0){

            x++;
        }
        else
        {
            printf("%d ", x);
            x++;
        }
        }
        
        
    } 

}