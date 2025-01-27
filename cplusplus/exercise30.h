/**
 * @file exercise30.h
 * @author Kliff Elvin
 * @brief Make an uncopyable template stack class using a linked list to provide the following functions:

          A function to push a data element to a stack.
          A function to pop a data element from a stack.
          A function to get the number of data elements stored in a stack.
          A function to clear a stack.

          Test the class using assertions and ensure that all the allocated memory blocks are released.

 * @version 0.1
 * @date 2025-01-20
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef EXERCISE30_H
#define EXERCISE30_H

#include <iostream>

template <typename T>

class Stack
{
    struct node_t
    {
        int data;
        node_t *next;
        node_t(int _data, node_t *ptr) : data{_data}, next{ptr} {}
    };

    node_t *top{nullptr};
    size_t elem_num{0};

public:
    Stack() = default;
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    bool push(int value)
{
        bool status { false };

    node_t *node = new (std::nothrow) node_t{value, top};

    if (node != nullptr)
    {
        status = true;
        elem_num++;
        top = node;
    }

    return status;
}

bool pop(int &elem)
{
    bool status{false};

    if (top != nullptr)
    {
        status = true;
        elem = top->data;
        node_t *temp{top};
        top = top->next;
        delete temp;
        elem_num--;
    }

    return status;
}

    size_t available(void)
    {

        return elem_num;
    }

    void clear(void)
    {
        while (top != nullptr)
        {
            node_t *temp{top};
            top = top->next;
            delete temp;
        }

        elem_num = 0;
    }

    friend std::ostream &operator<<(std::ostream &out, const Stack &stack)
    {
        node_t *cursor{stack.top};

        while (cursor != nullptr)
        {
            out << cursor->data << "\t";
            cursor = cursor->next;
        }

        return out;
    }

    ~Stack()
    {
        clear();
        std::cout << "....." << std::endl;
    }
};

#endif