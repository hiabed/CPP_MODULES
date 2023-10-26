#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	int _index;
	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;

  public:
    void SetIndex(int index);
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
    int GetIndex();
};

#endif