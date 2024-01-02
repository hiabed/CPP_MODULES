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
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();
	void setRawBits(int const raw);
	int getRawBits(void) const;
	float toFloat( void ) const;
	int toInt( void ) const;
};
std::ostream &operator<<( std::ostream &output, Fixed const &object);


#endif
