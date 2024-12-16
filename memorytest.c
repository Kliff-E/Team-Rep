#include <stdio.h>
#include <stdlib.h>


int input_size;
int *ptr;
int *reptr;


int main()
{

    printf("input the size of the array\n");
    scanf("%d", &input_size);

    ptr = (int*)malloc(input_size * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    printf("input the size of the array\n");
    scanf("%d", &input_size);
    

    reptr = (int*)realloc(ptr, sizeof(int));


    printf("\n");

    for (int i = 0; i < input_size; i++)
    {
        ptr[i] = input_size;
    }

    for (int i = 0; i < input_size; i++)
    {
        printf("%d", ptr[i]);
    }

    printf("\n");

    for (int i = 0; i < input_size; i++)
    {
        printf("%d", reptr[i]);
    }



    free(ptr);




    return 0;
}