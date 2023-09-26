#include "phonebook.hpp"

int main()
{
	Contact contact;
	std::string check_val;\
	int i = 0;
	while (i < 8)
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
			contact.index = i;
			check_val[0] = '\0';
		}
		else if (check_val == "SEARCH")
		{
			std::cout << "| " << contact.index << " | ";
			std::cout << contact.FirstName << " | ";
			std::cout << contact.LastName << " | ";
			std::cout << contact.NickName << " |\n";
		}
		else if (check_val == "EXIT")
			exit (EXIT_SUCCESS);
		if (i == 7)
			i = 0; 
		i++;
	}
}