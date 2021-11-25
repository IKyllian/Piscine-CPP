#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value)
{
	this->_value = value << bits;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << bits));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Assignation operator called" << std::endl;
	_value = src.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_value) / (1 << bits));
}

int Fixed::toInt(void) const
{
	return ((int)this->_value >> bits);
}


int Fixed::getRawBits(void) const
{
	// std::cout << "getRawbits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

bool Fixed::operator<(const Fixed& fx) const
{
	return (this->_value < fx._value);
}

bool Fixed::operator>(const Fixed& fx) const
{
	return (this->_value > fx._value);
}

bool Fixed::operator<=(const Fixed& fx) const
{
	return (this->_value <= fx._value);
}

bool Fixed::operator>=(const Fixed& fx) const
{
	return (this->_value >= fx._value);
}

bool Fixed::operator==(const Fixed& fx) const
{
	return (this->_value == fx._value);
}

bool Fixed::operator!=(const Fixed& fx) const
{
	return (this->_value != fx._value);
}

Fixed Fixed::operator+(const Fixed& fx)
{
	Fixed fixed;

	fixed.setRawBits(this->_value += fx.getRawBits());
	return (fixed);
}

Fixed Fixed::operator-(const Fixed& fx) 
{
	Fixed fixed;

	fixed.setRawBits(this->_value -= fx.getRawBits());
	return (fixed);
}

Fixed Fixed::operator*(const Fixed& fx)
{
	Fixed fixed;

	fixed.setRawBits(this->_value *= fx._value);
	return (fixed);
}

Fixed Fixed::operator/(const Fixed& fx)
{
	Fixed fixed;

	fixed.setRawBits(this->_value /= fx._value);
	return (fixed);
}


Fixed &Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed &Fixed::operator++(int)
{
	Fixed fixed(*this);

	++this->_value;
	return (*this);
}
		
Fixed &Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed &Fixed::operator--(int)
{
	Fixed fixed(*this);

	--this->_value;
	return (*this);
}

Fixed& min(Fixed const &fx1, Fixed const &fx2) const
{
	if (fx1 < fx2)
		return (fx1);
	else
		return (fx2);
}
	
Fixed& max(Fixed const &fx1, Fixed const &fx2) const
{
	if (fx1 > fx2)
		return (fx1);
	else
		return (fx2);
}