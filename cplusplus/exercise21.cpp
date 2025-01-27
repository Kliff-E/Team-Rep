#include <iostream>
#include <cassert>
#include "exercise21.h"

bool stack::push(int x)
{
    if (top >= (SIZE - 1))

        assert(!isFull() && "Stack Overflow");

        arr[++top] = x;
        std::cout << x << " pushed into stack\n";
        return true;
}

int stack::pop()
{
    assert(!isEmpty() && "Stack Underflow");
    int x = arr[top--];
    return x;
    
}
int stack::get()
{
    assert(!isEmpty() && "Stack is Empty");
    int x = arr[top];
    return x;
}
int stack::getStackSize()
{
    return top + 1;
}
bool stack::empty()
{
    top = -1;
    std::cout << "Stack has been cleared" << std::endl;

    return 0;
}

bool stack::isEmpty()
{
    return (top < 0);
}

bool stack::isFull()
{
    int status = false;
    if(getStackSize() == 10)
    {
        status = true;
    }
    return status;
}