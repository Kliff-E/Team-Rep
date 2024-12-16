#include <stdio.h>

int a = 5;
char b = 's';

int *ptra = &a;
char *ptrb = &b;

int add_five(int *ptra);
void say_value(int a);
void (*funcptr)(int) = say_value;


int  main()
{
    *ptra = 4;
    *ptrb = 'a';

    add_five(&a);

    printf("%d and %c\n", a, b);

    (*funcptr)(a);


    return 0;
}

int add_five(int *ptra)
{
    *ptra = *ptra+5;
}

void say_value(int a) { 
    printf("Value of a is %d\n", a); 
    }