#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    _target = "AbedS";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const
{
    if (!isSigned() || executer.getGrade() > getGradeToExecute())
    {
        GradeTooLowException low;
        throw (low);
    }
    else
    {
        std::ofstream file(_target + "_shrubbery");
        if (file.is_open()) 
        {
            file << "    **         **         **"     << std::endl;
            file << "   ****       ****       ****"    << std::endl;
            file << "  ******     ******     ******"   << std::endl;
            file << " ********   ********   ********"  << std::endl;
            file << "********** ********** **********" << std::endl;
            file << "    ||         ||         ||"     << std::endl;
            file.close();
            std::cout << "File created successfully: " << _target + "_shrubbery" << std::endl;
        } 
        else
            std::cerr << "Error creating file: " << _target + "_shrubbery" << std::endl;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // destructor;
}