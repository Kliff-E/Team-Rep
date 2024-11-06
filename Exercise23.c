#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){

int x = 2;
int y = 3;

int matrix[x][y];
int (*rix)[y] = matrix;

    srand(time(NULL));

    for (int r = 0; r < 6; r++){

    int nr = rand()% 100 -1;
    (*rix)[r] = nr;
    printf("%d ", (*rix)[r]);
    }

    printf("\n");

        for (int j= 0; j < 6; j++)
        {
        printf("%d ", (*rix)[j]);

        if (j == 2)
        {
            printf("\n\n");
        }
        
        }
        printf("\n");



    return 0;
}