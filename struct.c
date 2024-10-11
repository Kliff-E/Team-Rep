#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

union{
    int id;
    char name [45];
    int password;


}user;

int main (){

srand(time(NULL));

user.id = 1;
printf("%d \n", user.id);
strcpy(user.name, "Kliff");

printf("%s \n", user.name);

user.password = rand() % 1000000 + 1;

printf("%d \n", user.password);

return 0;
}