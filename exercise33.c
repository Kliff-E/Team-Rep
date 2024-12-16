#include <stdio.h>

#define pegs 64
#define power 2
#define minut 60
#define hour 60
#define day 24
#define year 365
long long unsigned int moves = 1;
long unsigned int time;



int main()
{


    for(int i = 1; i <= pegs; i++)
    {
        (moves *= power);
    }

    time = ((((moves -1)/minut) /hour) /day) /year;

    printf("%lu\n", time);


    return 0;
}