#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename temp>

void swap(temp &a, temp &b)
{
    temp c = b;
    b = a;
    a = c;
}

template<typename temp>

temp &min(temp &a, temp &b)
{
    if (a < b)
        return a;
    return b;
}

template<typename temp>

temp &max(temp &a, temp &b)
{
    if (a > b)
        return a;
    return b;
}

#endif