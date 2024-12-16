/**
 * @file tenta.h
 * @author Kliff Elvin (elvinkliff@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef TENTA_H
#define TENTA_H
#include <stdbool.h>
// define hardcoded values.
#define NAME_LENGTH 32
#define MAX_USER 10
#define CREATE 1
#define PRINT 2
#define UPDATE 3
#define DELETE 4
#define REMOVE 6
#define EXIT 5
#define NULL_CHAR 1
#define ID_START 1

// a typedef struct to make a format for every student.
typedef struct

{

    char name[NAME_LENGTH];

    int age;

    int id;


} user_t;

// create prototypes(definitions) for functions.
int init_file(user_t* user, int* number_of_users);
bool main_menu(user_t* user, int id, int number_of_users);
int generate_users(user_t *user, int id, int number_of_users);
//void delete_user(user_t* user, int id, int number_of_users);
bool write_users_to_file(user_t *user,int number_of_users);
bool read_users_from_file(user_t *user, int *number_of_users);
void change_user_name(user_t *user, int* number_of_users);
void print_user(user_t* user, int* number_of_users);
int remove_file ();



#endif