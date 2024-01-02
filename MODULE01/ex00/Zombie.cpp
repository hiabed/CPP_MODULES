#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string new_name)
{
	_name = new_name;
}

Zombie::Zombie()
{
	
}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed!\n";
}
