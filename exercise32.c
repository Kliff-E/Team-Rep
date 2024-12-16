#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


void fill_arr(int arr[5]);
void print_arr(int arr[5]);
void swap(int *x, int *y);
int ascending(int x, int y);
int descending(int x, int y);
typedef bool compare_t (int, int);
void sort_arr(int *arr, compare_t compare);


int main()
{

    int arr[5];
    int x = 1;
    int y = 0;
    int temp;

    fill_arr(arr);
    print_arr(arr);
    printf("\n");

    sort_arr(arr,ascending);
    print_arr(arr);
    printf("\n");

    sort_arr(arr,descending);
    print_arr(arr);
    printf("\n");

    


    return 0;
}

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

void sort_arr(int *arr, compare_t compare)
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

int descending(int x, int y) {
    return y - x; 
}