#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <iostream>

class PhoneBook
{
  private:
	Contact _contacts[8];

  public:
	void SetContact(Contact contact, int i);
	Contact GetContact(int i);
};

void	CheckIndex(std::string CheckIn, PhoneBook phonebook, int k);
int	CheckEmptyField(std::string &Field);
int	CheckPhoneNumber(std::string &PhoneNum);
void	print_infos(void);

#endif