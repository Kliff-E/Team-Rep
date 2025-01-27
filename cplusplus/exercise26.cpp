/**
 * @file exercise26.cpp
 * @author Kliff Elvin
 * @brief 1) Make a template print function to print an array.
 *        2) Make a template function pointer type to point to the print function
 *        3) Call the print function using an instance of the function pointer type
 *           to print an example array of type int.
 * @version 0.1
 * @date 2025-01-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

template <typename T, size_t SIZE> 
static void print(const T arr[SIZE])
{

    for (int i{0}; i < SIZE; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

template <typename T, size_t SIZE>
using func_t = void (*)(const T[SIZE]);

template <typename T>
struct array
{
};

template <typename T, size_t SIZE>
struct array<T[SIZE]>
{
    using elemt = T;
    static constexpr size_t size{SIZE};
};


int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    using type = array<decltype(arr)>::elemt;
    constexpr size_t size{array<decltype(arr)>::size};
    func_t <type, size> temp{print<type,size>};
    temp(arr);

    return 0;
}
