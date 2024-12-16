#include <stdio.h>

#define arr_size 12
#define string_size 12
#define decade 10
#define LUNH_ALGORITHM_MODULO 10
#define LUNH_CORRECTION_DIVISOR 10
#define hyphen 6
#define february_leap 29
#define true 1
#define false 0




int main(){


char string [string_size];
char check;
int sum;
int control_digit;
int year;
int leap = false;
int month;
int arr[arr_size] = {31,28,31,30,31,30,31,31,30,31,30,31};
int day;
int korrekt = true;

printf("Skriv personnummer YYMMDD-NNNN \n");
fgets(string,sizeof(string),stdin);             // get input from user


    check = string[10];          //save the last digit for checking control digit



for(int i = 0; i <= arr_size -2; i++)
{
    

    if (string[i] < '0' && i != hyphen|| string[i] > '9' && i != hyphen || i == hyphen && string[i] != '-')
    {
        printf("Inte korrekt format\n");            //checking if the input format is correct or not
        korrekt = 0;
        break;
    }


    if(i == 1){

        year = (string[0] -'0')*decade + (string[1] -'0');          //sets a variabel to the year and checks for leap year

        if (year > 24)
        {
            year += 1900; 
            printf("%d\n", year);                                         // only checks 1924-2024 because only two digits in input
        }
        else{
            year += 2000;
            printf("%d\n", year);
        }

        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            //printf("leap year\n");
            leap = 1;
        }
    }

    else if(i == 3){

    month = (string[2] -'0' ) *decade + (string[3] -'0');           //check month so that it is an actuall month
   // printf("%d %d\n", month, arr[month -1]);

        if ( month < 1 || month > 12)
        {
        printf("month wrong\n");
        korrekt = 0;
        break;
                
        }
    }
    else if(i == 5){

    day = (string[4] -'0') *decade + (string[5] -'0');          // check days so it matches the days in a month and leap day
    //printf("%d\n", day);
        if (leap == true)
        {
            arr[1] = february_leap;
        }
        

        if ( day < 1 || day > arr[month -1])
        {
        printf("day wrong\n");
        korrekt = false;
        break;
                
        }
    }

    

}


for(int i = 0; i <= arr_size-2; i++)
{

if (i % 2 == 0 && i < hyphen || i > hyphen && (i -1)% 2 == 0)       // starting luhn alghrithm
    {
        string[i] = (string[i] -'0') * 2;
    }
    else if (i != hyphen){
        string[i] = (string[i] -'0') * 1;
    }

}

for (int i = 0; i <= arr_size-2; i++)              
{
    printf("%d ", string[i]);
}

printf("\n");


for (int i = 0; i < arr_size -2; i ++)              // sum numbers over 9 according to luhn 
{
    if(string[i] > 9 & i != hyphen)
    {
        string[i] = (string[i] -10) +1;
        sum += string[i];
    }
    else if (i != hyphen){
        sum += string[i];
    }
}

 control_digit = (LUNH_ALGORITHM_MODULO - (sum % LUNH_CORRECTION_DIVISOR)) % LUNH_CORRECTION_DIVISOR;          // calculate the control digit

/*for (int i = 0; i <= 10; i++)
{
    printf("%c ", string[i]);
}

printf("\n");

for (int i = 0; i <= 10; i++)
{
    printf("%d ", string[i]);
}

printf("\n");

printf("%d", check[0]);

printf("\n");

printf("%d\n", sum);
printf("%d\n", control_digit);
printf("%c\n", check[0]);
printf("%d\n", string[10]);*/

if (control_digit == (check) -'0' && korrekt == true)               // check the control digit if it matches the input
{
    printf("Ditt personnummer är korrekt\n");
}
else{
    printf("Ditt personnummer är inte korrekt\n"); 
}


}