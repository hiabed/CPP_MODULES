#include "Form.hpp"

Form::Form():_name("Random"), _gradeToSign(5), _gradeToExecute(3)
{
    _isSigned = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    _isSigned = false;
    if (_gradeToSign > 150)
    {
        GradeTooLowException low;
        throw (low);
    }
    else if (_gradeToSign < 1)
    {
        GradeTooHighException high;
        throw (high);
    }
    if (_gradeToExecute > 150)
    {
        GradeTooLowException low;
        throw (low);
    }
    else if (_gradeToExecute < 1)
    {
        GradeTooHighException high;
        throw (high);
    }
}

Form::Form(const Form &other):_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

const std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
    {
        GradeTooLowException low;
        throw (low);
    }
    else if (b.getGrade() < 1)
    {
        GradeTooHighException high;
        throw (high);
    }
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &output, Form &obj)
{
    output << "***** Form informations *****\n";

    output << "Form name: " << obj.getName() << std::endl;
    output << "Grade required to sign: " << obj.getGradeToSign() << std::endl;
    output << "Grade required to execute: " << obj.getGradeToExecute() << std::endl;

    return output;
}

Form::~Form()
{
    
}