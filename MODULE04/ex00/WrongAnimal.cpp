#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal\n";
    std::cout << "WrongAnimal constructor called!\n";
}

WrongAnimal::WrongAnimal(std::string newType)
{
    type = newType;
    std::cout << "WrongAnimal constructor parametrized called!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "WrongAnimal copy constructor called!\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if(this != &other)
        this->type = other.type;
    std::cout << "WrongAnimal copy assignement operator called!\n";
    return *this;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound!\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called!\n";
}