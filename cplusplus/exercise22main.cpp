#include <iostream>
#include <cassert>
#include "exercise22.h"

int main()
{
    Singleton* sngl = Singleton::getInstance();

    // Test push functionality
    sngl->push(10);
    sngl->push(20);
    sngl->push(30);

    assert(sngl->getSingletonSize() == 3); // After pushing 3 elements, Singleton size should be 3
    std::cout << sngl->pop() << " Popped from Singleton\n";
    assert(sngl->getSingletonSize() == 2); // After popping, Singleton size should be 2

    // Print top element after popping
    std::cout << "Top element is : " << sngl->get() << std::endl;

    // Test Singleton size
    std::cout << "Number of elements: " << sngl->getSingletonSize() << std::endl;
    assert(sngl->getSingletonSize() == 2); // Singleton size should be 2

    // Test clearing Singleton
    sngl->empty();
    assert(sngl->getSingletonSize() == 0); // After emptying the Singleton, Singleton size should be 0

    // Test isEmpty after clearing Singleton
    assert(sngl->isEmpty() == true); // Singleton should be empty

    // Try pushing again after clearing the Singleton
    sngl->push(40);
    assert(sngl->getSingletonSize() == 1); // Singleton size should be 1 after pushing again
    assert(sngl->get() == 40);             // The top element should be 40

    // Test Singleton overflow by pushing more elements than the Singleton can hold
    for (int i = 0; i < 9; ++i)
        sngl->push(i + 50); // Push more elements to fill the Singleton

    assert(sngl->isFull() == true); // Singleton should be full now

    // Try to push to a full Singleton
     //sngl->push(100); // This should trigger an assertion failure because the Singleton is full

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
