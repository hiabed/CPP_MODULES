#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called!\n";
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Brain copy constructor called!\n";
}

Brain &Brain::operator=(const Brain &other)
{
    if(this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy assignement operator called!\n";
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called!\n";
}