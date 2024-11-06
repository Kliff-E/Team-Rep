#include <stdio.h>
#include <ctype.h>
#include <string.h>

char string [20] = {0};
int year;
int leap = 0;
int month;
int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int day;
int hour;
int minut;
int sek;

int main(){

printf("Write the date and time YYYY-MM-DD HH:mm:ss\n");
fgets(string,sizeof(string),stdin);


for (int i = 0; i <= strlen(string); i++){
    
        if (!isdigit(string[i]) && i != 4 && i != 7 && i!= 10 && i != 13 && i != 16 && i !=19){

            printf("not correct format %s", string);
            printf("\n%d\n", i);
            break;
        }
        else if(!isblank(string[i]) && i ==10 ){

            printf("not correct format %s", string);
            printf("\n%d\n", i);
            break;
        }
        else if(i == 4 && string[i] != '-'||i == 7 && string[i] != '-'){

            printf("not correct format %s", string);
            printf("\n%d\n", i);
            break;
        }
        else if(i == 13 && string[i] != ':'|| i == 16 && string[i] != ':'){

            printf("not correct format %s", string);
            printf("\n%d\n", i);
            break;
        }
        else if(i == 3){

            year = (string[0] -'0') *1000 + (string[1] -'0') *100 + (string[2] -'0') *10 + (string[3] -'0');
            printf("%d\n", year);

            if (i == 3 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0 && i == 3)
            {
                printf("leap year\n");
                leap = 1;
            }
        }
        else if(i == 6){

            month = (string[5] -'0') *10 + (string[6] -'0');
            printf("%d %d\n", month, arr[month -1]);

            if ( month == 0 || month > 12)
            {
                printf("month wrong\n");
                break;
                
            }
        }
        else if(i == 9){

            day = (string[8] -'0') *10 + (string[9] -'0');
            printf("%d\n", day);
            if (leap == 1)
            {
                arr[1] = 29;
            }
            

            else if ( day == 0 || day > arr[month -1])
            {
                printf("day wrong\n");
                break;
                
            }
        }

        else if( i == 12 ){

          hour = (string[11] -'0') *10 + (string[12] -'0');  
          printf("%d\n", hour);

          if( hour > 23)
          {
            printf("hour wrong\n");
            break;
          }
        }

        else if( i == 15 ){

          minut = (string[14] -'0') *10 + (string[15] -'0');  
          printf("%d\n", minut);

          if( minut == 0|| minut > 59)
          {
            printf("minut wrong\n");
            break;
          }
        }

        else if( i == 18 ){

          sek = (string[17] -'0') *10 + (string[18] -'0');  
          printf("%d\n", sek);

          if( sek == 0|| sek > 59)
          {
            printf("second wrong\n");
            break;
          }
        }

        else if ( i == strlen(string)){

            printf("correct format %s\n", string);
            printf("%c\n", string[i]);
        }
    }
return 0;
}