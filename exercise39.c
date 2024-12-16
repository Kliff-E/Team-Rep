#include <stdio.h>
#include "exercise39.h"
#include <string.h>

char temp;
int uppercase_i = 0;
int uppercase_j = 0;

int gcd(unsigned int x,unsigned int y)
{
    
    int i = 1;
    int div = 1;

    while (i <= x && i <= y)
    {
        if ( x % i == 0 && y % i == 0 ) 
        {
            div = i;
        }
        i++;
    }
    return div;

}

int lcm(unsigned int x,unsigned int y)
{

    int mult = 0;

    mult = (x * y) / gcd(x, y);

    return mult;

}
void sort(char * arr)
{
    for (int i = 0; i < strlen(arr) ; i++)
    {
        
    
        for (int j = i +1; j < strlen(arr) ; j++)
        {

            if (arr[i] < 97)
            {
            uppercase_i = 31;
            }
            else
            {
            uppercase_i = 0;
            }

            if (arr[j] < 97)
            {
                uppercase_j = 31;
            }
            else{
                uppercase_j = 0;
            }

            if((arr[i] + uppercase_i) > (arr[j] + uppercase_j))
            {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
            

        }
    }

    for(int i = 0; i < strlen(arr); i++)
    {
        printf("%c ", arr[i]);

    }
    printf("\n");
}