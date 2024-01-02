#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog\n";
    std::cout << "Dog constructor called!\n";
}

Dog::Dog(const Dog &other)
{
    *this = other;
    std::cout << "Dog copy constructor called!\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if(this != &other)
        this->type = other.type;
    std::cout << "Dog copy assignement operator called!\n";
    return *this;
}

std::string Dog::getType() const
{
    return type;
}

void Dog::makeSound() const
{
    std::cout << "Woof!!\n";
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called!\n";
}