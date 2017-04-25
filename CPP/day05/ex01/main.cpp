#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Form form1("form1", 10, 30);
	Form form2("form2", 42, 42);
	Bureaucrat rick2("rick2", 42);

	try {
		std::cout << rick2;
		std::cout << form1;
		rick2.signForm(&form1);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << form2;
		rick2.signForm(&form2);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
