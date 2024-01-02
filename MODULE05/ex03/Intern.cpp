#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string form_names[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    AForm *forms[3] = {
        new RobotomyRequestForm (target),
        new PresidentialPardonForm (target),
        new ShrubberyCreationForm (target)
    };
    for (int i = 0; i < 3; i++)
    {
        if (name == form_names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    delete forms[j];
                    forms[j] = NULL;
                }
            }
            return forms[i];
        }
    }
    std::cout << "Intern can't create the " << name << std::endl;
    for (int i = 0; i < 3; i++)
    {
        delete forms[i];
        forms[i] = NULL;
    }
    return NULL;
}

Intern::~Intern()
{
}