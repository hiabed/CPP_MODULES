#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <iostream>

template <typename T>

class MutantStack : public std::stack<T>
{
public:
    typedef typename std::deque<T>::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }
    // orthodox canolical form;
    MutantStack(){}
    MutantStack(const MutantStack &other) { *this = other; }
    MutantStack &operator=(const MutantStack &other) { (void)other; return *this; }
    ~MutantStack() {}
};

#endif