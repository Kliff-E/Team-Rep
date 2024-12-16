#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "arraystack.h"

int arr[MAX_SIZE];
int front = 0;
int rear = 0;

void init()
{
   if (front != -1)
    {
     front = -1;
     rear = -1;
    }
}

// Function to check if the stack is full
int isFull() {
    if (rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the stack is empty
int isEmpty() {
    
    return 0;
}

 int stack_push(int value) {
    if (isFull()) {
        printf("stack is full! Cannot push %d\n", value);
        return 0;
    }
    if (front == -1) {  // If stack is empty, set front to 0
        front = 0;
    }
    rear++;
    arr[rear] = value;
    printf("%d pushed to stack\n", value);
}

// Function to stack_pop (remove element) from the stack
int stack_pop() {
    if (isEmpty()) {
        printf("stack is empty! Cannot pop\n");
        return -1;  // Return -1 to indicate empty stack
    }
    int stack_popdValue = arr[rear];
    if (front == rear) {  // If there's only one element in the stack
        front = rear = -1;  // Reset the stack
    } else {
        rear--;
    }
    return stack_popdValue;
}

void display_stack() {
    if (isEmpty()) {
        printf("stack is empty\n");
        return;
    }
    printf("stack elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

