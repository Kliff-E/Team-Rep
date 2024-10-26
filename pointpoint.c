#include <stdio.h>


int main(){

int var = 1;
int *ptr;
ptr = &var;
int **p;
p = &ptr;

printf("%d\n", var);
printf("%p adress of var\n", &var);
printf("%p\n", ptr);
printf("%p\n", p);
printf("%p\n", *p);
printf("%p\n", (void*)(*p));


}