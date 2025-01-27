#include <iostream>


int main()
{
    const int rows(3);
    const int cols(3);
    int arr[rows][cols];


    std::cout << "Enter the numbers for a 3x3 array (9 numbers):\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Number [" << i + 1 << "][" << j + 1 << "]:";
            std::cin >> arr[i][j];
        }
        
    }

    std::cout << "\n The 3x3 array is:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << arr[i][j] << "\t";
        }

        std::cout << "\n";
    }

    return 0;
}