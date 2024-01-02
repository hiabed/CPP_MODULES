#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat\n";
    std::cout << "WrongCat constructor called!\n";
}

WrongCat::WrongCat(const WrongCat &other)
{
    *this = other;
    std::cout << "WrongCat copy constructor called!\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if(this != &other)
        this->type = other.type;
    std::cout << "WrongCat copy assignement operator called!\n";
    return *this;
}

std::string WrongCat::getType() const
{
    return type;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow :3\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called!\n";
}