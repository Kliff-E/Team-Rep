#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node
    {
        int data;
        struct node *next;
    }node_t;


typedef struct list
    {
        int size;
        node_t* head;
    }list_t;

void init_list(list_t* list);
node_t* create_node(int data);
int enqueue(list_t* list, int data);
int dequeue(list_t* list);
void empty_list(list_t* list);
void print_list(list_t* list);

int main()
{
    list_t list;
    init_list(&list);

    enqueue(&list,10);
    enqueue(&list,20);
    enqueue(&list,30);
    enqueue(&list,40);
    enqueue(&list,50);
    enqueue(&list,60);  // This will show an error message because the queue is full

    print_list(&list);

    dequeue(&list);
    dequeue(&list);

    print_list(&list);

    empty_list(&list);

    print_list(&list);


    return 0;
}

void init_list(list_t* list) {
    list->head = NULL;
    list->size = 0;
}

node_t* create_node(int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int enqueue(list_t* list, int data) {

    node_t* new_node = create_node(data);
    
    if (list->head == NULL) {  // If queue is empty, set front to 0
        list->head = new_node;
    }
    else{
    node_t* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
    printf("%d enqueued to queue\n", data);
}

int dequeue(list_t* list) {
    if (list->head == NULL) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;  // Return -1 to indicate empty queue
    }

    node_t* temp = list->head;
    int dequeued_value = temp->data;

    list->head = list->head->next;
        
        free(temp);

    printf("%d dequeued from queue\n", dequeued_value);
    list->size--;
    return;
}

void empty_list(list_t* list)
{

    while (list->head != NULL) {

        dequeue(list);
    
    }

    printf("list is empty\n");
    

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
    printf("list size:%d\n", list->size);
}