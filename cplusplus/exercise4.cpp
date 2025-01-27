#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{   
    start:
    char letter;
    
    std::cout << "Enter lowercase letter: ";
    std::cin >> letter;

    if (std::islower(letter))
    {
        char upperletter = std::toupper(letter);
        std::cout << "The uppercase letter is: " << upperletter << std::endl;
    }
    else{
        std::cout << "You did not enter a lowercase letter!" << std::endl;
        goto start;
    }
    


    std::srand(static_cast<unsigned int>(std::time(0)));

    int num1 = std::rand() % 10;
    int num2 = std::rand() % 10;

    std::cout << "First random number: " << num1 << std::endl;
    std::cout << "second random number: " << num2 << std::endl;

    return 0;
}