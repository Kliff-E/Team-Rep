#include <stdio.h>
#include <ctype.h>


int hello()
{
    printf("Hello World\n");
}

int sum()
{
    int x = 2;
    int y = 3;
    int z;
    z = x + y;
    printf("%d\n", z);
}

int square()
{
  int nr;
  printf("Square a number\n");
  scanf("%d", &nr);
  nr = nr * nr;
  printf("%d\n",nr);
}

int average()
{
    int nr1;
    int nr2;
    int nr3;
    int ave;
    printf("averge of three numbers\n");
    scanf("%d", &nr1);
    scanf("%d", &nr2);
    scanf("%d", &nr3);
    ave = (nr1 + nr2 + nr3) /3;
    printf("%d\n", ave);
}

int prime()
{
    start:
    int Nr;
    int prime = 1;

    printf("Write a number between 2 and 10000\n");
    scanf("%d", &Nr);

    for(int i = 2; i <= Nr/ 2; i++){

        if(Nr % i == 0){
        prime = 0;
        break;
        }
    } 

    if(prime == 1 && Nr >= 2){

    printf("%d is a prime number\n", Nr);

    }
    else if(Nr < 2 || Nr > 10000 || isalpha(Nr) || ispunct(Nr) || isblank(Nr)) {

        printf("not a number between 2 and 10000\n try again\n");
        return 0;

    }
    else if (prime == 0){
        printf("%d is not a prime number\n", Nr);
    }
    goto start;
}

int main()
{

square();
hello();
sum();
average();
prime();
return 0;

}
