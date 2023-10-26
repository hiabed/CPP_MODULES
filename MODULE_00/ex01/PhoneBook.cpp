#include "PhoneBook.hpp"

void PhoneBook::SetContact(Contact contact, int i)
{
    _contacts[i] = contact;
}

Contact PhoneBook::GetContact(int i)
{
    return _contacts[i];
}