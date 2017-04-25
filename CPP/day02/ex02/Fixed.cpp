#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void) : _fixed_point_value(0) {

}

Fixed::Fixed(int const value) {
	_fixed_point_value = value << this->_fractional_bits;
}

Fixed::Fixed(float const value) {
	_fixed_point_value = roundf(value * (1 << this->_fractional_bits));
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
}

Fixed::~Fixed(void) {

}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	if (this != &rhs)
		this->_fixed_point_value = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const & rhs) {
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs) {
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs) {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs) {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs) {
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs) {
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const & rhs) const {
	int res = this->getRawBits() + rhs.getRawBits();
	float fres = res * (float)(1.0f / (1 << this->_fractional_bits));
	return (Fixed(fres));
}

Fixed Fixed::operator-(Fixed const & rhs) const {
	int res = this->getRawBits() - rhs.getRawBits();
	float fres = res * (float)(1.0f / (1 << this->_fractional_bits));
	return (Fixed(fres));
}

Fixed Fixed::operator*(Fixed const & rhs) const {
	int res = (this->getRawBits() * rhs.getRawBits());
	float fres = res * (float)(1.0f / (1 << this->_fractional_bits * 2));
	return (Fixed(fres));
}

Fixed Fixed::operator/(Fixed const & rhs) const {
	int res = (this->getRawBits() << this->_fractional_bits) / rhs.getRawBits();
	float fres = res * (float)(1.0f / (1 << this->_fractional_bits));
	return (Fixed(fres));
}

Fixed & Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed & Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed res(*this);
	++(*this);
	return (res);
}

Fixed Fixed::operator--(int) {
	Fixed res(*this);
	--(*this);
	return (res);
}

int		Fixed::getRawBits(void) const {
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

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs) {
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs) {
	if (lhs.getRawBits() < rhs.getRawBits())
		return (rhs);
	return (lhs);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i) {
	o << (i.toFloat());
	return (o);
}
