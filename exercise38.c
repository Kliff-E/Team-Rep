
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

//int init_file(user_t* user, int number_of_users);
int init_file(user_t* user, int* number_of_users);
void main_menu(user_t* user, int id, int number_of_users);
int generate_users(user_t *user, int id, int number_of_users);
void delete_user(user_t* user, int id, int number_of_users);
void append_users_to_file(user_t *user, int number_of_users);
void write_users_to_file(user_t *user,int number_of_users);
void read_users_from_file(user_t *user, int* number_of_users);
void change_user_name(user_t *user);
void print_user(user_t* user, int number_of_users);
int remove_file ();


int main()
{

     int id = 0;
     int number_of_users = 0;

    srand(time(NULL));

    user_t user[USER_AMOUNT+1];

    FILE *file = fopen("user.bin", "ab");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }
    rewind(file);
    fclose(file);

    number_of_users = init_file(user, &number_of_users);

    printf("%d", number_of_users);

    id = number_of_users;

    main_menu(user, id, number_of_users);

        return 0;
}
void main_menu(user_t* user,int id, int number_of_users)
{
    int choice = 0; 
    printf("\n");
    printf("1.Create User Record\n");
    printf("2.Read User Record\n");
    printf("3.Update User Record\n");
    printf("4.Delete User Record\n");
    printf("5.Exit\n");
    printf("6. Remove file\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        number_of_users = generate_users(user, id, number_of_users);
        id++;
        write_users_to_file(user, number_of_users);
        break;
    
    case 2:
        read_users_from_file(user,&number_of_users);
        break;
    case 3:
        change_user_name(user);
        write_users_to_file(user, number_of_users);
        break;
    case 4:
        delete_user(user, id, number_of_users);
        write_users_to_file(user, number_of_users-1);
        break;
    case 5:
        return;
    case 6:
        remove_file();
        break;
    }
    print_user(user, number_of_users);
    main_menu(user, id,number_of_users);
}
/*int init_file(user_t* user, int number_of_users)
{
    FILE *file = fopen("user.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }

    number_of_users = fread(user, sizeof(user_t), USER_AMOUNT, file);
    printf("%d\n", number_of_users);
    fclose(file);

    return number_of_users;
}*/

int init_file(user_t* user, int* number_of_users)
{
    FILE *file = fopen("user.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }

    // Read the data from the file and store it in 'user'
    *number_of_users = fread(user, sizeof(user_t), USER_AMOUNT, file);

    // Print the number of users read
    printf("Number of users read from file: %d\n", *number_of_users);

    fclose(file);

    return *number_of_users;
}

int generate_users(user_t *user, int id, int number_of_users)
{
const char charset[] = "abcdefghijklmnopqrstuvwxyz";


        for (int j = 0; j < NAME_LENGTH; j++) 
        {
        user[number_of_users].name[j] = charset[rand() % (sizeof(charset) - 1)];
        }
        user->name[NAME_LENGTH] = '\0';  // Null-terminate the string
        
        user[number_of_users].id = number_of_users + 1;  // ID starts from 1
        number_of_users++;
        system("clear");
        return number_of_users;
}

void delete_user(user_t* user, int id, int number_of_users) 
{
    int choice = 0;
    printf("Delete user by ID: ");
    scanf("%d", &choice);

    // Find the user with the specified ID
    int user_found = 0;
    user_t temp[number_of_users-1];
    int j = 0;

    for (int i = 0; i < number_of_users; i++) {
        if (user[i].id == choice) {
            user_found = 1;
            continue;

        }
        temp[j] = user[i];
        j++;
        
    }

    for (int i = 0; i < number_of_users-1; i++)
    {
        user[i] = temp[i];
    }
    number_of_users--;
    

    if (!user_found) {
        printf("User with ID %d not found.\n", choice);
    } else {
         FILE *file = fopen("user.bin", "w+b");
            if (file == NULL) {
            perror("Error opening file");
            exit(0);
            }
            fwrite(user,sizeof(user_t), number_of_users, file);
            fclose(file);
        printf("User with ID %d deleted successfully.\n", choice);
        
    }
    return;
}


void append_users_to_file(user_t *user, int number_of_users) {
    FILE *file = fopen("user.bin", "ab");
    system("clear");
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }
    fwrite(user, sizeof(user_t), number_of_users, file);
    printf("Users have been written to the file '%s'.\n", "user.bin");
    fclose(file);
}


void write_users_to_file(user_t *user, int number_of_users) {
    FILE *file = fopen("user.bin", "wb");
    system("clear");
    if (file == NULL) 
    {
        perror("Error opening file");
        exit(0);
    }
    fwrite(user, sizeof(user_t), number_of_users, file);
    printf("Users have been written to the file '%s'.\n", "user.bin");
    fclose(file);
}

void read_users_from_file(user_t *user, int* number_of_users) 
{
    FILE *file = fopen("user.bin", "rb");
    system("clear");
   // rewind(file);
    if (file == NULL) {
        perror("Error opening file");
        exit(0);
    }
    *number_of_users = fread(user, sizeof(user_t), USER_AMOUNT, file);
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

void print_user(user_t* user,int number_of_users)
{

    for(int i = 0; i < number_of_users; i++)
    {

        if(user[i].id == 0)
        {
            break;
        }

    printf("User:%d\nUsername:%s\n Id:%hhu\n", i +1, user[i].name, user[i].id);

    }
    return;

}

int remove_file ()
{
  if( remove( "user.bin" ) != 0 )
    perror( "Error deleting file" );
  else
    puts( "File successfully deleted" );
  return 0;
}