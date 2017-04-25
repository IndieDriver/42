#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat rick("rick", 1);
	Bureaucrat morty("morty", 20);
	Bureaucrat summer("summer", 140);
	Bureaucrat jerry("jerry", 150);

	Intern someRandomIntern;


	Form *shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
	Form *robotomy = someRandomIntern.makeForm("robotomy request", "jerry");
	Form *pardon = someRandomIntern.makeForm("presidential pardon", "rick");

	Form *random = someRandomIntern.makeForm("random", "random");
	std::cout << random << std::endl << std::endl;

	std::cout << rick;
	std::cout << morty;
	std::cout << summer;
	std::cout << jerry;

	std::cout << std::endl;
	std::cout << *shrubbery;
	std::cout << *robotomy;
	std::cout << *pardon;


	std::cout << std::endl << "###### SHRUBBERY ######" << std::endl;
	jerry.executeForm(*shrubbery);
	jerry.signForm(*shrubbery);
	summer.signForm(*shrubbery);
	summer.executeForm(*shrubbery);
	morty.executeForm(*shrubbery);

	std::cout << std::endl << "###### ROBOTOMY ######" << std::endl;
	summer.signForm(*robotomy);
	summer.executeForm(*robotomy);
	morty.signForm(*robotomy);
	morty.executeForm(*robotomy);

	std::cout << std::endl << "###### PRESIDENTIAL PARDON ######" << std::endl;
	morty.signForm(*pardon);
	morty.executeForm(*pardon);
	rick.executeForm(*pardon);

	delete shrubbery;
	delete robotomy;
	delete pardon;
	return 0;
}
