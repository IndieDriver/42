#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _fixed_point_value(value) {
	_fixed_point_value = value << this->_fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_value = roundf(value * (1 << this->_fractional_bits));
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_fixed_point_value = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixed_point_value = raw;
}

float	Fixed::toFloat(void) const {
	return (_fixed_point_value * (float)(1.0f / (1 << this->_fractional_bits)));
}

int		Fixed::toInt(void) const {
	return (_fixed_point_value >> _fractional_bits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
	o << (i.toFloat());
	return (o);
}
