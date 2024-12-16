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
    char *input_name = NULL;  // Initializing input_name to NULL for getline
    int user_amount = 0;

    uint8_t input_age;

    // Ask for the number of users
    printf("Enter the amount of users:\n");
    scanf("%d", &user_amount);
    getchar();  // To consume the newline character left by scanf

    // Allocate memory for the array of pointers to person_t
    person_t **users = (person_t **)malloc(user_amount * sizeof(person_t *));
    if (users == NULL) {
        printf("Memory allocation for users failed.\n");
        return 1;
    }

    // Read data for each user
    for (int i = 0; i < user_amount; i++) {
        // Prompt for person name
        printf("Enter %d user name:\n", i + 1);
        getline(&input_name, &input_size, stdin);

        // Remove the newline character from the name
        input_name[strcspn(input_name, "\n")] = '\0';

        // Prompt for person age
        printf("Enter %d user age:\n", i + 1);
        scanf("%hhu", &input_age);
        getchar();  // Consume the newline character left by scanf

        // Create person and store in the array
        users[i] = create_person(input_name, input_age);
        if (users[i] == NULL) {
            printf("Failed to create user %d\n", i + 1);
            free(input_name);  // Free input_name before exit
            free(users);       // Free the users array
            return 1;
        }
    }

    // Print out the users' information
    for (int i = 0; i < user_amount; i++) {
        printf("User %d:\n", i + 1);
        printf("Username: %s\nAge: %hhu\n", users[i]->name, users[i]->age);
    }

    // Free memory for all users
    for (int i = 0; i < user_amount; i++) {
        free_person(users[i]);
    }

    // Free the array of pointers and input_name buffer
    free(users);
    free(input_name);

    return 0;
}

// Function to free the memory allocated for a person
static void free_person(person_t *account)
{
    if (account != NULL) {
        free(account->name);  // Free the name field
        free(account);         // Free the person struct
    }
}

// Function to create a new person with a given name and age
static person_t *create_person(char *name, uint8_t age)
{
    // Allocate memory for the person struct
    person_t *ptr = (person_t *)malloc(sizeof(person_t));
    if (ptr != NULL)
    {
        ptr->age = age;

        // Allocate memory for the name
        size_t len = strlen(name) + 1;
        ptr->name = (char *)malloc(len * sizeof(char));
        if (ptr->name != NULL)
        {
            strncpy(ptr->name, name, len);
        }
        else
        {
            free(ptr);  // If memory allocation for name fails, free person struct
            ptr = NULL;
        }
    }
    return ptr;
}
