/**
 * @file exercise29.cpp
 * @author Kliff Elvin
 * @brief Make a template function named map to map a value in a range to a value in another range.
          Type of the ranges shall be arithmetic types.
          Example: 0.5f in the range of 0.0f and 3.3f is mapped to 155 in the range of 0 and 1023

 * @version 0.1
 * @date 2025-01-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>

template <typename T>
struct Range
{
    T min;
    T max;
};

template <typename F, typename T>
std::enable_if_t<std::is_arithmetic<T>::value, T> map(std::enable_if_t<std::is_arithmetic<F>::value, F> value, Range<F> from, Range<T> to)
{
    return (((to.max - to.min) / (from.max - from.min)) * (value - from.min) + to.min);
}



int main()
{
    Range<float> from{0.0f, 3.3f};
    Range<int> to{0, 1023};

    std::cout << map<float, int> (0.5f,from,to) << std::endl;


    return 0;
}