#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    srand(time(0));
    char c = "ABC"[rand() % 3];

    std::cout << "Type " << c << " created!" << std::endl;

    if (c == 'A')
        return new A;
    else if (c == 'B')
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
	std::cout << "identify using Base *: ";

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Invalid type" << std::endl;
}

void identify(Base& p)
{
    std::cout << "identify using Base &: ";
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A\n";
    }
    catch(std::bad_cast& e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B\n";
        }
        catch(std::exception& e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C\n";
            }
            catch(std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
}