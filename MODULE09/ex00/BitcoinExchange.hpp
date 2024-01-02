#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

int check_val(float value);
float get_value(std::string &iline);
float get_data_value(std::string &dline);
int check_date(std::string &iDate);
int no_value(std::string &iline);
int check_date_format(std::string &iline);
int check_line_format(std::string &iline);
int check_value(std::string &iline);
int check_line(std::string &iline);

typedef std::map<std::string, float> map;

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
};

#endif