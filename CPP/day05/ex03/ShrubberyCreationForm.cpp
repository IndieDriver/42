#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137) {

}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs){
		this->_target = rhs._target;
	}
	return (*this);
}

void 					ShrubberyCreationForm::action() const {
	std::string tree;
	tree += "    ###\n";
	tree += "   #o###\n";
	tree += " #####o###\n";
	tree += "#o#\\#|#/###\n";
	tree += " ###\\|/#o#\n";
	tree += "  # }|{  #\n";
	tree += "    }|{\n";
	std::ofstream file(_target + "_shrubbery");
	if (file.is_open()) {
		file << tree;
		file.close();
	}
}
