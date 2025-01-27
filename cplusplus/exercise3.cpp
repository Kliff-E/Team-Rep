#include <iostream>

int main()
{
    start:
    int num = 0;

    std::cout << "Enter a positive integer: ";
    std:: cin >> num;

    if(num <= 0)
    {
        std::cout << "Please enter a positive integer." << std::endl;
        goto start;
    }

    int sum = 0;

    for (int i = 0; i <= num; i+= 2)
    {
        sum += i;
    }
    
    std::cout << "The sum of all even numbers from 0 to " << num << " is: " << sum << std::endl;

    return 0;
}