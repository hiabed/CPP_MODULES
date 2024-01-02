#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class Weapon;

class HumanB
{
private:
    Weapon *_Weapon;
    std::string _name;
public:
    HumanB(std::string name);
    ~HumanB();
    void setWeapon(Weapon &weapon);
    void attack();
};

#endif