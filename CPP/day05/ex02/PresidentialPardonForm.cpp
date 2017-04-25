#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs){
		this->_target = rhs._target;
	}
	return (*this);
}

void 					PresidentialPardonForm::action() const {
	std::cout << this->_target + " has been pardoned by Zafod Beeblebrox" << std::endl;
}
