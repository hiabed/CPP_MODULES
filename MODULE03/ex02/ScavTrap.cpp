#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    if (_ep <= 0 || _hp <= 0)
        return ;
    std::cout << "ScavTrap is now in Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (_ep <= 0 || _hp <= 0)
        return ;
    _ep--;
    std::cout << "ScavTrap " << _Name << " attacks " << target << " , causing " << _ad << " points of damage!\n";
    std::cout << "***** actual energy points is: " << _ep << " *****\n\n";
}

ScavTrap::ScavTrap(std::string Name):ClapTrap(Name)
{
    _Name = Name;
    _hp = 100;
    _ep = 50;
    _ad = 20;
    std::cout << "ScavTrap Name is: " << _Name << std::endl;
    std::cout << "With HP of " << _hp << " And energy points of " << _ep << " and attak damage of " << _ad << "\n\n";
}

ScavTrap::ScavTrap()
{
    _Name = "Scav";
    _hp = 100;
    _ep = 50;
    _ad = 20;
    std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called\n";
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy assignment operator called\n";
    if(this != &other)
    {
        _Name = other._Name;
        _hp = other._hp;
        _ep = other._ep;
        _ad = other._ad;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called\n";
}