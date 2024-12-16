#ifndef EXERCISE38_H
#define EXERCISE38_H


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

int init_file(user_t* user);
void main_menu(user_t* user, int id, int number_of_users);
void generate_users(user_t *user, int id);
void delete_user(user_t* user, int id);
void write_users_to_file(user_t *user, int number_of_users);
void read_users_from_file(user_t *user);
void change_user_name(user_t *user);
void print_user(user_t* user, int id);




#endif