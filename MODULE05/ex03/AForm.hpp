#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual const std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &b);
    class GradeTooHighException : public Bureaucrat::GradeTooHighException {};
    class GradeTooLowException: public Bureaucrat::GradeTooLowException {};
    class NotSignedException : public std::exception {
        const char *what() const throw();
    };
    virtual void execute(Bureaucrat const & executor) const = 0;
    virtual ~AForm();
};

std::ostream &operator<<(std::ostream &output, AForm &obj);

#endif
