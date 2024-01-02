#include "Span.hpp"

// member functions (methods);

void Span::addNumber(int number)
{
    if(vArr.size() >= _N)
        throw std::runtime_error("the vector is full\n");
    vArr.push_back(number);
}

void Span::addRangeNumbers(std::vector<int>::iterator begin , std::vector<int>::iterator end)
{
    if(vArr.size() >= _N)
        throw std::runtime_error("the vector is full\n");
    vArr.insert(vArr.end(), begin, end);
}

void Span::print_container()
{
    for (unsigned int i = 0; i < 10; i++)
    {
        std::cout << vArr.at(i) << "\n";
    }
}

int Span::shortestSpan()
{
    if (vArr.size() < 2)
        throw (std::runtime_error("no span can be found\n"));
    int sSpan = INT_MAX;
    for (int i = 0; (size_t)i < vArr.size(); i++)
    {
        for (int j = 0; (size_t)j < vArr.size(); j++)
        {
            if (i != j && abs(vArr.at(i) - vArr.at(j)) < sSpan) //check self comparison;
                sSpan = abs(vArr.at(i) - vArr.at(j));
        }
    }
    return (sSpan);
}

int Span::longestSpan()
{
    if (vArr.size() < 2)
        throw (std::runtime_error("no span can be found\n"));
    return (*max_element(vArr.begin(), vArr.end()) - *min_element(vArr.begin(), vArr.end()));
}

//constructor parametrized;

Span::Span(unsigned int N)
{
    _N = N;
}

//orthodox canolical form;

Span::Span()
{
    _N = 0;
}
Span::Span(const Span &other)
{
    *this = other;
}
Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        vArr = other.vArr;
    }
    return *this;
}

Span::~Span()
{
}