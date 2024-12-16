#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void fill_arr(int arr[5]);
void print_arr(int arr[5]);
void print_matrix(int matrix[2][2]);

int main()
{

    int arr[5];
    int matrix[2][2] = {{1,2},{3,4}};

    fill_arr(arr);
    print_arr(arr);
    printf("\n");
    print_matrix(matrix);

    return 0;
}

void fill_arr(int arr[5])
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        arr[i] = rand()% 10;
    }
    
}

void print_arr(int arr[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void print_matrix(int matrix[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        printf("\n");
    for(int j = 0; j < 2; j++)
    {
        printf("%d ", matrix[i][j]);
    }
    }

    printf("\n");
}