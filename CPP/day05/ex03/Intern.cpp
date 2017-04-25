#include "Intern.hpp"

Intern::Intern(void) {

}

Intern::Intern(Intern const & src) {
	*this = src;
}

Intern::~Intern(void) {

}

Intern &	Intern::operator=(Intern const &) {
	return (*this);
}

Form *		Intern::makeForm(std::string form_name, std::string target) {
	Form *form = NULL;
	if (form_name == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	if (form_name == "robotomy request")
		form = new RobotomyRequestForm(target);
	if (form_name == "presidential pardon")
		form = new PresidentialPardonForm(target);
	if (form != NULL)
		std::cout << "Intern create " + form_name + " form"<< std::endl;
	else
		std::cout << "Intern cannot create " + form_name + " form because: form_name is unknown" << std::endl;
	return (form);
}
