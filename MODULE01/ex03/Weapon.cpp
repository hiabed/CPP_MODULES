#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
    _type = type;
}

void Weapon::setType(std::string type)
{
    _type = type;
}

const std::string &Weapon::getType()
{
    return _type;
}

Weapon::~Weapon()
{
    std::cout << _type << " is destroyed\n";
}