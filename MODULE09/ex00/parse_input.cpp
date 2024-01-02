#include "BitcoinExchange.hpp"

int check_val(float value)
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number.\n";
        return 0;
    }
    else if (value > 1000)
    {
        std::cerr << "Error: too large a number.\n";
        return 0;
    }
    return 1;
}

int days_monthCheck(int year, int month, int day)
{
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        return 0;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 0;
    else if (month == 2 && !(year % 4) && day > 29)
        return 0;
    else if (month == 2 && (year % 4) && day > 28)
        return 0;
    return 1;
}

int check_date(std::string &iDate)
{
    int year = stoi(iDate.substr(0, 4));
    if (year < 2009 || year > 2022)
    {   
        std::cerr << "Error: bad input => " << iDate << std::endl;
        return 0;
    }
    int month = stoi(iDate.substr(5, 2));
    if (month > 12 || month < 1)
    {
        std::cerr << "Error: bad input => " << iDate << std::endl;
        return 0;
    }
    int day = stoi(iDate.substr(8, 2));
    if ((year == 2009 && day == 1) || day < 1 || !days_monthCheck(year, month, day))
    {
        std::cerr << "Error: bad input => " << iDate << std::endl;
        return 0;
    }
    return 1;
}

int no_value(std::string &iline)
{
    int i = 0;
    while(iline[i] && iline[i] != '|')
        i++;
    if(iline[i] && iline[i] == '|')
        i++;
    while(iline[i] == ' ')
        i++;
    if (!iline[i])
    {
        std::cerr << "Error: there is no value.\n";
        return 1;
    }
    else if (iline[i] == '|')
    {
        std::cerr << "Error: bad format => " << iline << std::endl;
        return 1;
    }
    return 0;
}

int check_value(std::string &iline)
{
    int i = 0;
    int dots = 0;
    while(iline[i] && iline[i] != '|')
        i++;
    if(iline[i])
        i++;
    while(iline[i] && iline[i] == ' ')
        i++;
    if (iline[i] && (iline[i] == '-' || iline[i] == '+'))
        i++;
    while (iline[i] && (isdigit(iline[i]) || iline[i] == '.'))
    {
        if (iline[i] == '.')
            dots++;
        i++;
    }
    if (!iline[i] && dots < 2)
        return 1;
    std::cerr << "Error: not valid value.\n";
    return 0;
}

float get_value(std::string &iline)
{
    int i = 0;
    while(iline[i] && iline[i] != '|')
        i++;
    if(iline[i])
        i++;
    while(iline[i] && iline[i] == ' ')
        i++;
    float value = 0;
    if(iline[i])
        value = atof(&iline[i]);
    while (iline[i] && isdigit(iline[i]))
        i++;
    return value;
}

int check_line_format(std::string &iline)
{
    int i = 0;
    while(iline[i] && iline[i] != '|')
        i++;
    if(iline[i])
        i++;
    while(iline[i] && iline[i] != '|')
        i++;
    if (!iline[i])
        return 1;
    std::cerr << "Error: bad format => \"date | value\"\n";
    return 0;
}

int check_line(std::string &iline)
{
    if (!check_date_format(iline))
        return 0;
    else if (!check_line_format(iline))
        return 0;
    else if (!check_value(iline))
        return 0;
    return 1;
}

int check_date_format(std::string &iline)
{
    int i = 0;
    while(iline[i] && iline[i] != ' ')
        i++;
    if (i != 10 || iline[4] != '-' || iline[7] != '-')
    {
        std::cerr << "Error: bad format => Year-Month-Day (xxxx-xx-xx)\n";
        return 0;
    }
    return 1;
}

float get_data_value(std::string &dline)
{
    int i = 0;
    while(dline[i] && dline[i] != ',')
        i++;
    if(dline[i])
        i++;
    while(dline[i] == ' ')
        i++;
    float value = atof(&dline[i]);
    return value;
}