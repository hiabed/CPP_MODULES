#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog\n";
    brainPtr = new Brain();
    std::cout << "Dog constructor called!\n";
}

Dog::Dog(const Dog &other)
{
    brainPtr = NULL;
    *this = other;
    std::cout << "Dog copy constructor called!\n";
}

Dog &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        delete brainPtr;
        brainPtr = new Brain();
        this->type = other.type;
        *this->brainPtr = *other.brainPtr;
    }
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
    delete brainPtr;
    std::cout << "Dog Destructor called!\n";
}