#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat b("Abed", 1);
    RobotomyRequestForm r("Hamza");
    ShrubberyCreationForm s("Hamza");
    PresidentialPardonForm p("Hamza");
    try
    {
        r.beSigned(b);
        r.execute(b);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        s.beSigned(b);
        s.execute(b);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        p.beSigned(b);
        p.execute(b);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Bureaucrat b1("Brahim", 1);
    try
    {
        p.beSigned(b1);
        b1.executeForm(p);
        p.execute(b1);
        b1.executeForm(r);
        r.execute(b1);
        b1.executeForm(s);
        s.execute(b1);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}