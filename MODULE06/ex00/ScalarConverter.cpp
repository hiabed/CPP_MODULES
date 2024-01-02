#include "ScalarConverter.hpp"

int ScalarConverter::_i = 0;
char ScalarConverter::_c = 0;
float ScalarConverter::_f = 0;
double ScalarConverter::_d = 0;

ScalarConverter::ScalarConverter()
{
    _i = 0;
    _c = 0;
    _f = 0.0f;
    _d = 0.0;
}

void ScalarConverter::print_charType()
{
    std::cout << "char: " << _c << std::endl;
    std::cout << "int: " << _i << std::endl;
    std::cout << "float: " << _f << ".0f" << std::endl;
    std::cout << "double: " << _d << ".0" << std::endl;
}

void ScalarConverter::print_info(float av1)
{
    if(isprint(av1)) //char;
        std::cout << "char: " << _c << std::endl;
    else if (isnan(av1))
        std::cout << "char: impossible\n";
    else if(!isprint(av1))
        std::cout << "char: Non displayable" << std::endl;
    if (isnan(av1) || av1 == INFINITY || av1 == -INFINITY) //int;
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << _i << std::endl;
    if (av1 != static_cast<int>(av1)) //float
        std::cout << "float: " << _f << "f" << std::endl;
    else
        std::cout << "float: " << _f << ".0f" << std::endl;
    if (av1 != static_cast<int>(av1)) //double
        std::cout << "double: " << _d << std::endl;
    else
        std::cout << "double: " << _d << ".0" << std::endl;
}

int inf_nan(std::string &av1)
{
    if (av1 == "+inf" || av1 == "-inf" || av1 == "+inff" || av1 == "-inff" || av1 == "nan" || av1 == "nanf")
        return 1;
    return 0;
}

void ScalarConverter::convert(std::string &av1)
{
    if (!is_valid(av1) && !inf_nan(av1))
    {
        std::cout << av1 << " is not a valid input\n";
        return ;
    }
    if (is_character(av1) && !isdigit(av1[0]))
    {
        _i = static_cast<int>(av1[0]);
        _c = static_cast<char>(av1[0]);
        _f = static_cast<float>(av1[0]);
        _d = static_cast<double>(av1[0]);
        print_charType();
        return ;
    }
    const char *s = av1.c_str();
    _i = static_cast<int>(atoi(s));
    _c = static_cast<char>(atoi(s));
    _f = static_cast<float>(atof(s));
    _d = static_cast<double>(atof(s));
    print_info(atof(s));
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
        _i = other._i;
        _d = other._d;
        _f = other._f;
        _c = other._c;
    }
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}