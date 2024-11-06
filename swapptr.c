#include <stdio.h>

int x = 1;
int y = 0;


void swap(int *px, int *py);

int main()
{

    swap(&x,&y);

    printf("%d %d\n", x, y);

    return 0;
}

void swap(int *px, int *py)
{
   int temp = *px;
   *px = *py;
   *py = temp; 
}