#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_SIZE 6


int arr[MAX_SIZE];
int front = 0;
int rear = 0;
size_t size;

void init();
int isFull();
int isEmpty();
int enqueue(int *arr, int value);
int dequeue(int *arr);
void displayQueue();

int main()
{

    init();  // Initialize the queue

    enqueue(arr,10);
    enqueue(arr,20);
    enqueue(arr,30);
    enqueue(arr,40);
    enqueue(arr,50);
    enqueue(arr,60);  // This will show an error message because the queue is full

    displayQueue();

    printf("Dequeued: %d\n", dequeue(arr));
    printf("Dequeued: %d\n", dequeue(arr));
    




    displayQueue();



    return 0;
}

void init()
{
   if (front != -1)
    {
     front = -1;
     rear = -1;
     size = 0;
    }
}

// Function to check if the queue is full
int isFull() {
    if (rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    
    return 0;
}

 int enqueue(int *arr, int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return 0;
    }
    if (front == -1) {  // If queue is empty, set front to 0
        front = 0;
    }
    rear++;
    arr[rear] = value;
    printf("%d enqueued to queue\n", value);
}

// Function to dequeue (remove element) from the queue
int dequeue(int *arr) {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;  // Return -1 to indicate empty queue
    }
    int dequeuedValue = arr[front];
    if (front == rear) {  // If there's only one element in the queue
        front = rear = -1;  // Reset the queue
    } else {
        front++;
    }
    return dequeuedValue;
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

