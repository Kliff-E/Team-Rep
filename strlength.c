#include <stdio.h>

char str[10];
int len;


int strlength();

int main()
{

    printf("Write a string\n");
    fgets(str,sizeof(str),stdin);

    int len = strlength(len);

    printf("string length: %d\n", len);


    return 0;
}


int strlength(int len)
{

for(int i = 0; i < 10; i++)
{
    if(str[i] == '\0')
    {
        len = i -1;
        break;

    }
}

return(len);

}