#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
{
    _Name = Name;
    _hp = 10;
    _ep = 10;
    _ad = 0;
    std::cout << "ClapTrap Name is: " << _Name << std::endl;
    std::cout << "With HP of " << _hp << " And energy points of " << _ep << " and attak damage of " << _ad << "\n\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (_ep <= 0 || _hp <= 0)
        return ;
    _ep--;
    std::cout << "ClapTrap " << _Name << " attacks " << target << " , causing " << _ad << " points of damage!\n";
    std::cout << "***** actual energy points is: " << _ep << " *****\n\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_ep <= 0 || _hp <= 0)
        return ;
    _ep--;
    _hp += amount;
    std::cout << _Name << " gains " << amount << " amounts of HP!\n";
    std::cout << "***** actual HP is: " << _hp << " and _ep is: " << _ep << " *****\n\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hp -= amount;
    if (_hp <= 0 || _ep <= 0)
    {
        _hp = 0;
        std::cout << _Name << " takes " << amount << " amounts of damage!\n";
        std::cout << "***** actual HP is: " << _hp << " *****\n\n";
        return ;
    }
    std::cout << _Name << " takes " << amount << " amounts of damage!\n";
    std::cout << "***** actual HP is: " << _hp << " *****\n\n";
}

ClapTrap::ClapTrap()
{
    _Name = "Clap";
    _hp = 10;
    _ep = 10;
    _ad = 0;
    std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called\n";
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assignment operator called\n";
    if(this != &other)
    {
        _Name = other._Name;
        _hp = other._hp;
        _ep = other._ep;
        _ad = other._ad;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called\n";
}