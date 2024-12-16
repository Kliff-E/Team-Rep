/**
 * @file assignmentg1.c
 * @author Kliff Elvin
 * @brief 
 * @version 0.1
 * @date 2024-11-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

#define MONTHS_ARR_SIZE 12
#define STRING_SIZE 12
#define DECADE 10
#define ALTERNATE_DUBBEL 2
#define ALTERNATE_MULT_ONE 1
#define LUNH_ALGORITHM_MODULO 10
#define LUNH_CORRECTION_DIVISOR 10
#define HYPHEN 6
#define FEBRUARY_leap_year 29
#define LEAP_YEAR_CHECK 4
#define LEAP_YEAR_CHECK_CENTURY 100
#define LEAP_YEAR_CHECK_FOUR_HUNDRED 400
#define TRUE 1
#define FALSE 0
#define CURRENT_YEAR 24
#define CONTROL_DIGIT 10




int main(){


char string [STRING_SIZE];
char control_check = 0;
int sum = 0;
int control_digit;
int year = 0 ;
int leap_year = FALSE;
int month = 0;
int months_arr[MONTHS_ARR_SIZE] = {31,28,31,30,31,30,31,31,30,31,30,31};
int day = 0;
int correct_format = TRUE;

printf("Skriv personnummer YYMMDD-NNNN \n");
fgets(string,sizeof(string),stdin);             // get input from user


    control_check = string[CONTROL_DIGIT];          //save the last digit for control_checking control digit



for(int i = 0; i < STRING_SIZE -1; i++)
{
    

    if (string[i] < '0' && i != HYPHEN|| string[i] > '9' && i != HYPHEN || i == HYPHEN && string[i] != '-')
    {
        printf("Inte korrekt format\n");            //control_checking if the input format is correct or not
        correct_format = FALSE;
        break;
    }


    if(i == 1){

        year = (string[0] -'0')*DECADE + (string[1] -'0');          //sets a variabel to the year and control_checks for leap_year year

        if (year > CURRENT_YEAR)
        {
            year += 1900; 
                                                    // only control_checks 1925-2024 because only two digits in input
        }
        else{
            year += 2000;
            
        }

        if (year % LEAP_YEAR_CHECK == 0 && year % LEAP_YEAR_CHECK_CENTURY != 0 || year % LEAP_YEAR_CHECK_FOUR_HUNDRED == 0)
        {
            leap_year = TRUE;
        }
    }

    else if(i == 3){

    month = (string[2] -'0' ) *DECADE + (string[3] -'0');           //control_check month so that it is an actuall month

        if ( month < 1 || month > 12)
        {
        printf("month wrong\n");
        correct_format = FALSE;
        break;
                
        }
    }
    else if(i == 5){

    day = (string[4] -'0') *DECADE + (string[5] -'0');          // control_check days so it matches the days in a month and leap_year day

        if (leap_year == TRUE)
        {
            months_arr[1] = FEBRUARY_leap_year;
        }
        

        if ( day < 1 || day > months_arr[month -1])
        {
        printf("day wrong\n");
        correct_format = FALSE;
        break;
                
        }
    }

    

}



for(int i = 0; i < STRING_SIZE-2; i++)
{

if (i % 2 == 0 && i < HYPHEN || i > HYPHEN && (i -1)% 2 == 0)       // starting luhn algorithm with alternating multiplication on all numbers except the last digit
    {
        string[i] = (string[i] -'0') * ALTERNATE_DUBBEL;
    }
    else if (i != HYPHEN){
        string[i] = (string[i] -'0') * ALTERNATE_MULT_ONE;
    }

}




for (int i = 0; i < STRING_SIZE -2; i++)              // sum numbers over 9 according to luhn except the last digit and add 1, but subtracting 9 works the same
{
    if(string[i] > 9 & i != HYPHEN)
    {
        string[i] = (string[i] -9);
        sum += string[i];
    }
    else if (i != HYPHEN){
        sum += string[i];
    }
}

 control_digit = (LUNH_ALGORITHM_MODULO - (sum % LUNH_CORRECTION_DIVISOR)) % LUNH_CORRECTION_DIVISOR;          // calculate the control digit


if (control_digit == (control_check) -'0' && correct_format == TRUE)               // control_check the control digit if it matches the input
{
    printf("Ditt personnummer är korrekt\n");
}
else{
    printf("Ditt personnummer är inte korrekt\n"); 
}

return 0;

}
