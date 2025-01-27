#include <iostream>
#include <cstdlib>

bool is_prime(int num);

    int main()
{
    int num = {0};

    std::cout << "Enter a Number: ";

    std::cin >> num;

    if (num <= 0)
    {
        std::cerr << "Please provide a positive integer." << std::endl;
        exit(1);
    }

    if (is_prime(num))
    {
        std::cout << num << " is a prime number." << std::endl;
    }
    else
    {
        std::cout << num << " is not a prime number." << std::endl;
    }

    return 0;
}

bool is_prime(int num)
{
    int status = {1};
    if (num <= 1)
    {
        status = false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            status = false; // If divisible by i, it's not a prime number
        }
    }
    return status; // If no divisor found, it is a prime number
}