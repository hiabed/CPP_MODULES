#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d("Abed");

    d.whoAmI();
    d.attack("Hamza");
    d.takeDamage(20);
    d.beRepaired(10);
    d.takeDamage(100);
    d.beRepaired(50);
    return 0;
}