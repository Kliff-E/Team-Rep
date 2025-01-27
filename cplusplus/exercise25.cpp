#include "exercise25.h"
#include <new>

bool Queue::enqueue(int value)
{
    bool status{false};

    node_t *node = new (std::nothrow) node_t{value, nullptr};

    if (node != nullptr)
    {
        if(tail == nullptr)
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

bool Queue::dequeue(int &elem)
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

    if(head == nullptr)
    {
        tail = nullptr;
    }

    return status;
}

size_t Queue::available(void)
{

    return elem_num;
}

void Queue::clear(void)
{
    while (head != nullptr)
    {
        node_t *temp{head};
        head = head->next;
        delete temp;
    }

    elem_num = 0;
}
