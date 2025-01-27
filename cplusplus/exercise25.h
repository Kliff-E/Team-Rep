/**
 * @file exercise25.h
 * @author Kliff Elvin
 * @brief Make an uncopyable queue class using a linked list to store and restore data of type int and
 *        to provide the following functions:
 *          1. A function to enqueue a data element to a queue.
 *          2. A function to dequeue a data element from a queue.
 *          3. A function to get the number of data elements stored in a queue.
 *          4. A function to clear a queue.
 *
 *        Test the class using assertions and ensure that
 *        all the allocated memory blocks are released
 * @version 0.1
 * @date 2025-01-17
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef EXERCISE25_H
#define EXERCISE25_H

#include <iostream>

class Queue
{
    struct node_t
    {
        int data;
        node_t *next;
        node_t(int _data, node_t *ptr) : data{_data}, next{ptr} {}
    };

    node_t *head{nullptr};
    node_t *tail{nullptr};
    size_t elem_num{0};

public:
    Queue() = default;
    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;

    bool enqueue(int value);

    bool dequeue(int &elem);

    size_t available(void);

    void clear(void);

    friend std::ostream &operator<<(std::ostream &out, const Queue &queue)
    {
        node_t *cursor{queue.head};

        while (cursor != nullptr)
        {
            out << cursor->data << "\t";
            cursor = cursor->next;
        }

        return out;
    }

    ~Queue() { clear(); }
};

#endif