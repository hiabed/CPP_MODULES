#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath>

class Fixed
{
  private:
	int fixed_point;
	static const int frac_bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &copy_constructor);
	Fixed &operator=(const Fixed &other);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();
	void setRawBits(int const raw);
	int getRawBits(void) const;
	float toFloat( void ) const;
	int toInt( void ) const;
	bool operator>(Fixed const &obj);
	bool operator<(Fixed const &obj);
	bool operator>=(Fixed const &obj);
	bool operator<=(Fixed const &obj);
	bool operator==(Fixed const &obj);
	bool operator!=(Fixed const &obj);
	Fixed operator+(Fixed const &obj);
	Fixed operator-(Fixed const &obj);
	Fixed operator*(Fixed const &obj);
	Fixed operator/(Fixed const &obj);
	Fixed &operator++();
	Fixed operator++(int);
	static Fixed &min(Fixed &obj1, Fixed &obj2);
	static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
	static Fixed &max(Fixed &obj1, Fixed &obj2);
	static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
};

std::ostream &operator<<(std::ostream &output, Fixed const &object);

#endif
