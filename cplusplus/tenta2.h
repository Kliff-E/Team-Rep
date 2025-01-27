/**
 * @file tenta2.h
 * @author Kliff Elvin
 * @brief 
 * @version 0.1
 * @date 2025-01-17
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef TENTA2_H
#define TENTA2_H

#include <iostream>


template <typename T, int N>

class Buffer
{

    private:
        T arr[N];
        size_t head{0};
        size_t tail{0};
        size_t elem_num{0};

    public:
        Buffer() = default;
        Buffer(const Buffer &) = delete;
        Buffer &operator=(const Buffer&) = delete;


            bool write(const T &value)
        {
            bool status{false};

            if (isFull())
            {
                arr[head] = value;
                head =(head + 1) % 4;
                tail = (tail +1) % 4;
            }

            else
            {
                arr[tail] = value;
                tail = (tail +1) % 4;
                elem_num++;
            }

            status = true;
            return status;
    };

    size_t available()
    {

        return elem_num;
    }

    bool isEmpty()
    {
        return elem_num == 0;
    }

    bool isFull()
    {
        return elem_num == 4;
    }

    void read() const
    {
        std::cout << "Data in buffer" << std::endl;

        std::cout << *this << std::endl;
    }

    void clear(void)
    {
        head = 0;
        tail = 0;
        elem_num = 0;
    }

    friend std::ostream &operator<<(std::ostream &out, const Buffer &buffer)
    {
        if (buffer.elem_num == 0)
        {
            out << "Buffer is empty.";
        }

        else
        {
        size_t cursor = buffer.head;

        while (cursor != buffer.tail)
        {
            out << buffer.arr[cursor] << "\t";
            cursor = (cursor + 1) % 4;
        }
        }

        return out;
    }

    ~Buffer() { clear(); }
};

#endif