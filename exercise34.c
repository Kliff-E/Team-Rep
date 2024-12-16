#include <stdio.h>


int digits(int i);
int power(int base, int exponent);


int main()
{

    int input;

    printf("Input a number\n");
    scanf("%d", &input);


    if( input == 0)
    {
        input = input +1;
    }

   int result = digits(input);
   int nr = power(2, 4);

    printf("%d\n", result );
    printf("%d\n", nr );



    return 0;
}

int digits(int i) 
{
  if (i <= 0) {

    return 0;
  } else {
    return 1 + digits(i/10);
  }
}

int power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    else{
    
        return base *power(base,exponent -1);
    }
}