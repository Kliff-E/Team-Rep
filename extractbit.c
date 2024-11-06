#include <stdio.h>


int nr;

void extract();

int main()
{
    scanf("%d", &nr);
    extract(nr);

    return 0;
}

void extract(int nr)
{
    if(nr <= 255 && nr >= 0)
    {

    for(int i = 7; i >= 0; i--)
    {
    int bit = (nr >> i) & 1;

    printf("%d ", bit);

    }

    }
    else{

        printf("not a valid number\n");
    }
}