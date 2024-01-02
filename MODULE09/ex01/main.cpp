#include "RPN.hpp"

int is_operator(char av1)
{
    if (av1 == '+' || av1 == '-' || av1 == '*' || av1 == '/')
        return 1;
    return 0;
}

int parse_input(char *av1)
{
    for (int i = 0; av1[i]; i++)
    {
        if (av1[i] != '+' && av1[i] != '-' && av1[i] != '*' && av1[i] != '/' && av1[i] != ' ' && av1[i] != '\t' && !isdigit(av1[i]))
            return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: bad number of arguments.\n";
        return 0;
    }
    if (!parse_input(av[1]))
    {
        std::cerr << "Error\n";
        return 0;
    }
    std::stack<int> st;
    int result = 0;
    int array[2];
    int op = 0;
    for (int i = 0; av[1][i]; i++)
    {
        if(isdigit(av[1][i]))
            st.push(atoi(&av[1][i]));
        else if (is_operator(av[1][i]))
        {
            op = 1;
            if(st.size() < 2)
            {
                std::cerr << "Error\n";
                return 0;
            }
            array[0] = st.top();
            st.pop();
            array[1] = st.top();
            st.pop();
            if (av[1][i] == '+')
                result = array[1] + array[0];
            else if (av[1][i] == '-')
                result = array[1] - array[0];
            else if (av[1][i] == '*')
                result = array[1] * array[0];
            else if (av[1][i] == '/')
                result = array[1] / array[0];
            st.push(result);
        }
    }
    if (st.size() == 1 && op)
        std::cout << result << std::endl;
    else
        std::cerr << "Error\n";
    return 0;
}