#include "PhoneBook.hpp"

void	print_infos()
{
	std::cout << "****  use 'ADD' command to add a contact to the phonebook  *****\n";
	std::cout << "****  use 'SEARCH' command to search for a specific contact  ***\n";
	std::cout << "****  use 'EXIT' command to EXIT from the phonebook program  ***\n\n";
}

void CheckIndex(std::string CheckIn, PhoneBook phonebook, int k)
{
	std::cout << "Please type an index of a contact: \n";
	getline(std::cin, CheckIn);
	if (std::cin.eof())
		exit(1);
	std::cout << "\n";
	if (CheckIn.length() == 1 && CheckIn[0] - 48 > 0 && CheckIn[0] - 48 <= k)
	{
		std::cout << "Contact Informations:\n";
		std::cout << "First Name: " << phonebook.GetContact(CheckIn[0] - 49).GetFirstName() << "\n";
		std::cout << "Last Name: " << phonebook.GetContact(CheckIn[0] - 49).GetLastName() << "\n";
		std::cout << "Nick Name: " << phonebook.GetContact(CheckIn[0] - 49).GetNickName() << "\n";
		std::cout << "Phone number: " << phonebook.GetContact(CheckIn[0] - 49).GetPhoneNumber() << "\n";
		std::cout << "Darkest Secret: " << phonebook.GetContact(CheckIn[0] - 49).GetDarkestSecret() << "\n";
		std::cout << "Index: " << phonebook.GetContact(CheckIn[0] - 49).GetIndex() << "\n\n";
	}
	else
	{
		std::cout << "Invalid Index.\n";
	}
}

int	CheckEmptyField(std::string &Field)
{
	while (1)
	{
		std::getline (std::cin, Field);
		if (std::cin.eof())
			exit(1);
		if (Field.empty())
		{
			std::cout << "Field's empty, try again:\n";
			continue;
		}
		else
		{
			int i = 0;
			while (Field[i] && (Field[i] == ' ' || Field[i] == '\t' || Field[i] == '\n'))
				i++;
			if(Field[i] == '\0')
				std::cout << "Field's empty, try again:\n";
			else
				return 1;
		}
	}
}

int	CheckPhoneNumber(std::string &PhoneNum)
{
	std::cout << "Phone Number: \n";
	while (1)
	{
		std::getline (std::cin, PhoneNum);
		int j = 0;
		while (isdigit(PhoneNum[j]))
			j++;
		if (PhoneNum[j] != '\0')
		{
			std::cout << "invalid, try again:\n";
			continue;
		}
		return 1;
	}
}