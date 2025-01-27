#ifndef EXERCISE24_H
#define EXERCISE24_H

#include <iostream>

class Stack
{
    struct node_t
    {
        int data;
        node_t *next;
        node_t(int _data, node_t *ptr) : data{_data}, next{ptr}{}
    };

    node_t *top{nullptr};
    size_t elem_num{0};
    
public:
    Stack() = default;
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;
    
    bool push(int value);

    bool pop(int &elem);

    size_t available(void);

    void clear(void);


    friend std::ostream &operator << (std::ostream &out, const Stack &stack)
    {
        node_t *cursor{stack.top};

        while (cursor != nullptr)
        {
            out << cursor->data << "\t";
            cursor = cursor->next;
        }
        
        return out;
    }

    ~Stack() {clear(); std::cout << "....." << std::endl; }
};



#endif