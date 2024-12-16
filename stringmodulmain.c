#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringmodul.h"

int main()
{

char name1 [] = "kliff";
char name2[] = "bob";

int strl = length(name1);
int strl2 = length(name2);

printf("string 1 length %d string 2 length %d\n", strl, strl2);

int check = compare(name1, name2);

if (check == 1)
{
    printf("the strings are the same\n");
}
else{
    printf("the strings are not the same\n");
}


    return 0;
}