#ifndef EXERCISE_H
#define EXERCISE_H

typedef struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    }node_t;


typedef struct list
    {
        int size;
        node_t* head;
    }list_t;

void init_list(list_t* list);
node_t* create_node(int data);
void add_sorted(list_t* list, int data);
void remove_node(list_t* list, int data);
void change_data(list_t* list,int old_data, int new_data);
void search_data(list_t* list, int data);
int number_of_elements(list_t* list);
void print_list(list_t* list, int elements);
void delete_list(list_t* list);




#endif