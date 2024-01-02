#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "******** ANIMAL CLASS *******\n\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Get type ==> " << j->getType() << " " << std::endl;
    std::cout << "Get type ==> " << i->getType() << " " << std::endl;
    std::cout << "Get type ==> " << meta->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "======== WRONGANIMAL CLASS =========\n\n";

    const WrongAnimal *an = new WrongAnimal();
    const WrongAnimal *Wcat = new WrongCat();

    std::cout << "Get type ==> " << Wcat->getType() << std::endl;
    std::cout << "Get type ==> " << an->getType() << std::endl;
    Wcat->makeSound();
    an->makeSound();
    return 0;
}