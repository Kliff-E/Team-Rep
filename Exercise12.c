#include <stdio.h>

int numb;
int add;
int tot;

int main (){

    printf("Input a positive number\n");
    scanf("%d", &numb);


    for(int i = 0;i < numb||i +1 < numb;i +=2)
    {
        printf("%d ", i);
       tot = tot +i;
    }
    add = tot + numb;
    printf("\n");
    printf("%d \n", add);
    return 0;
}