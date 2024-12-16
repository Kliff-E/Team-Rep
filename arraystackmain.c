#include <stdio.h>
#include "arraystack.h"


int main()
{

    init();  // Initialize the stack

    stack_push(10);
    stack_push(20);
    stack_push(30);
    stack_push(40);
    stack_push(50);
    stack_push(60);  // This will show an error message because the stack is full

    display_stack();

    printf("popped: %d\n", stack_pop());
    printf("popped: %d\n", stack_pop());
    




    display_stack();



    return 0;
}