#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main()
{
    const int SIZE = 10;
    int arr[SIZE];

    std::srand(static_cast<unsigned int>(std::time(0)));


    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = std::rand() % 100 +1;

        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::sort(arr, arr + SIZE);

    std::cout << "Sorted array: ";

        for (int i = 0; i < SIZE; i++)
    {

        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}