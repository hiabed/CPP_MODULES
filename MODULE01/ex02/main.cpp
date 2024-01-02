#include <iostream>

int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string *stringPTR = &name;
    std::string &stringREF = name;

    std::cout << "addresses:\n";
    std::cout << &name << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << "values:\n";
    std::cout << name << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}