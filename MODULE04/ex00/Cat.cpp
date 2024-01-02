#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat\n";
    std::cout << "Cat constructor called!\n";
}

Cat::Cat(const Cat &other)
{
    *this = other;
    std::cout << "Cat copy constructor called!\n";
}

Cat &Cat::operator=(const Cat &other)
{
    if(this != &other)
        this->type = other.type;
    std::cout << "Cat copy assignement operator called!\n";
    return *this;
}

std::string Cat::getType() const
{
    return type;
}

void Cat::makeSound() const
{
    std::cout << "Meow :3\n";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called!\n";
}