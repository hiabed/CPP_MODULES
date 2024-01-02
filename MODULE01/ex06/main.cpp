#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl harl;
		harl.complain(av[1]);
	}
	else
		std::cout << "you should enter 2 arguments: <executable> <message>\n";
}