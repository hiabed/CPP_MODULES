#include "MutantStack.hpp"

// subject test;

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "top element after pop(): " << mstack.top() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(18);
    mstack.push(2);
    mstack.push(150);
    mstack.push(-15);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    *it = 5000;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "top element in the og stack is: " << s.top() << std::endl;
    return 0;
}

// list test;

// int main()
// {
//     std::list<int> lst;
//     lst.push_back(5);
//     lst.push_back(17);
//     std::cout << "top element: " << lst.back() << std::endl;
//     lst.pop_back();
//     std::cout << "top element after pop(): " << lst.back() << std::endl;
//     std::cout << "size: " << lst.size() << std::endl;

//     lst.push_back(18);
//     lst.push_back(2);
//     lst.push_back(150);
//     lst.push_back(-15);
//     std::list<int>::iterator it = lst.begin();
//     std::list<int>::iterator ite = lst.end();
//     ++it;
//     --it;
//     *it = 5000;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     return 0;
// }