#include "AForm.hpp"

AForm::AForm():_name("Random"), _gradeToSign(5), _gradeToExecute(3)
{
    _isSigned = false;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
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

AForm::AForm(const AForm &other):_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    *this = other;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

const std::string AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &b)
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

const char *AForm::NotSignedException::what() const throw()
{
    return "Form not signed\n";
}

std::ostream &operator<<(std::ostream &output, AForm &obj)
{
    output << "***** AForm inAformations *****\n";

    output << "AForm name: " << obj.getName() << std::endl;
    output << "Grade required to sign: " << obj.getGradeToSign() << std::endl;
    output << "Grade required to execute: " << obj.getGradeToExecute() << std::endl;

    return output;
}

AForm::~AForm()
{
    
}