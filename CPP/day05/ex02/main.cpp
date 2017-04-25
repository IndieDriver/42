#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
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

	ShrubberyCreationForm shrubbery = ShrubberyCreationForm("home");
	RobotomyRequestForm robotomy = RobotomyRequestForm("jerry");
	PresidentialPardonForm pardon = PresidentialPardonForm("rick");

	std::cout << rick;
	std::cout << morty;
	std::cout << summer;
	std::cout << jerry;

	std::cout << std::endl;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;


	std::cout << std::endl << "###### SHRUBBERY ######" << std::endl;
	jerry.executeForm(shrubbery);
	jerry.signForm(shrubbery);
	summer.signForm(shrubbery);
	summer.executeForm(shrubbery);
	morty.executeForm(shrubbery);

	std::cout << std::endl << "###### ROBOTOMY ######" << std::endl;
	summer.signForm(robotomy);
	summer.executeForm(robotomy);
	morty.signForm(robotomy);
	morty.executeForm(robotomy);

	std::cout << std::endl << "###### PRESIDENTIAL PARDON ######" << std::endl;
	morty.signForm(pardon);
	morty.executeForm(pardon);
	rick.executeForm(pardon);
	return 0;
}
