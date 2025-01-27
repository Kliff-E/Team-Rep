#include <iostream>
#include <stdexcept>
#include <cassert>

template<typename T>
class Stack
{
    private:
    T* arr;
    size_t capacity;
    size_t topIndex;

    public:

    explicit Stack(size_t size) : capacity(size), topIndex(0)
    {
        if(size <= 3)
        {
            throw std::invalid_argument("Stack size must be greater than 3.");
        }
        arr = new T[capacity];
    }

    Stack()
    {
        delete[] arr;
    } 

    Stack(const Stack&) = delete;

    Stack& operator = (const Stack&) = delete;

    Stack(Stack&& other) noexcept
    : arr(other.arr), capacity(other.capacity), topIndex(other.topIndex)
    {
        other.arr = nullptr;
        other.topIndex = 0;
        other.capacity = 0;
    }

    Stack& operator = (Stack&& other) noexcept
    {
        if(this != &other)
        {
            delete[] arr;

            arr = other.arr;
            capacity = other.capacity;
            topIndex = other.topIndex;

            other.arr = nullptr;
            other.topIndex = {0};
            other.capacity = {0};
        }

        return *this;
    }

    void push(const T& data)
    {
        if(topIndex >= capacity)
        {
            throw std::overflow_error("Stack overflow: uanble to push.");
        }
        arr[topIndex++] = data;
    }

    T pop()
    {
        if (topIndex == 0)
        {
            throw std::underflow_error("Stack underflow: no elements to pop");
        }
        return arr[--topIndex];
    }

    size_t size() const
    {
        return topIndex;
    }

    void clear()
    {
        topIndex = 0;
    }
};



int main(void)
{
    try
    {

        Stack<int> stack(5);

        stack.push(10);
        stack.push(20);
        stack.push(30);

        assert(stack.pop() == 30);
        assert(stack.pop() == 20);
        assert(stack.pop() == 10);

        assert(stack.size() == 0);

        stack.push(100);
        stack.push(200);

        stack.clear();
        assert(stack.size() == 0);

        std::cout << "All tests passed!" << std::endl;

    }

    catch(const std::exception& e)
    {
        std::cerr << "Exception ocurred: " << e.what() << std::endl;
    }



    return 0;
}