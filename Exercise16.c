#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arr[10];
int temp[10];
int I = 0;
int c = 0;

int main(){

    printf("Before\n");
    srand(time(NULL));

    for (int r = 0; r < 10; r++){

    int nr = rand()% 10;
    arr[r] = nr;
    printf("%d", arr[r]);

    }

    for(int i = 0; i < 10; i++)
    {
        I++;
        if(arr[i] > arr[I] && I < 10)
        {
            temp[i] = arr[i];
            arr[i] = arr[I];
            arr[I] = temp[i];
            
            
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

    printf("%d", arr[pr]);

    }
    printf("\n");
    return 0;
}