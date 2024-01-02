#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("hZombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("sZombie");
}