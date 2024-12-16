#include <stdio.h>
#include <stdlib.h>


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


node_t* create_node(int data);
void init_list(list_t* list);
void add_to_end(list_t* list, int data);
void remove_from_end(list_t* list);
void print_list(list_t* list);

int main()
{
    /*node_t node1;
    node1.data = 1;
    node1.next = NULL;
    node1.prev = NULL;

    node_t node4;
    node4.data = 4;
    node4.next = NULL;
    node4.prev = &node1;

    node_t node2;
    node2.data = 2;
    node2.next = NULL;
    node2.prev = &node4;

    node_t node3;
    node3.data = 3;
    node3.next = NULL;
    node3.prev = &node2;

    node1.next = &node4;
    node4.next = &node2;
    node2.next = &node3;*/

    list_t list;
    init_list(&list);

    add_to_end(&list, 1);
    add_to_end(&list, 2);
    add_to_end(&list, 3);

    print_list(&list);

    remove_from_end(&list);

    print_list(&list);



    /*for (node_t *head = &node1; head != NULL; head = head->next )
    {
        printf("%d ", head -> data);
    }

    printf("\n");


    for (node_t *tail = &node3; tail != NULL; tail = tail->prev )
    {
        printf("%d ", tail -> data);
    }

    printf("\n");*/


    return 0;
}

node_t* create_node(int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void init_list(list_t* list) {
    list->head = NULL;
    list->size = 0;
}

void add_to_end(list_t* list, int data) {
    node_t* new_node = create_node(data);
    
    // If the list is empty, the new node is the head
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        // Traverse to the end of the list
        node_t* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Add the new node to the end
        temp->next = new_node;
    }
    list->size++;
}
void remove_from_end(list_t* list) {
    if (list->head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    // If there is only one element in the list
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        node_t* temp = list->head;
        while (temp->next != NULL && temp->next->next != NULL) {
            temp = temp->next;
        }
        // Remove the last node
        free(temp->next);
        temp->next = NULL;
    }
    list->size--;
}

void print_list(list_t* list) {
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
}