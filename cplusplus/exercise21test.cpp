#include <iostream>
#include <cassert>
#include "exercise21.h"

int main()
{
    stack s;

    // Test push functionality
    s.push(10);
    s.push(20);
    s.push(30);

    assert(s.getStackSize() == 3); // After pushing 3 elements, stack size should be 3
    std::cout << s.pop() << " Popped from stack\n";
    assert(s.getStackSize() == 2); // After popping, stack size should be 2

    // Print top element after popping
    std::cout << "Top element is : " << s.get() << std::endl;

    // Test stack size
    std::cout << "Number of elements: " << s.getStackSize() << std::endl;
    assert(s.getStackSize() == 2); // Stack size should be 2

    // Test clearing stack
    s.empty();
    assert(s.getStackSize() == 0); // After emptying the stack, stack size should be 0

    // Test isEmpty after clearing stack
    assert(s.isEmpty() == true); // Stack should be empty

    // Try pushing again after clearing the stack
    s.push(40);
    assert(s.getStackSize() == 1); // Stack size should be 1 after pushing again
    assert(s.get() == 40);         // The top element should be 40

    // Test stack overflow by pushing more elements than the stack can hold
    for (int i = 0; i < 9; ++i)
        s.push(i + 50); // Push more elements to fill the stack

    assert(s.isFull() == true); // Stack should be full now

    // Try to push to a full stack
    //s.push(100); // This should trigger an assertion failure because the stack is full

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
