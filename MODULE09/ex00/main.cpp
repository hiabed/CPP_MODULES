#include "BitcoinExchange.hpp"

map fill_map()
{
    std::ifstream DataFile("data.csv");
    if (!DataFile.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        exit(EXIT_FAILURE);
    }
    std::string dline;
    map m;
    getline(DataFile, dline);
    while(getline(DataFile, dline))
    {
        std::string dDate = dline.substr(0, 10);
        float dValue = get_data_value(dline);
        m.insert(std::pair<std::string, float>(dDate, dValue));
    }
    DataFile.close();
    return m;
}

void print_keyVal(map m)
{
    map::iterator it = m.begin();
    while (it != m.end())
    {
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }
}

void find_date(map m, std::string iLine)
{
    if (!check_line(iLine))
        return ;
    std::string iDate = iLine.substr(0, 10);
    if (!check_date(iDate) || no_value(iLine))
        return ;
    float iValue = get_value(iLine);
    if (!check_val(iValue))
        return ;
    map::iterator it = m.find(iDate);
    if (it == m.end())
        it = --m.lower_bound(iDate);
    std::cout << iDate << " => " << iValue << " = " << (it->second * iValue) << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file.\n";
        exit(EXIT_FAILURE);
    }
    map m = fill_map();
    std::fstream InputFile(av[1]);
    if(!InputFile.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        exit(EXIT_FAILURE);
    }
    std::string iLine;
    getline(InputFile, iLine);
    while (getline(InputFile, iLine))
    {
        find_date(m, iLine);
    }
    return 0;
}