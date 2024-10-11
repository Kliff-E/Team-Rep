#include <stdio.h>
#include <stdlib.h>

typedef struct {

int day;
int month;
int year;

}date;


int main(){
    date d;

    printf("what day? ");
    scanf("%d", &d.day);
    printf("what month? ");
    scanf( "%d", &d.month);
    printf("what year? ");
    scanf("%d", &d.year);

    printf("Date %d %d %d \n", d.day,d.month,d.year);



    return 0;
}