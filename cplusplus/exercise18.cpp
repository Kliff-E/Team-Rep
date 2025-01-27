#include <iostream>
#include "exercise18.h"

struct stack_t
{
    int top;
    int array[stack::SIZE];
};

stack_t *stack::create(void)
{
    return new (std::nothrow) stack_t{-1, {}};
}

bool stack::push(stack_t *stck, int value)
{
    bool status{false};

    if (stck != nullptr)
    {
        if (stck->top < SIZE - 1)
        {
            stck->top++;
            status = true;
            stck->array[stck->top] = value;
        }
    }

    return status;
}

bool stack::pop(stack_t *stck, int &elem)
{
    bool status{false};

    if (stck != nullptr)
    {
        if (stck->top > -1)
        {
            elem = stck->array[stck->top];
            status = true;
            stck->top--;
        }
    }

    return status;
}

int stack::getStackSize(stack_t *stck)
{
    int num = -1;

    if (stck != nullptr)
    {
        num = stck->top + 1;
    }

    return num;
}
void stack::empty(stack_t *stck)
{
    if (stck != nullptr)
    {
        stck->top = -1;
        std::cout << "Stack has been cleared" << std::endl;
    }
}

void stack::destroy(stack_t *&stck)
{
    if (stck != nullptr)
    {
        delete stck;
        stck = nullptr;
    }
}