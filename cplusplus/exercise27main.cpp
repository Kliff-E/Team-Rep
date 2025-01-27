#include "exercise27.h"
#include <iostream>
#include <cassert>

int main(void)
{
    int value;
    Queue<decltype(value)> q;

    assert(0 == q.available());

    assert(q.enqueue(10));
    assert(1 == q.available());

    assert(q.enqueue(20));
    assert(2 == q.available());

    assert(q.dequeue(value));
    assert(value == 10);
    assert(1 == q.available());

    assert(q.dequeue(value));
    assert(value == 20);
    assert(0 == q.available());

    assert(q.enqueue(30));
    assert(1 == q.available());

    q.clear();
    assert(0 == q.available());

    assert(!q.dequeue(value));

    std::cout << "All tests passed!" << std::endl;

    return 0;
}