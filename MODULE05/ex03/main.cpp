#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



int main()
{
    Bureaucrat b("Abed", 1);
    RobotomyRequestForm r("Hamza");
    ShrubberyCreationForm s("Hamza");
    PresidentialPardonForm p("Hamza");

    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    try
    {
        if (!rrf)
            throw (0);
        rrf->beSigned(b);
        rrf->execute(b);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (int &i)
    {
        std::cerr << "form dosen't existe\n";
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
        r.beSigned(b1);
        b1.executeForm(r);
        r.execute(b1);
        s.beSigned(b1);
        b1.executeForm(s);
        s.execute(b1);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete rrf;
}