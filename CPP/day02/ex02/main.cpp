#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a1(5.05f);
	Fixed a2(2);
	Fixed a3(5.05f);

	std::cout << "Fixed(5.05f): " << a1 << std::endl;
	std::cout << "Fixed(2): " << a2 << std::endl;

	std::cout << "5.05f + 2.0f: " << a1 + a2 << std::endl;
	std::cout << "5.05f - 2.0f: " << a1 - a2 << std::endl;
	std::cout << "5.05f / 2.0f: " << a1 / a2 << std::endl;
	std::cout << "5.05f * 2.0f: " << a1 * a2 << std::endl;

	std::cout << "5.05f < 2.0f: " << (a1 < a2) << std::endl;
	std::cout << "5.05f > 2.0f: " << (a1 > a2) << std::endl;

	std::cout << "5.05f <= 5.05f: " << (a1 <= a3) << std::endl;
	std::cout << "5.05f >= 5.05f: " << (a1 >= a3) << std::endl;
	std::cout << "5.05f == 5.05f: " << (a1 == a3) << std::endl;
	std::cout << "5.05f != 5.05f: " << (a1 != a3) << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
