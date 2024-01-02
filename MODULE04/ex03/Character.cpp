#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    _name = "Abed";
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
        unequiped_slots[i] = NULL;
    }
}

Character::Character(std::string name)
{
    _name = name;
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
        unequiped_slots[i] = NULL;
    }
}

Character::Character(const Character &other)
{
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
        unequiped_slots[i] = NULL;
    }
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (slots[i])
                delete slots[i];
            if (other.slots[i])
                this->slots[i] = other.slots[i]->clone();
            this->unequiped_slots[i] = other.unequiped_slots[i];
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        delete unequiped_slots[i];
        unequiped_slots[i] = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] == m)
            return ;
        if(slots[i] == NULL)
        {
            slots[i] = m;
            return ;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
    {
        std::cout << "Please enter index between 0 and 3";
        return ;
    }
    if(slots[idx])
    {
        for (int i = 0; i < 4; i++)
        {
            if(unequiped_slots[i] == NULL)
            {
                unequiped_slots[i] = slots[idx];
                break;
            }
        }
        slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Please enter an index between 0 and 3";
        return ;
    }
    if (slots[idx])
        slots[idx]->use(target);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete slots[i];
        delete unequiped_slots[i];
    }
}