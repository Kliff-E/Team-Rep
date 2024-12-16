
#include <stdio.h>

#include <stdint.h>

#include <stdlib.h>

#include <string.h>

typedef struct

{

    char *name;

    uint8_t age;

} person_t;

static void free_person(person_t *account);
static person_t *create_person(char *name, uint8_t age);

 
int main(void)

{

    size_t input_size = 0;
    char *input_name = NULL;
    int user_amount = 0; 

    uint8_t input_age;

    printf("Enter the amount of users\n");
    scanf("%d", &user_amount);
    getchar();

    person_t **users = (person_t **)malloc(user_amount * sizeof(person_t *));
    if (users == NULL) {
        printf("Memory allocation for users failed.\n");
    
    }


    for(int i = 0; i < user_amount; i++)
    {

    (void)printf("Enter %d user name:\n", i +1);
    getline(&input_name, &input_size, stdin);

    input_name[strcspn(input_name, "\n")] = '\0';

    (void)printf("Enter %d user age:\n", i +1);
    scanf("%hhu", &input_age);
    getchar();


    users[i] = create_person(input_name, input_age);
    
    if (users[i] == NULL)
    {
        printf("Failed to create user %d\n", i +1);
        free(input_name);
        free(users);
    }

}

    for(int i = 0; i < user_amount; i++)
    {

    printf("User:%d\nUsername:%s\n Age:%hhu\n", i +1, users[i]->name, users[i]->age);
    free_person(users[i]);

    }
    
    
    free(users);
    free(input_name);


    return 0;

}

static void free_person(person_t *account)
{
    if(account !=NULL)
    {
    free((account)->name);
    free(account);
    }
}

static person_t *create_person(char *name, uint8_t age)
{

    person_t *ptr = (person_t *)malloc(sizeof(person_t));
    if (ptr != NULL)
    {
        ptr->age = age;
        size_t len = strlen(name) + 1;
        ptr->name = (char *)malloc(len * sizeof(char));
        if (ptr->name != NULL)
        {
            strncpy(ptr->name, name, len);
        }
        else
        {
            free(ptr);
            ptr = NULL;
        }
    }

    return ptr;

}

