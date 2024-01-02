#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            delete materias[i];
            if (other.materias[i])
                this->materias[i] = other.materias[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if(materias[i] == NULL)
        {
            materias[i] = m;
            return ;
        }
        if (i == 3)
            return ;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if(materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 4; j++)
        {
            if (materias[i] == materias[j])
                materias[j] = NULL;
        }
        if (materias[i])
            delete materias[i];
    }
}
