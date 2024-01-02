#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
private:
    AMateria *unequiped_slots[4];
    AMateria *slots[4];
    std::string _name;
public:
    Character();
    Character(std::string name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character();
    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};


#endif