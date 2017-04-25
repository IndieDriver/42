#include "Form.hpp"

Form::Form(void) : _name("default form"), _signed(false), _gradeToSign(150), _gradeToExec(150){

}

Form::Form(Form const & src) :
	_name(src.getName()),
	_gradeToSign(src.getSignGrade()),
	_gradeToExec(src.getExecGrade()) {
	*this = src;
}

Form::Form(std::string name, int signGrade, int execGrade) :
	_name(name), _signed(false), _gradeToSign(signGrade), _gradeToExec(execGrade) {
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150)
		throw GradeTooLowException();
	if (_gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToExec > 150)
		throw GradeTooLowException();

}

Form::~Form(void) {

}

Form &	Form::operator=(Form const & rhs) {
	if (this != &rhs){
		this->_signed = rhs._signed;
	}
	return (*this);
}

void	Form::beSigned(Bureaucrat *bureaucrat) {
	if (bureaucrat->getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_signed = true;
}

std::string			Form::getName() const {
	return(this->_name);
}

bool				Form::isSigned() const {
	return(this->_signed);
}

int					Form::getSignGrade() const {
	return(this->_gradeToSign);
}

int					Form::getExecGrade() const {
	return(this->_gradeToExec);
}

Form::GradeTooLowException::GradeTooLowException() {

}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) {
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {

}
Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &) {
	return (*this);
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

Form::GradeTooHighException::GradeTooHighException() {

}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) {
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {

}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const &) {
	return (*this);
}

const char * Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

std::ostream &	operator<<(std::ostream & o, Form const & i) {
	o << "Form " + i.getName();
	if (i.isSigned())
		o << " is signed";
	else
		o << " is not signed";
	o << ", need at least a grade of " << i.getSignGrade() << " to be signed";
	o << ", and a grade " << i.getExecGrade() << " to be executed" << std::endl;
	return (o);
}
