#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    Dog *dog1 = new Dog;
    Dog *dog2 = new Dog;
    
    std::cout << "Animal type: " << dog1->getType() << std::endl;
    std::cout << "Animal type: " << dog2->getType() << std::endl;
    dog1->makeSound();
    dog2->makeSound();
    Cat *cat1 = new Cat;
    Cat *cat2 = new Cat;

    std::cout << "Animal type: "<< cat1->getType() << std::endl;
    std::cout << "Animal type: "<< cat2->getType() << std::endl;
    cat1->makeSound();
    cat2->makeSound();
    Animal *arr[4] = {dog1, dog2, cat1, cat2};
    for(int i = 0; i < 4; i++)
        delete arr[i];
    delete j; //should not create a leak
    delete i;
    return 0;
}
