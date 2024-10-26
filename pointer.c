#include <stdio.h>



int main(){

int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;

printf("\n");

for (int i = 0; i < 5; i++)
{
    printf("%d", (*ptr +i));
}
printf("\n");

for (int i = 0; i < 5; i++)
{
    printf("%d\n", (*ptr +i+1));
}

    return 0;
}
