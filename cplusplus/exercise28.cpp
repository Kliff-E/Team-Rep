/**
 * @file exercise28.cpp
 * @author Kliff Elvin
 * @brief 1. Generate and store 1000 random numbers in the range of 100 and 100000 in a vector.
          2. Remove the non-prime numbers from the vector.
          3. Sort the vector using std::sort in ascending order (from smallest to largest)
          4. Usinng an iterator print the elements in the vector to the terminal.
 * @version 0.1
 * @date 2025-01-19
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>

constexpr int NUMBERS {1000};
constexpr int FIRST_PRIME {2};
constexpr int RANGE_MIN {100};
constexpr int RANGE__MAX {100000}; 

static bool non_prime(int nr);

int main()
{

    std::srand(time(nullptr));

    std::vector<int> vec;

    for (int i = 0; i < NUMBERS; i++)
    {
        vec.push_back(std::rand() % (RANGE__MAX - RANGE_MIN) + RANGE_MIN);
    }
    
    vec.erase(std::remove_if(vec.begin(), vec.end(), non_prime), vec.end());

    std::sort(vec.begin(), vec.end());

    std::for_each(vec.begin(), vec.end(), [](const auto &elem) {std::cout << elem << std::endl;});



    return 0;
}

static bool non_prime(int nr)
{
    bool status {true};

    if (nr >= FIRST_PRIME)
    {
        status = false;

        if ( nr > FIRST_PRIME)
        {
            status = true;

            const int max {static_cast<int>(std::sqrt(nr)) +1};

            for (int i = FIRST_PRIME; i <= max; i++)
            {
                if (nr % i == 0)
                {
                    status = false;
                    break;
                }
            }
            status = !status;
        }
    }
    return status;
}
