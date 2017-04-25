#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this != &rhs){
		this->_target = rhs._target;
	}
	return (*this);
}

void 					RobotomyRequestForm::action() const {
	std::cout << "**BVVVVVVVVVVVVVVVVV**" << std::endl;
	if (rand() % 2 == 1) {
		std::cout << _target + " has been robotomized successfully" << std::endl;
	} else {
		std::cout << _target + " robotomization failed" << std::endl;
	}
}
