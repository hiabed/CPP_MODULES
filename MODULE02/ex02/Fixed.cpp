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
    return fixed_point >> frac_bits;
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
        fixed_point = other.fixed_point;
    return *this;
}

std::ostream &operator<<(std::ostream &output, Fixed const &object)
{
    output << object.toFloat();
    return output;
}

bool Fixed::operator>(Fixed const &obj)
{
    return fixed_point > obj.fixed_point;
}

bool Fixed::operator<(Fixed const &obj)
{
    return fixed_point < obj.fixed_point;
}

bool Fixed::operator>=(Fixed const &obj)
{
    return fixed_point >= obj.fixed_point;
}

bool Fixed::operator<=(Fixed const &obj)
{
    return fixed_point <= obj.fixed_point;
}

bool Fixed::operator==(Fixed const &obj)
{
    return fixed_point == obj.fixed_point;
}

bool Fixed::operator!=(Fixed const &obj)
{
    return fixed_point != obj.fixed_point;
}

Fixed Fixed::operator+(Fixed const &obj)
{
    Fixed res;
    res.fixed_point = fixed_point + obj.fixed_point;
    return res;
}

Fixed Fixed::operator-(Fixed const &obj)
{
    Fixed res;
    res.fixed_point = fixed_point - obj.fixed_point;
    return res;
}

Fixed Fixed::operator*(Fixed const &obj)
{
    Fixed res; 
    res.fixed_point = fixed_point  * obj.fixed_point / (1 << frac_bits);
    return res;
}

Fixed Fixed::operator/(Fixed const &obj)
{
    Fixed res;
    res.fixed_point = (fixed_point * (1 << frac_bits) / obj.fixed_point);
    return res;
}

Fixed &Fixed::operator++()
{
    ++fixed_point;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed original(*this);
    fixed_point++;
    return original;
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
    if(obj1.fixed_point <= obj2.fixed_point)
        return obj1;
    else
        return obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    if(obj1.fixed_point <= obj2.fixed_point)
        return obj1;
    else
        return obj2;
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if(obj1.fixed_point >= obj2.fixed_point)
        return obj1;
    else
        return obj2;
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    if(obj1.fixed_point >= obj2.fixed_point)
        return obj1;
    else
        return obj2;
}
