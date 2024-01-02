#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    _target = "AbedR";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executer) const
{
    if (!isSigned() || executer.getGrade() > getGradeToExecute())
    {
        GradeTooLowException low;
        throw (low);
    }
    else
    {
        std::cout << "WRRRRRR!! ";
        srand(time(0));
        if (rand() % 2 == 0)
        {
            std::cout << _target << " has been robotomized successfully\n";
        }
        else
        {
            std::cout << "the robotomy failed.\n";
        }
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // destructor;
}