#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default name") {

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
}

Bureaucrat::~Bureaucrat(void) {

}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs){
		this->_grade = rhs._grade;
	}
	return (*this);
}

void		Bureaucrat::incGrade() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::decGrade() {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int			Bureaucrat::getGrade() const {
	return (this->_grade);
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {

}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) {
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {

}
Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &) {
	return (*this);
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {

}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) {
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {

}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &) {
	return (*this);
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i) {
	o << i.getName() + ", bureaucrat grade " << i.getGrade() << std::endl;;
	return (o);
}
