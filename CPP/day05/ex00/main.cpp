#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int main(void)
{

	try {
		Bureaucrat rick("rick", 0);
		std::cout << rick;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat summer("summer", 420);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat morty("morty", 1);
	try {
		std::cout << morty;
		morty.incGrade();
		std::cout << morty;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat jerry("jerry", 150);
	try {
		std::cout << jerry;
		jerry.decGrade();
		std::cout << jerry;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}



	return 0;
}
