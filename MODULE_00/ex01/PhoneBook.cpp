#include "phonebook.hpp"

void Contact::SetFirstName(std::string FirstName)
{
    _FirstName = FirstName;
}

void Contact::SetLastName(std::string LastName)
{
    _LastName = LastName;
}

void Contact::SetNickName(std::string	NickName)
{
    _NickName = NickName;
}

void Contact::SetPhoneNumber(std::string PhoneNumber)
{
    _PhoneNumber = PhoneNumber;
}

void Contact::SetDarkestSecret(std::string	DarkestSecret)
{
    _DarkestSecret = DarkestSecret;
}

std::string Contact::GetFirstName()
{
    return _FirstName;
}

std::string Contact::GetLastName()
{
    return _LastName;
}

std::string Contact::GetNickName()
{
    return _NickName;
}

std::string Contact::GetPhoneNumber()
{
    return _PhoneNumber;
}

std::string Contact::GetDarkestSecret()
{
    return _DarkestSecret;
}
