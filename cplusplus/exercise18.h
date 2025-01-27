/**
 * @file exercise18.h
 * @author Kliff Elvin (elvinkliff@gmail.com)
 * @brief Make a multiple instance stack using a fixed size array of type int.
        The stack shall be tested using assertion and provide the following functions:
        A function to create a stack.
        A function to push a data element a stack.
        A function to get number of the data elements stored in a stack.
        A function to pop an element from a stack.
        A function to clear a stack
        A function to destroy a stack


 * @version 0.1
 * @date 2025-01-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef EXERCISE18_H
#define EXERCISE18_H

struct stack_t;

namespace stack


{
    constexpr int SIZE{10};

    stack_t *create(void);
    bool push(stack_t *stck, int value);
    bool pop(stack_t *stck, int &elem);
    int getStackSize(stack_t *stck);
    void empty(stack_t *stck);
    void destroy(stack_t *&stck);
}

#endif