#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
#include <cstdlib>
#include <iomanip>

class Contact
{
	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;

  public:
	int index;
	void SetFirstName(std::string FirstName);
	void SetLastName(std::string LastName);
	void SetNickName(std::string NickName);
	void SetPhoneNumber(std::string PhoneNumber);
	void SetDarkestSecret(std::string DarkestSecret);
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();
};

class PhoneBook
{
  public:
	Contact contacts[8];
};

#endif