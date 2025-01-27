#include "exercise24.h"

bool Stack::push(int value) 
{
    bool status{false};

    node_t *node = new(std::nothrow) node_t{value, top};


    if (node != nullptr)
    {
        status = true;
        elem_num++;
        top = node;
    }

    return status;

}

bool Stack::pop(int &elem) 
{
    bool status{false};

    if(top != nullptr)
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

size_t Stack::available(void) {

    return elem_num;
}

void Stack::clear(void) 
{
    while(top != nullptr)
    {
        node_t *temp{top};
        top = top->next;
        delete temp;
    }

    elem_num = 0;

}


