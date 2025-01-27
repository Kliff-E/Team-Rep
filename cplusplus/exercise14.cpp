#include <cstdlib>
#include <iostream>
#include <ctime>

constexpr int SIZE = 10;

using compare_t = bool (*)(int, int);

void fill_arr(int *ptr);

void print_arr(int *ptr);

void swap(int *a, int *b);

void sort_array(size_t length, int *arr, compare_t compare);

bool ascending(int a, int b);

bool descending(int a, int b);

    int main()
{
    int arr[SIZE];

    int X = 9;
    int Y = 10;

    int *x = &X;
    int *y = &Y;

    int *ptr = arr;

    fill_arr(ptr);

    print_arr(ptr);

    sort_array(SIZE, ptr, ascending);

    print_arr(ptr);

    sort_array(SIZE, ptr, descending);

    print_arr(ptr);

    //std::cout << "Before: " << x << " " << y << std::endl;
   // swap(x,y);
   // std::cout << "After: " << x << " " << y << std::endl;

    return 0;
}

void fill_arr(int *ptr)
{
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < SIZE; i++)
    {
        *(ptr + i) = rand() % 100;
    }
    

}

void print_arr(int *ptr)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}

void sort_array(size_t length, int *arr, compare_t compare)
{
    for (size_t i = 0; i < length - 1; ++i)
    {
        for (size_t j = 0; j < length - 1 - i; ++j)
        {
            if (compare(arr[j], arr[j + 1]))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool ascending(int a, int b)
{
    return a > b; // Swap if a is greater than b
}

// Descending order comparison
bool descending(int a, int b)
{
    return a < b; // Swap if a is smaller than b
}