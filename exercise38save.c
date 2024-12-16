
#include <stdio.h>

#include <stdint.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>


#define NAME_LENGTH 8
#define USER_AMOUNT 4

/*Create record
read record
update record
delete record
add a user 
delete user*/

typedef struct

{

    char name[NAME_LENGTH+1];

    int id;

} user_t;

int init_file(user_t* user, int id, int number_of_users);
void main_menu(user_t* user, int id);
int generate_users(user_t *user, int id);
void delete_user(user_t* user, int id);
void write_users_to_file(user_t *user);
void read_users_from_file(user_t *user);
void change_user_name(user_t *user);
void print_user(user_t* user);


int main()
{

     int id = 0;
     int number_of_users = 0;

    srand(time(NULL));

    user_t user[USER_AMOUNT+1];

    number_of_users = (user,id, number_of_users);

    id = number_of_users;

    main_menu(user, id);

        return 0;
}
void main_menu(user_t* user,int id)
{
    int choice = 0; 
    printf("\n");
    printf("1.Create User Record\n");
    printf("2.Read User Record\n");
    printf("3.Update User Record\n");
    printf("4.Delete User Record\n");
    printf("5.Exit\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        id = generate_users(user, id);
        write_users_to_file(user);
        break;
    
    case 2:
        read_users_from_file(user);
        break;
    case 3:
        change_user_name(user);
        write_users_to_file(user);
        break;
    case 4:
        delete_user(user, id);
        write_users_to_file(user);
        break;
    case 5:
        return;
    }
    print_user(user);
    main_menu(user, id);
}
int init_file(user_t* user, int id, int number_of_users)
{
    FILE *file = fopen("user.bin", "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }

    id = fread(user, sizeof(user_t), USER_AMOUNT, file);
    fclose(file);

    return id;
}

int generate_users(user_t *user, int id)
{
const char charset[] = "abcdefghijklmnopqrstuvwxyz";

        for (int j = 0; j < NAME_LENGTH; j++) 
        {
        user[id].name[j] = charset[rand() % (sizeof(charset) - 1)];
        }
        user->name[NAME_LENGTH] = '\0';  // Null-terminate the string
        
        user[id].id = id + 1;  // ID starts from 1
        id++;
        system("clear");
        return id;
}

void delete_user(user_t* user, int id)
{
    int choice = 0;
    system("clear");
    printf("Delete user from id\n");
    scanf("%d", &choice);

    if (user[choice].id == id)
    {
        for (int j = 0; j < NAME_LENGTH; j++) 
        {
        memset(user[choice].name, 0, sizeof(user[choice].name)); 
        }
    }
    return;
    
}

void write_users_to_file(user_t *user) {
    FILE *file = fopen("user.bin", "wb");
    system("clear");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }
    fwrite(user, sizeof(user_t), USER_AMOUNT, file);
    printf("Users have been written to the file '%s'.\n", "user.bin");
    fclose(file);
}

void read_users_from_file(user_t *user) 
{
    FILE *file = fopen("user.bin", "rb");
    system("clear");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }
    fread(user, sizeof(user_t), USER_AMOUNT, file);
    printf("Users have been read from the file '%s'.\n", "user.bin");
    fclose(file);
}

void change_user_name(user_t *user) {

    const char *new_name = "changed";
    int choice = 0;
    system("clear");

    printf("Change user from id\n");
    scanf("%d", &choice);

     int id = choice;  // Change the user with ID 

    for (int i = 0; i < USER_AMOUNT; i++) {
        if (user[i].id == id) {
            strncpy(user[i].name, new_name, NAME_LENGTH);
            user[i].name[NAME_LENGTH] = '\0';  // Ensure null-termination
            printf("User with ID %d name has been changed to '%s'.\n", id, new_name);
        }
    }
    printf("User with ID %d not found.\n", id);
}

void print_user(user_t* user)
{

    for(int i = 0; i < USER_AMOUNT; i++)
    {

        if(user[i].id == 0)
        {
            break;
        }

    printf("User:%d\nUsername:%s\n Id:%hhu\n", i +1, user[i].name, user[i].id);

    }
    return;

}