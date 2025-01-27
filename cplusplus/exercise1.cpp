#include <iostream>

#define NUMBER 8

#ifndef NUMBER 

#error "Macro NUMBER not defined."

#endif

#if (NUMBER != 8) && (NUMBER != 16)

#error "Macro number must be 8 or 16."

#endif

int main()
{
    std::cout << "The value of NUMBER is: " << NUMBER << std::endl;
    return 0;
}
