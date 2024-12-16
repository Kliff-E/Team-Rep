#include <stdio.h>

#include "exercise38.h"

int main()
{

     int id = 0;

    user_t user[USER_AMOUNT+1];

    id = init_file(user);
    int number_of_users = id;


    main_menu(user, id, number_of_users);

        return 0;
}