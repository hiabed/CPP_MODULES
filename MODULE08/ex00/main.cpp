#include "easyfind.hpp"

int main()
{
    // vector test;
    std::vector<int> vArr;
    vArr.push_back(-1);
    vArr.push_back(5);
    vArr.push_back(7);
    vArr.push_back(9);
    vArr.push_back(15);
    try
    {
        std::cout << easyfind(vArr, 2222) << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what();
    }
    try
    {
        std::cout << easyfind(vArr, -1) << std::endl;
    }
    catch (std::exception &e)
    {
        e.what();
    }
    // deque test;
    std::deque <int> dArr;
    dArr.push_back(-1);
    dArr.push_back(5);
    dArr.push_back(7);
    dArr.push_front(3);
    try
    {
        std::cout << easyfind(dArr, 3) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }
    // list test;
    std::list <int> lArr;
    lArr.push_back(-1);
    lArr.push_back(5);
    lArr.push_back(7);
    lArr.push_front(3);
    try
    {
        std::cout << easyfind(lArr, 5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }
    try
    {
        std::cout << easyfind(lArr, 0) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }
}