#include "PmergeMe.hpp"
#include <list>

void sort_two(int &a, int &b)
{
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
}

int check_args(int ac, char **av)
{
    if (ac < 3)
    {
        std::cerr << "Error\n";
        return (0);
    }
    for (int i = 1; av[i]; i++)
    {
        for(int j = 0; av[i][j]; j++)
        {
            if (!isdigit(av[i][j]))
            {
                std::cerr << "Error\n";
                return (0);
            }
        }
    }
    return (1);
}

int main(int ac, char **av)
{
    if (!check_args(ac, av))
        return 0;
    sort_container<std::vector <int>, std::vector <std::pair<int, int> > >(ac, av, "std::vector");
    sort_container<std::deque <int>, std::deque <std::pair<int, int> > >(ac, av, "std::deque");
    return 0;
}
