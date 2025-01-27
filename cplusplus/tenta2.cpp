#include "tenta2.h"
#include <iostream>
#include <cassert>

int main(void)
{
    int value;
    Buffer<decltype(value),(4)> q;

    assert(0 == q.available());

    assert(q.write(10));
    assert(1 == q.available());

    assert(q.write(20));
    assert(2 == q.available());

    assert(q.write(30));
    assert(3 == q.available());

    assert(q.write(40));
    assert(4 == q.available());

    assert(q.write(50));
    assert(4 == q.available());

    q.read();

    q.clear();
    assert(0 == q.available());

    std::cout << "All tests passed!" << std::endl;

    return 0;
}