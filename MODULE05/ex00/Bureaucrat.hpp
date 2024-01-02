#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    void incrementGrade();
    void decrementGrade();
    std::string getName() const;
    int getGrade() const;
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
    public:
        const char *what() const throw();
    };
    ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &output, Bureaucrat &obj);

#endif