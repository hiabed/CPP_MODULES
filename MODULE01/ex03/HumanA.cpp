#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _Weapon(weapon), _name(name)
{
}

HumanA::~HumanA()
{
    std::cout << _name << " is destroyed\n";
}