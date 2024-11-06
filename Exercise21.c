#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main(){
    
    
    int arr[10];
    int temp[10];
    int I = 0;
    int c = 0;
    int *ptr = arr;
    int *te = temp;

    printf("Before\n");
    srand(time(NULL));

    for (int r = 0; r < 10; r++){

    int nr = rand()% 10;
    *(ptr +r) = nr;
    printf("%d", *(ptr +r));

    }

    for(int i = 0; i < 10; i++)
    {
        I++;
        if(*(ptr +i) > *(ptr +I) && I < 10)
        {
            *(te +i) = *(ptr + i);
            *(ptr +i) = *(ptr + I);
            *(ptr +I) = *(te + i);
            
            
        }
        else if (I == 10)
        {
            i = -1;
            I = 0;
            c++;
            if (c == 10)
            {
                break;
            }
            
        }
    
    }
    printf("\nAfter \n");
    for (int pr = 0; pr < 10; pr++){

    printf("%d", *(ptr +pr));

    }
    printf("\n");
    return 0;
}