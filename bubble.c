#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int arr[10];
int temp[20];
int arr2 [10];
int r = 1;
int final[20];

void bubble();
void merge();

int main()
{

    srand(time(NULL));
    printf("\n First Array:");

    for(int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 10;
        arr2[i] = rand() % 10;
        printf("%d ", arr[i]);

    }

    printf("\nSecond Array:");

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr2[i]);

    }

    bubble();
    
    printf("\n First Array:");

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);

    }
    printf("\n Second Array:");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr2[i]);

    }

    printf("\n");


    merge();

    printf("\n Final Array: ");

    for(int i = 0; i < 20; i++)
    {
        printf("%d ", final[i]);

    }

        

    return 0;
}

void bubble()
{
    while (r < 10)
    {

        for (int j = 0; j <= 20; j++)
        {

            if(arr[r] < arr[j])
            {
            temp[r] = arr[r];
            arr[r] = arr[j];
            arr[j] = temp[r];
            }

        }
        for (int l = 0; l <= 20; l++)
        {

            if(arr2[r] < arr2[l])
            {
            temp[r] = arr2[r];
            arr2[r] = arr2[l];
            arr2[l] = temp[r];
            }

        }

        r++;
    }

}

void merge()
{


    for(int i = 0; i < 10; i++)
    {
        final[i] = arr[i];
        final[i+10] = arr2[i];
    }

int f = 1;

 while (f < 20)
    {

        for (int j = 0; j <= 20; j++)
        {

            if(final[f] < final[j])
            {
            temp[f] = final[f];
            final[f] = final[j];
            final[j] = temp[f];
            }

        }

        f++;
    }
}