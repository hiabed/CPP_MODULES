#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert + <value to cast>\n";
        return 0;
    }
    std::string literal = av[1];
    ScalarConverter::convert(literal);
}
