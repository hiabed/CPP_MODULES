#include "Serializer.hpp"

int main()
{
    Data d;
    d.str = "hello";

    //serialize;
    uintptr_t u = Serializer::serialize(&d);
    std::cout << "=============\n";
    std::cout << "d address: " << &d << std::endl;
    std::cout << "d string : " << d.str << std::endl;
    std::cout << "=============\n";
    std::cout << "u value: " << u << std::endl;
    std::cout << "=============\n";
    
    Data *ptr;
    //deserialize;
    ptr = Serializer::deserialize(u);
    std::cout << "ptr address: " << ptr << std::endl;
    std::cout << "ptr string : " << ptr->str << std::endl;
    std::cout << "=============\n";
}
