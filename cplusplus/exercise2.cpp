#include <iostream>
#include <iomanip>

int main()
{
    int num;

do{

    std::cout << "Enter number between 0 and 255: ";
    std::cin >> num;

    if (num < 0 || num > 255)
    {
        std::cout << "invalid number. please try again: " << std::endl;

    }
    

    
} while (num < 0 || num > 255);

std::cout << "The hexadecimal value is: "
<< std::hex << std::uppercase << num << std::endl;

}