#include "Span.hpp"

int main()
{
    std::cout << "-----TEST #1------\n";

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try
    {
        sp.addNumber(11);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    try
    {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }

    std::cout << "-----TEST #2------\n";

    std::vector<int>    v(10000);
    srand(time(0));
    generate(v.begin(), v.end(), &rand);
    
    Span s2(v.size());
    s2.addRangeNumbers(v.begin(), v.end());
    s2.print_container();
    try
    {
        s2.addNumber(12);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    return 0;
}
