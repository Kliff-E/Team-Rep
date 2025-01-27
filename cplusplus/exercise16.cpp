#include <cstdlib>
#include <iostream>
#include <ctime>

constexpr int SIZE = {10};

void fill_arr(int *arr);

void print_arr(int *arr);

    int main()
{

    int arr[SIZE];

    fill_arr(arr);

    print_arr(arr);

    return 0;
}

void fill_arr(int *arr)
{

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[i] = rand() % 100;
            }
        }
    }
}

void print_arr(int *arr)
{

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}