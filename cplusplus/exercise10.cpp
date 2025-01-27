#include <iostream>
#include <ctime>

int main()
{
    const int rows(2);
    const int cols(3);
    int arr[rows][cols];

    srand(static_cast<unsigned int>(std::time(0)));

    int *ptr = (int *)arr;

    for (int i = 0; i < 6; i++)
    {
        
            *(ptr + i) = rand() % 100;
    }

    std::cout << "\n The 2x3 array is:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << *(ptr + i * 3 + j) << "\t";
        }

        std::cout << "\n";
    }

    return 0;
}