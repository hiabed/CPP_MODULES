#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal\n";
    std::cout << "Animal constructor called!\n";
}

Animal::Animal(std::string newType)
{
    type = newType;
    std::cout << "Animal constructor parametrized called!\n";
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Animal copy constructor called!\n";
}

Animal &Animal::operator=(const Animal &other)
{
    if(this != &other)
        this->type = other.type;
    std::cout << "Animal copy assignement operator called!\n";
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound!\n";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called!\n";
}