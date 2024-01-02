#include "ScalarConverter.hpp"

int is_character(std::string& literal)
{
    int alpha = 0;
    for (int i = 0; literal[i]; i++)
    {
        if (alpha > 1)
            return 0;
        if (isdigit(literal[i]))
            return 0;
        if (isascii(literal[i]))
            alpha++;
    }
    if (alpha == 1)
        return 1;
    return 0;
}

int is_valid(std::string &literal)
{
    int dots = 0;
    int sign = 0;
    int f = 0;
    for(int i = 0; literal[i]; i++)
    {
        if (isalpha(literal[i]) && !is_character(literal) && literal[i] != 'f')
            return 0;
        if (literal[i] == 'f')
            f++;
        if (f > 1)
            return 0;
        if (literal[i] == '.')
        {
            dots++;
            if (dots > 1 || (i == 0 && literal[i + 1]) || (static_cast<size_t>(i) == literal.length() - 1) || (isascii(literal[i + 1]) && literal[i + 1] && !isdigit(literal[i + 1])))
                return 0;
        }
        if (literal[i] == '+' || literal[i] == '-')
        {
            sign++;
            if (sign > 1 || i > 0)
                return 0;
        }
        if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f' && i > 0)
            return 0;
    }
    if (literal[0] == ' ')
        return 0;
    return 1;
}
