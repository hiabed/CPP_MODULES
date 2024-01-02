#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>

class Array
{
private:
    // private attributes;
    T *_a;
    unsigned int _n;
public:
    size_t size() const
    {
        return _n;
    }
    // orthodox canolical form;
    Array()
    {
        _n = 0;
        _a = NULL;
    }
    Array(unsigned int n)
    {
        _n = n;
        _a = new T[_n]();
    }
    Array(const Array &other)
    {
        _a = NULL;
        *this = other;
    }
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _a;
            _n = other._n;
            _a = new T[_n]();
            for (unsigned int i = 0; i < _n; i++)
                this->_a[i] = other._a[i];
        }
        return *this;
    }
    ~Array()
    {
        delete[] _a;
    }
    //  subscript operator overloading;
    T &operator[](unsigned int index)
    {
        if (index < _n)
            return _a[index];
        throw std::out_of_range("Index out of range");
    }
    // if the object declared is const;
    const T &operator[](unsigned int index) const
    {
        if (index < _n)
            return _a[index];
        throw std::out_of_range("Index out of range");
    }
};

#endif