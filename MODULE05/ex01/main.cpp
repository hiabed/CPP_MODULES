#include "Form.hpp"

int main()
{
    Bureaucrat b("Abed", 25);
    try
    {
        Form f("Form1", 30, 1);
        b.signForm(f);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "continue\n";
    try
    {
        Form f("Form2", 20, 1);
        b.signForm(f);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "continue1\n";
    try
    {
        Form f("Form3", 20, 1);
        f.beSigned(b);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    Form print("printed form", 20, 2);
    std::cout << print << std::endl;
    std::cout << "end\n";
}