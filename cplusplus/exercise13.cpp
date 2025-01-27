#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>



int main()
{
    std::string input;

    std::cout << "Enter a string: ";

    std::getline(std::cin, input);

    char *ptr = &input[0];

    while (*ptr != '\0')
    {
        if(std::isupper(*ptr))
        {
            *ptr= std::tolower(*ptr);
        }
        else if(std::islower(*ptr))
        {
            *ptr = std::toupper(*ptr);
        }
        ptr++;
    }
    

    std::cout << "Converted string: " << input << std::endl;



    return 0;
}