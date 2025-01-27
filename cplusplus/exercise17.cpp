#include <iostream>

int countDigit(int number);

int power_of(int x, int y);

int num {0};
int x {0};
int y {0};

int main()
{

    std::cout << "Write a number: ";
    std::cin >> num; 

    std::cout << num << " has this many digits: " << countDigit(num) << std::endl;

    std::cout << "Write a base and a exponent" << std::endl;
    std::cin >> x >> y;

    std::cout << power_of(x,y) << std::endl;

    return 0;
    
}


int countDigit(int number)
{
    int value {0};

    if (number == 0)
    {
        return 0;
    }
    else{
        return 1+ countDigit(number/10);
    }
    

}

int power_of(int x, int y)
{
    if ( y == 0)
    {
        return 1;
    }
    else{

        return x * power_of(x,y -1 );
    }
    

}