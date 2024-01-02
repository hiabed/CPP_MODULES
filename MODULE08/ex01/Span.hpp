#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int _N;
    std::vector<int>vArr;
public:
    // member functions;
    void addNumber(int number);
    void addRangeNumbers(std::vector<int>::iterator begin , std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();
    void print_container();
    // orthodox canolical form;
    Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    // constructor parametrized;
    Span(unsigned int N);
};

#endif