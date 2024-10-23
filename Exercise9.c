#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int guess;
char guessf;
int rd;
char restart;

int main (){
Restart:
rd = 0;
srand(time(NULL));
int Nr = rand() % 100;
printf("random number %d\n", Nr );
printf("Guess a number between 0 and 99\n");

for ( rd = 0; rd < 10;rd++)
{

if(scanf("%d", &guess) ==1){


while (getchar() != '\n');

if(guess < 0 || guess > 99 ){

printf("Not a number between 0 and 99\n");



}

else if (guess == Nr){

    printf("Correct!\nGuesses:%d\n", rd+1);
    printf("random number was %d\n", Nr );
    rd = 10;
}

    else if (guess < Nr){

        printf("Too small ;)\n");
        printf("Try Again! %d Guesses left\n", 9-rd);
    
    }

    else if(guess > Nr){

        printf("Too big :o\n");
        printf("Try Again! %d Guesses left\n", 9-rd);
    }
}
    else {
printf("not a number, game restarts %d\n", guess);
rd = 10;
}
     



if(rd == 10){
        printf("Wanna play again?\nYes = y No = n\n");
        while (getchar() != '\n');
        scanf(" %c", &restart);

        if(restart == 'y')
        {
            goto Restart;
        }
        else if(restart == 'n')
        {
            return 0;
        }
    }
}

};