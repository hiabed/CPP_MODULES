#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
    _Weapon = &weapon;
}

void HumanB::attack()
{
    if(_Weapon)
        std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
    _name = name;
    _Weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout << _name << " is destroyed\n";
}