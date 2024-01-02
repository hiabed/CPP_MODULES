#include "iter.hpp"

int main()
{
    // print function will work for both const type(i.e => const int) and type(i.e => int);

    // print function that takes const int;
    std::cout << "int array\n";
    int arr[] = {1, 2, 3, 4};
    iter(arr, 4, &print<const int>);

    // print function that takes int;
    std::cout << "int array\n";
    iter(arr, 4, &print<int>);

    // both are compiled and worked succesfully;

    // the same for the rest of types;
    std::cout << "\narray of characters\n";
    char s[] = "hello";
    iter(s, 5, &print<char>);

    std::cout << "\ndouble array\n";
    double dArr[] = {1.2, 2.3, 3.4, 4.5};
    iter(dArr, 4, &print<double>);

    std::cout << "\narray of strings\n";
    std::string strings[] = {"hello", "world", "!!"};
    iter(strings, 3, &print<std::string>);
}
