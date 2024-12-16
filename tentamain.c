#include <stdio.h>
#include "tenta.h"
#include "stdlib.h"

int main()
{
    // start the program and setting number of users
     int id = 0;
     int number_of_users = 0;

     user_t *user = malloc(sizeof(user_t) * MAX_USER);
     // open file or create one
     FILE *file = fopen("tenta.bin", "ab");
     if (file == NULL)
     {
         perror("Error opening file");
         exit(0);
    }
    fclose(file);
    // set the number of users from file and then set id to that.
    number_of_users = init_file(user, &number_of_users);

    id = number_of_users;
    // start the program with the main menu.
    main_menu(user, id, number_of_users);

        return 0;
}