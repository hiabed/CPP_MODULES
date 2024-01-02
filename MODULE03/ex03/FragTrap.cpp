#include "FragTrap.hpp"

void FragTrap::highFivesGuys()
{
    if (_ep <= 0 || _hp <= 0)
        return ;
    std::cout << "High Five!\n";
}

FragTrap::FragTrap(std::string Name):ClapTrap(Name)
{
    _Name = Name;
    _hp = 100;
    _ep = 100;
    _ad = 30;
    std::cout << "FragTrap Name is: " << _Name << std::endl;
    std::cout << "With HP of " << _hp << " And energy points of " << _ep << " and attak damage of " << _ad << "\n\n";
}

FragTrap::FragTrap()
{
    _Name = "Frag";
    _hp = 100;
    _ep = 100;
    _ad = 30;
    std::cout << "FragTrap Default constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called\n";
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Copy assignment operator called\n";
    if(this != &other)
    {
        _Name = other._Name;
        _hp = other._hp;
        _ep = other._ep;
        _ad = other._ad;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called\n";
}