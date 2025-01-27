#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    int *ptr = arr;

    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int *ptr = arr; ptr < arr + SIZE; ++ptr)
    {
        *ptr = std::rand() % 100 + 1;

        std::cout << *ptr << " ";
    }
    std::cout << std::endl;

    std::sort(arr, arr + SIZE);

    std::cout << "Sorted array: ";

    for (int *ptr = arr; ptr < arr + SIZE; ++ptr)
    {

        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}