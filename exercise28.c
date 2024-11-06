#include <stdio.h>
#include <string.h>

char a[16];
char b[16];
int x;

int compare();


int main(){

    printf("Input first string\n");
    fgets(a, sizeof(a), stdin);

    printf("Input second string\n");
    fgets(b, sizeof(b), stdin);


    printf("\nFirst string: %s\n", a);
    printf("Second string: %s\n", b);

    int x = compare(x);

    printf("%d\n", x);


    return 0;
}

int compare(int x){


    if (strlen(a) != strlen(b))
    {
        x = 0;
    }
    else{

    for(int i = 0; i < strlen(a); i++)
    {
        if(a[i] != b[i])
        {
            x = 0;
            break;
        }
        else{
            x = 1;
        }
    }


    }

    return(x);




}