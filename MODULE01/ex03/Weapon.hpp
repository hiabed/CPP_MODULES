#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string _type;
public:
    void setType(std::string type);
    const std::string &getType();
    Weapon(const std::string &type);
    ~Weapon();
};





#endif