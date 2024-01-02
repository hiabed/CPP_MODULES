#include "Array.hpp"

int main()
{
    Array<int> B(4);

    std::cout << "The Array size is: " << B.size() << std::endl;
    // assign arrays elements;
    srand(time(0));
    for (unsigned int i = 0; i < B.size(); ++i)
        B[i] = rand();
    // read arrays elements;
    for (unsigned int i = 0; i < B.size(); ++i)
        std::cout << "B[" << i << "]" << " = " << B[i] << std::endl;
    //throwing exception if the index is not found;
    try
    {
        std::cout << B[2] << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
