#include "ClapTrap.hpp"

int main()
{
    ClapTrap Cl4pTp;
    Cl4pTp.attack("Hamza");
    Cl4pTp.takeDamage(100);
    Cl4pTp.beRepaired(1);
    Cl4pTp.attack("Hamza");
    return 0;
}