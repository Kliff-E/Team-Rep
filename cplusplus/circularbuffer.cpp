#ifndef TENTA2_H
#define TENTA2_H

#include <iostream>
#include <cstddef>
#include <cassert>

template <typename T>
class Queue
{
private:
    T arr[4];           // Array to hold data
    size_t head{0};     // Index of the head (oldest element)
    size_t tail{0};     // Index of the tail (next insertion point)
    size_t elem_num{0}; // Number of elements in the buffer

public:
    Queue() = default;
    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;

    bool enqueue(const T &value)
    {
        bool status = false;

        if (isFull())
        {
            // If the buffer is full, we overwrite the oldest element (head)
            arr[head] = value;
            head = (head + 1) % 4; // Circular increment
            tail = (tail + 1) % 4; // Circular increment
        }
        else
        {
            arr[tail] = value;
            tail = (tail + 1) % 4; // Circular increment
            elem_num++;
        }

        status = true;
        return status;
    }

    bool dequeue(T &elem)
    {
        bool status = false;

        if (!isEmpty())
        {
            elem = arr[head];
            head = (head + 1) % 4; // Circular increment
            elem_num--;
            status = true;
        }

        return status;
    }

    size_t available() const
    {
        return elem_num;
    }

    bool isEmpty() const
    {
        return elem_num == 0;
    }

    bool isFull() const
    {
        return elem_num == 4;
    }

    void read() const
    {
        std::cout << "Data in buffer: ";
        size_t index = head;
        for (size_t i = 0; i < elem_num; ++i)
        {
            std::cout << arr[index] << " ";
            index = (index + 1) % 4; // Circular increment
        }
        std::cout << std::endl;
    }

    void clear()
    {
        head = tail = elem_num = 0;
    }

    friend std::ostream &operator<<(std::ostream &out, const Queue &queue)
    {
        size_t index = queue.head;
        for (size_t i = 0; i < queue.elem_num; ++i)
        {
            out << queue.arr[index] << "\t";
            index = (index + 1) % 4; // Circular increment
        }
        return out;
    }

    ~Queue() = default;
};

int main(void)
{
    int value;
    Queue<decltype(value)> q;

    assert(0 == q.available());

    assert(q.enqueue(10));
    assert(1 == q.available());

    assert(q.enqueue(20));
    assert(2 == q.available());

    assert(q.enqueue(30));
    assert(3 == q.available());

    assert(q.enqueue(40));
    assert(4 == q.available());

    assert(q.enqueue(50));
    assert(4 == q.available()); // No change to available after enqueueing 50

    q.read();

    q.clear();
    assert(0 == q.available());

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

#endif
