#include "phonebook.hpp"

int main()
{
	Contact contact;
	std::string check_val;
	while (1)
	{
		std::cin >> check_val;
		if (check_val == "ADD")
		{
			std::cout << "First Name: \n";
			std::cin >> contact.FirstName;
			std::cout << "Last Name: \n";
			std::cin >> contact.LastName;
			std::cout << "Nick Name: \n";
			std::cin >> contact.NickName;
			std::cout << "Phone Number: \n";
			std::cin >> contact.PhoneNumber;
			std::cout << "Darkest Secrect: \n";
			std::cin >> contact.DarkestSecret;
			check_val[0] = '\0';
		}
		else if (check_val == "SEARCH")
		{
			
		}
		else if (check_val == "EXIT")
			exit (EXIT_SUCCESS);
	}
}