#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    const std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &b);
    class GradeTooHighException : public Bureaucrat::GradeTooHighException {};
    class GradeTooLowException : public Bureaucrat::GradeTooLowException {};
    ~Form();
};

std::ostream &operator<<(std::ostream &output, Form &obj);

#endif
