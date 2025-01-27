
#include "exercise22.h"
#include <assert.h>
#include <iostream>

Singleton *Singleton::instancePtr = nullptr;
std::mutex Singleton::mtx;

Singleton *Singleton::getInstance()
{
    if (instancePtr == nullptr)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (instancePtr == nullptr)
        {
            instancePtr = new Singleton();
        }
    }
    return instancePtr;
}

bool Singleton::push(int x)
{
    if (top >= (SIZE - 1))

        assert(!isFull() && "Singleton Overflow");

    arr[++top] = x;
    std::cout << x << " pushed into Singleton\n";
    return true;
    }

    int Singleton::pop()
    {
        assert(!isEmpty() && "Singleton Underflow");
        int x = arr[top--];
        return x;
    }
    int Singleton::get()
    {
        assert(!isEmpty() && "Singleton is Empty");
        int x = arr[top];
        return x;
    }
    int Singleton::getSingletonSize()
    {
        return top + 1;
    }
    bool Singleton::empty()
    {
        top = -1;
        std::cout << "Singleton has been cleared" << std::endl;

        return 0;
    }

    bool Singleton::isEmpty()
    {
        return (top < 0);
    }

    bool Singleton::isFull()
    {
        int status = false;
        if (getSingletonSize() == 10)
        {
            status = true;
        }
        return status;
    }