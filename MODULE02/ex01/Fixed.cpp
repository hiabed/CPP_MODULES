#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    fixed_point = 0;
}

Fixed::Fixed(const int nb)
{
    std::cout << "Int constructor called\n";
    fixed_point = nb << frac_bits;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}

Fixed::Fixed(const float nb)
{
    std::cout << "Float constructor called\n";
    fixed_point = (roundf(nb * (1 << frac_bits)));
}

float Fixed::toFloat( void ) const
{
    return ((float)fixed_point / (1 << frac_bits));
}

int Fixed::toInt( void ) const
{
    int to_int = fixed_point >> frac_bits;
    return to_int;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
    {
        fixed_point = other.fixed_point;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &output, Fixed const &object)
{
    output << object.toFloat();
    return output;
}