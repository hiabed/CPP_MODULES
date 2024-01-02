#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);
    ~Cure();
    std::string const & getType() const; //Returns the materia type.
    Cure* clone() const;
    void use(ICharacter& target);
};

#endif