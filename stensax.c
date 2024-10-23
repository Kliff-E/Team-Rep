#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main (){
Restart:
int p1 = 0;
int p2 = 0;
int pready = 0;
char restart = 0;
int end = 0;
int play = 0;

do{
system("clear");
printf("Sten, Sax , Påse ...\n Player 1 input your choice 1 = Sten, 2 = Sax 3 = Påse\n");
scanf("%d", &p1);

if(p1 > 3 || p1 < 0 || isalpha(p1)){

printf("wrong input\n Try again?\n Player 1 y = yes or n = no\n");
while (getchar() != '\n');
scanf("%c", &restart);

    if(restart == 'y'){

    system("clear");
    continue;

    }
    else if(restart == 'n'){
        
    end = 1;
    }

}
else{
    system("clear");
    pready = 1;
}

if (pready == 1){
pready = 0;
printf("Sten, Sax , Påse ...\n Player 2 input your choice 1 = Sten, 2 = Sax 3 = Påse\n");
scanf("%d", &p2);

if(p2 > 3 || p2 < 0){

printf("wrong input\n Try again?\n Player 2 y = yes or n = no\n");
while (getchar() != '\n');
scanf("%c", &restart);

if(restart == 'y')
        {
        
            continue;
            
        }
        else if(restart == 'n')
        {
            end = 1;
        }

}
else{
    play = 1;
    system("clear");

}
}
if (play == 1){

    switch (p1)
    {
    case 1:
        if (p1 == 1 && p2 == 2)
        {
            printf("Player 1 wins! \n Sten > Sax \n");
            end = 1;
            break;
        }
        else if ( p1 == 1 && p2 == 3)
            {
             printf("Player 2 wins! \n Påse > Sten \n");  
             end = 1; 
             break;
            }
        case 2:
            if (p1 == 2 && p2 == 1)
        {
            printf("Player 2 wins! \n Sten > Sax \n");
            end = 1;
            break;
        }
        else if (p1 == 2 && p2 == 3)
            {
             printf("Player 1 wins! \n Sax > Påse \n");  
             end = 1; 
             break;
            }
            
    case 3:
            if (p1 == 3 && p2 == 1)
        {
            printf("Player 1 wins! \n Påse > Sten \n");
            end = 1;
            break;
        }
        else if (p1 == 3 && p2 == 2)
            {
             printf("Player 2 wins! \n Sax > påse \n");  
             end = 1; 
             break;
            }
    
    default:
    printf("Tie!\n");
    end = 1;
        break;
    }
}

}
while(end != 1);

printf("Play again? \ny = yes n = no\n");
while (getchar() != '\n');
scanf("%c", &restart);

if(restart == 'y')
        {
            pready = 1;
            goto Restart;
            
        }
        else if(restart == 'n')
        {
        return 0;
        }
    
}