#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename t1, typename t2>

void iter(t1 *arr, int length, void (*function)(t2 &))
{
    for (int i = 0; i < length; i++)
        function(arr[i]);
}

template <typename temp>

void print(temp &i)
{
    std::cout << i << std::endl;
}

#endif
