/**
 * @file exercise22.h
 * @author Kliff Elvin
 * @brief Implement and test an uncopyable Singleton Singleton class using an array of type int whose size is a compile-time constant.
        The Singleton class shall provide the following function:
        A function to push a data element to the Singleton.
        A function to get number of the data elements stored in the Singleton.
        A function to pop an element from the Singleton.
        A function to clear the Singleton




 * @version 0.1
 * @date 2025-01-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef EXERCISE22_H
#define EXERCISE22_H

#include <mutex>

class Singleton
{

public:
    Singleton(const Singleton &obj) = delete;

    // Static method to get the Singleton instance
    static Singleton *getInstance();
    bool push(int x);
    int pop();
    int get();
    int getSingletonSize();
    bool empty();
    bool isFull();
    bool isEmpty();

private:
    static constexpr int SIZE{10};
    int arr[SIZE];
    int top{-1};

    static Singleton *instancePtr;

    // Mutex to ensure thread safety
    static std::mutex mtx;

    // Private Constructor
    Singleton() {}
    };

#endif