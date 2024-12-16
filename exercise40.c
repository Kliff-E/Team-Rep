#include <stdio.h>
#include <stdlib.h>
#include "exercise40.h"


void init_list(list_t* list) {
    list->head = NULL;
    list->size = 0;
}

node_t* create_node(int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
void add_sorted(list_t* list, int data) {
    node_t* new_node = create_node(data);
    
    // If the list is empty, the new node is the head
    if (list->head == NULL ) {
        list->head = new_node;
    } 
    else if(list->head->data >= data)
    {
        new_node->next = list->head;
        list->head->prev = new_node;  // Update the previous pointer of the old head
        list->head = new_node;
        
    }
    else {
        // Traverse to the end of the list
        node_t* temp = list->head;
        while (temp->next != NULL && data > temp->next->data) {

            temp = temp->next;
           
        }
        // Add the new node to the end
        new_node->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = new_node;  // Update the prev pointer of the next node
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    list->size++;
}
void remove_node(list_t* list, int data) 
{
     node_t* temp = list->head;
     while (temp != NULL) 
    {
     if (temp->data == data) 
    {
        // If it's the only node in the list
        if (temp->prev == NULL && temp->next == NULL) 
        {
        list->head = NULL;
        } 
        else if (temp->prev == NULL) 
        {  
        // It's the head node
        list->head = temp->next;
        temp->next->prev = NULL;
        } 
        else if (temp->next == NULL) 
        {  
        // It's the tail node
        temp->prev->next = NULL;
        } 
        else 
        {  // It's somewhere in the middle
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        }
    free(temp);
    list->size--;
    return;
    }

    
    temp = temp->next;
    }

    
    printf("Data not found in the list.\n");
    
}

void change_data(list_t* list, int old_data, int new_data)
{
    
    remove_node(list, old_data);

    add_sorted(list, new_data);
    

}

void search_data(list_t* list, int data) 
{
     node_t* temp = list->head;
     while (temp != NULL) 
    {
     if (temp->data == data) 
    {
        printf("%d\n", temp->data);
        return;
    }

    
    temp = temp->next;
    }
}

int number_of_elements(list_t* list) 
{
     node_t* temp = list->head;
     int number = 0;
     while (temp != NULL) 
    {
        number++;
    temp = temp->next;
    }
    return number;


    
    printf("Data not found in the list.\n");
    
}


void print_list(list_t* list, int elements)
{
     if (list->head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    node_t* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    printf("number of elements: %d\n", elements);
}

void delete_list(list_t* list) 
{
     node_t* temp = list->head;
     node_t* nextNode;
     while (temp != NULL) 
    {
    nextNode = temp->next;
    free(temp);
    temp = nextNode;
    list->size--;
    }


    
    printf("List deleted\n");
    
}
