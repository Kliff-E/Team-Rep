/**
 * @file exercise21.h
 * @author Kliff Elvin
 * @brief Implement and test a stack class using an array of type int whose size is a compile-time constant.
        The class shall provide the following function:
        A function to push a data element to a stack.
        A function to get number of the data elements stored in a stack.
        A function to pop an element from a stack.
        A function to check if a stack is full or not.
        A function to check if a stack is empty or not
        A function to clear a stack


 * @version 0.1
 * @date 2025-01-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef EXERCISE21_H
#define EXERCISE21_H

class stack
{

public:
    bool push(int x);
    int pop();
    int get();
    int getStackSize();
    bool empty();
    bool isFull();
    bool isEmpty();

private:
    static constexpr int SIZE{10};
    int arr[SIZE];
    int top{-1};
};

#endif