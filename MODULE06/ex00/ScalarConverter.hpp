#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>

int is_valid(std::string &literal);
int is_character(std::string& literal);

class ScalarConverter
{
private:
    static int _i;
    static char _c;
    static double _d;
    static float _f;
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
public:
    static void convert(std::string &literal);
    static void print_info(float av1);
    static void print_charType();
};

#endif