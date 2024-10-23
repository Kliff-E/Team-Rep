#include <stdio.h>
#include <ctype.h>


int main(){
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