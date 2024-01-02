#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat\n";
    brainPtr = new Brain();
    std::cout << "Cat constructor called!\n";
}

Cat::Cat(const Cat &other)
{
    brainPtr = NULL;
    *this = other;
    std::cout << "Cat copy constructor called!\n";
}

Cat &Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        delete brainPtr;
        brainPtr = new Brain();
        this->type = other.type;
        *this->brainPtr = *other.brainPtr;
    }
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
    delete brainPtr;
    std::cout << "Cat Destructor called!\n";
}