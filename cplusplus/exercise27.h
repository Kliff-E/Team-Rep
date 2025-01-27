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
#ifndef EXERCISE27_H
#define EXERCISE27_H

#include <iostream>
#include <cstddef>

template <typename T>

class Queue
{
    struct node_t
    {
        T data;
        node_t *next;
        node_t(T _data, node_t *ptr) : data{_data}, next{ptr} {}
    };

    node_t *head{nullptr};
    node_t *tail{nullptr};
    size_t elem_num{0};

public:
    Queue() = default;
    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;

    bool enqueue(const T &value)
    {
        bool status{false};

        node_t *node = new (std::nothrow) node_t{value, nullptr};

        if (node != nullptr)
        {
            if (tail == nullptr)
            {
                head = node;
                tail = head;
            }
            else
            {
                tail->next = node;
                tail = node;
            }

            status = true;
            elem_num++;
        }

        return status;
    }

    bool dequeue(T &elem)
    {
        bool status{false};

        if (head != nullptr)
        {
            status = true;
            elem = head->data;
            node_t *temp{head};
            head = head->next;
            delete temp;
            elem_num--;
        }

        if (head == nullptr)
        {
            tail = nullptr;
        }

        return status;
    }

    size_t available(void)
    {

        return elem_num;
    }

    void clear(void)
    {
        while (head != nullptr)
        {
            node_t *temp{head};
            head = head->next;
            delete temp;
        }

        elem_num = 0;
    }

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