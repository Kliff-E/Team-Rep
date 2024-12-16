#include <stdio.h>
#include <stdbool.h>

bool prime(int nr);

int main()
{

    int nr;

    printf("Write a number\n");
    scanf("%d", &nr);

    if (nr < 0)
    {
        nr = -nr;
    }

    bool result = prime(nr);

    if ( result == 0 || nr == 0 || nr == 1)
    {
        printf("%d is not a prime number\n", nr);
    }
    else if(result == 1)
    {
        printf("%d is a prime number\n", nr);
    }




    return 0;
}


bool prime(int nr)
{
    for(int i = 2; i <= nr/ 2; i++){

        if(nr % i == 0){
        return 0;
        }
    } 
    
    return 1;
}