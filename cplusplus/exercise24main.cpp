#include "exercise24.h"
#include <iostream>
#include <cassert>

int main(void)
{
    int value;
    Stack stack;

    assert(0 == stack.available());

    assert(stack.push(10));
    assert(1 == stack.available());

    assert(stack.push(20));
    assert(2 == stack.available());

    assert(stack.pop(value));
    assert(value == 20);
    assert(1 == stack.available());

    assert(stack.pop(value));
    assert(value == 10);
    assert(0 == stack.available());

    assert(stack.push(30));
    assert(1 == stack.available());

    stack.clear();
    assert(0 == stack.available());

    assert(!stack.pop(value));

    std::cout << "All tests passed!" << std::endl;

    return 0;
}