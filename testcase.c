#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "testcase.h"

void fill_arr(int arr[5])
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        arr[i] = rand()% 100;
    }
    
}

void print_arr(int arr[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void swap(int *x, int *y)
{

    int temp = *x;
    *x = *y;
    *y = temp;
}

int sort_arr(int *arr, compare_t compare)
{
    for (int i = 0; i < 5; i++)
    {
    
    for (int j = i+1; j < 5; j++)
        {

            if(compare (arr[i],arr[j]) > 0)
            {
             swap(&arr[i],&arr[j]);
            }

        }
    }
}

int ascending(int x, int y) {
    return x - y; 
}

int confirm(int *arr)
{
    int korrekt = 1;


    for (int i = 0; i < 5; i++)
    {
        if(arr[i] > arr[i +1])
        {
            korrekt = 0;
        }
    }
    



    return korrekt;
}
