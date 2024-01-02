#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("Thomas", 150);
    try
    {
        a.decrementGrade();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        a.incrementGrade();
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    Bureaucrat c("john", 1);
    try
    {
        c.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        c.decrementGrade();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << a;
    //////////////
    Bureaucrat k = c;
    std::cout << k;
    //////////////
    std::cout << "end\n";
}