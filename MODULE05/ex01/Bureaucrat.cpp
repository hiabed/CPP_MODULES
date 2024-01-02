#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("Abed")
{
    _grade = 1; // highest grade;
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
    {
        this->_grade = other._grade;
    }
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

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        if (form.isSigned())
            std::cout << getName() << " signed " << form.getName() << std::endl;
        else
        {
            Form::GradeTooLowException low;
            throw (low);
        }
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
    
}