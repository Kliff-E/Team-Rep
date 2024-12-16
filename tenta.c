#include <stdio.h>

#include <stdint.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <stdbool.h>

#include "tenta.h"

bool main_menu(user_t* user,int id, int number_of_users)
{
    char choice = '0'; 
    int choice_case = 0;
    bool status = false;
    // format for main menu layout and look for input.
    (void)printf("\n");
    (void)printf("========= DB =========\n");
    (void)printf("C.Create a student\n");
    (void)printf("P.Print all students\n");
    (void)printf("U.Update a student\n");
    (void)printf("E.Exit\n");
    (void)printf("Enter your choice ");
    scanf("%c", &choice);

    getchar();

    status = true;

    //convert input to uppercase and check if it matches any option  
    if(toupper(choice) == 'C')
    {
        choice_case = CREATE;
    }
    else if(toupper(choice) == 'P')
    {
        choice_case = PRINT;
    }
    else if(toupper(choice) == 'U')
    {
        choice_case = UPDATE;
    }
    else if(toupper(choice) == 'E')
    {
        choice_case = EXIT; 
    }
    else{
        system("clear");
        (void)printf("Wrong input\n");
        main_menu(user, id,number_of_users);
    }
    // starting functions from input
    switch (choice_case)
    {
    case CREATE:
        number_of_users = generate_users(user, id, number_of_users);
        id++;
        if (!write_users_to_file(user, number_of_users))
        {
        (void)printf("Failed to read users from the file!\n");
        exit(1);
        }
        break;
    
    case PRINT:
        if (!read_users_from_file(user, &number_of_users))
        {
        (void)printf("Failed to read users from the file!\n");
        exit(1);
        }
        print_user(user, &number_of_users);
        break;
    case UPDATE:
        change_user_name(user,&number_of_users);
        if (!write_users_to_file(user, number_of_users))
        {
        (void)printf("Failed to read users from the file!\n");
        exit(1);
        }
        break;
    case EXIT:
        return status;
    }
    //return to main menu after function
    main_menu(user, id,number_of_users);
}
// check file at the start to check data in file.
int init_file(user_t* user, int* number_of_users)
{
    int count = 0;
    FILE *file = fopen("tenta.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }

    // Read the data from the file and store it in 'user'

       


    fclose(file);

    return *number_of_users;
}
// create users
int generate_users(user_t *user, int id, int number_of_users)
{
        //get data for student user form
        int age_save;
        //int input_error = 0;
        (void)printf("Name of student\n");
    
        scanf("%s", &user[number_of_users].name[0]);
    

        getchar();

        (void)printf("Age of student\n");
        scanf("%d", &age_save);

        getchar();

        if(age_save > 255 || age_save <=0)
        {
        printf("Wrong Input\n");
        generate_users(user, id, number_of_users);

        }
        else
        {
            user[number_of_users].age = age_save;
        }
        
        //if(input_error == 0){
        user[number_of_users].id = number_of_users + ID_START;  // ID starts from 1
        number_of_users++;
        system("clear");
       // }
        return number_of_users;
}
// write users to the file
bool write_users_to_file(user_t *user, int number_of_users) {
    bool status = false;
    FILE *file = fopen("tenta.bin", "wb");
    system("clear");
    if (file == NULL) 
    {
        perror("Error opening file");
        exit(0);
    }
    status = true;
    fwrite(user, sizeof(user_t), number_of_users, file);
    fclose(file);
    return status;
}
// read users from file
bool read_users_from_file(user_t *user, int *number_of_users) 
{
    bool status = false;
    *number_of_users = init_file(user, number_of_users);
    status = true;
    FILE *file = fopen("tenta.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }
    while (fread(user, sizeof(user_t), 1, file))
    {
        printf("id:%d %s\n", user->id, user->name);
       
    }
    status = true;
    if (number_of_users == 0)
    {
        perror("Error reading file or file is empty");
    }

   
   fclose(file);
    return status;
}
// change data in the student form
void change_user_name(user_t *user, int* number_of_users) {

    char new_name[NAME_LENGTH];
    int new_age = 0;
    int choice = 0;

    // get new data from input
    (void)printf("Change student from id\n");
    scanf("%d", &choice);

    getchar();

    (void)printf("Change student Name\n");
    scanf("%s", new_name);

    (void)printf("%s\n", new_name);
    getchar();

    (void)printf("Change student age\n");
    scanf("%d", &new_age);
    getchar();

    if(new_age > 255 || new_age <=0)
    {
    system("clear");
    printf("Wrong Input\n");
    change_user_name(user, number_of_users);

    }
    else{

    // overwrite the old data with the new
    int id = choice;  // Change the user with ID 

    for (int i = 0; i < *number_of_users; i++) {
        if (user[i].id == id) 
        {

            if(sizeof(new_name) > NAME_LENGTH)
            {
                (void)printf("Too large name");
                main_menu(user, id,*number_of_users);

            }
            strncpy(user[i].name, new_name, NAME_LENGTH);
            user[i].name[NAME_LENGTH] = '\0';  // Ensure null-termination
            user[i].age = new_age;
            (void)printf("Student with ID %d name has been changed to '%s' and age too '%d'.\n", id, new_name, new_age);
        }
    }
    
    
    (void)printf("Student with ID %d not found.\n", id);
    }
}
// print the student information to the terminal
void print_user(user_t* user,int* number_of_users)
{

    (void)printf("ID:   Age:    Name:     \n");
    (void)printf("========================\n");

    while (fread(user, sizeof(user_t), 1, file))
    {
        (void)printf("%hhu     %hhu      %s\n", user[i].id, user[i].age, user[i].name);
        printf("id:%d %s\n", user->id, user->name);
    }

    

    }
   

}