#include <iostream>
#include <iomanip>

void printBinary(int num);

int main()
{
    int num;

    do
    {

        std::cout << "Enter number between 0 and 255: ";
        std::cin >> num;

        if (num < 0 || num > 255)
        {
            std::cout << "invalid number. please try again: " << std::endl;
        }

    } while (num < 0 || num > 255);

    printBinary(num);

    
}

void printBinary(int num)
{
    for (int i = 7; i >= 0; i--)
    {
        // Use bitwise shift and AND to extract each bit
        int bit = (num >> i) & 1;
        std::cout << bit; // Print the bit (0 or 1)
    }
    std::cout << std::endl;
}