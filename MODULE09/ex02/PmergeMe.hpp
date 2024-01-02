#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <sys/time.h>

void sort_two(int &a, int &b);

template <typename Container>

Container fill_container(char **av)
{
    Container C;
    // fill container;
    for (int i = 1; av[i]; i++)
        C.push_back(atoi(av[i]));
    return C;
}

template <typename Container>

void print_container(Container &C, bool beg)
{
    if (beg)
        std::cout << "Before: ";
    else
        std::cout << "After:  ";
    for (size_t i = 0; i < C.size() ; i++)
        std::cout << C.at(i) << " ";
    std::cout << std::endl;
}

template <typename Container>

Container fill_pairs_container(char **av)
{
    Container C;
    for (int i = 1; av[i] && av[i + 1]; i += 2)
        C.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
    return C;
}

template <typename Container>

void print_pairs_container(Container &C)
{
    std::cout << "container pairs: \n";
    for (size_t i = 0; i < C.size() ; i++)
        std::cout << "pair "<< i + 1 << ": " << C.at(i).first << " " << C.at(i).second << std::endl;
}

template<typename Container, typename Pair>

void sort_container(int ac, char **av, std::string container)
{
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);
    Container my_con = fill_container<Container >(av);
    if (container == "std::vector")
        print_container(my_con, true);
    Pair con = fill_pairs_container<Pair > (av);
    // sort two elements of each pair of a container;
    for (size_t i = 0; i < con.size(); i++)
        sort_two(con.at(i).first, con.at(i).second);

    Container largest;
    for (size_t i = 0; i < con.size(); i++)
        largest.push_back(con.at(i).second);

    Container smallest;
    for (size_t i = 0; i < con.size(); i++)
        smallest.push_back(con.at(i).first);

    sort(largest.begin(), largest.end());

    typename Container::iterator b = smallest.begin();
    typename Container::iterator it;
    while(b != smallest.end())
    {
        it = lower_bound(largest.begin(), largest.end(), *b);
        largest.insert(it, *b);
        b++;
    }
    if (my_con.size() % 2)
    {
        it = lower_bound(largest.begin(), largest.end(), *(my_con.end() - 1));
        largest.insert(it, *(my_con.end() - 1));
    }
    if (container == "std::vector")
        print_container(largest, false);
    gettimeofday(&end, NULL);
    if (container == "std::vector")
        std::cout << "Time to process a range of    " << ac - 1 << " elements with " << container << " : "<< (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << '\n';
    else
        std::cout << "Time to process a range of    " << ac - 1 << " elements with " << container << " : "<< (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << '\n';
}

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
};

#endif