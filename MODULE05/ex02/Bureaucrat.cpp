#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Abed")
{
    _grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if(grade > 150)
    {
        GradeTooLowException low;
        throw(low);
    }
    if(grade < 1)
    {
        GradeTooHighException high;
        throw(high);
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low\n";
}

void Bureaucrat::incrementGrade()
{
    _grade--;
    if(_grade < 1)
    {
        GradeTooHighException high;
        throw(high);
    }
}

void Bureaucrat::decrementGrade()
{
    _grade++;
    if(_grade > 150)
    {
        GradeTooLowException low;
        throw(low);
    }
}

std::ostream &operator<<(std::ostream &output, Bureaucrat &obj)
{
    output << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "."<< std::endl;
    return output;
}

void Bureaucrat::signForm(AForm &Aform)
{
    try
    {
        Aform.beSigned(*this);
        if (Aform.isSigned())
            std::cout << getName() << " signed " << Aform.getName() << std::endl;
        else
        {
            AForm::GradeTooLowException low;
            throw (low);
        }
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << getName() << " couldn't sign " << Aform.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    if (form.isSigned() && getGrade() <= form.getGradeToExecute())
        std::cout << getName() << " executed " << form.getName() << std::endl;
    else
        std::cout << getName() << " can't execute the " << form.getName() << std::endl;
}

Bureaucrat::~Bureaucrat()
{
}