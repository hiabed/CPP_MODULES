#include "ScavTrap.hpp"

int main()
{
    ScavTrap s("Abed");
    s.attack("Hamza");
    s.takeDamage(100);
    s.beRepaired(1);
    return 0;
}