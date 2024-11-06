#include <stdio.h>

#define SIZE 3

int arr[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
int x = 2;
int choice;
int end;

void display_matrix(int arr[SIZE][SIZE]);

void multiply_constant(int matrix[SIZE][SIZE], int x);

void add_constant(int matrix[SIZE][SIZE], int x);

void transpose_matrix(int arr[SIZE][SIZE]);


int main()
{

    printf("Choose function multiply = 1 add = 2 transpose = 3\n");
    scanf("%d", &choice);

    void (*display_ptr)() = &display_matrix;
    void (*multiply_ptr)() = &multiply_constant;
    void (*add_ptr)() = &add_constant;
    void (*transpose_ptr)() = &transpose_matrix;


    if (choice == 1){
    (*display_ptr)(arr);
    (*multiply_ptr)(arr,x);
    (*display_ptr)(arr);
    }

    else if(choice == 2){
    (*display_ptr)(arr);
    (*add_ptr)(arr,x);
    (*display_ptr)(arr);
    }
    else if (choice == 3){
    (*display_ptr)(arr);
    (*transpose_ptr)(arr);
    (*display_ptr)(arr);
    }

}

void display_matrix(int arr[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n");
    for(int j = 0; j < SIZE; j++)
    {
        printf("%d ", arr[i][j]);
    }
    }

    printf("\n");
    

}

void multiply_constant(int matrix[SIZE][SIZE], int x)
{
    for (int i = 0; i < SIZE; i++)
    {

    for(int j = 0; j < SIZE; j++)
    {
        arr[i][j] *= x;
    }
    }
}

void add_constant(int matrix[SIZE][SIZE], int x)
{
    for (int i = 0; i < SIZE; i++)
    {

    for(int j = 0; j < SIZE; j++)
    {
        arr[i][j] += x;
    }
    }


}

void transpose_matrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {

    for(int j = i +1; j < SIZE; j++)
    {
        int temp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = temp;
    }
    }


}

