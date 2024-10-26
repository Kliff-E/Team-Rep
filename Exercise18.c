#include <stdio.h>


int main(){

int x = 3;
int y = 3;

int matrix[x][y];
//int *ptr = matrix;

    for (int i = 0; i < 3; i++)
    {

        if(i < 3){

        for (int j= 0; j < 3; j++)
        {
        scanf("%d", &matrix[i][j]);
        
        }
    }   
    }

    for (int i = 0; i < 3; i++)
    {
        printf("\n");

        if(i < 3){

        for (int j= 0; j < 3; j++)
        {
        printf("%d ", matrix[i][j]);
        
        }
        printf("\n");
    }   
    }



    return 0;
}