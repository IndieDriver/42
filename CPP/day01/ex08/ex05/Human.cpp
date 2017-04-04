#include "Human.hpp"

Human::Human() : _brain(Brain()) {

}

Human::~Human() {

}

std::string Human::identify() const {
	return (this->_brain.identify());
}

Brain const &Human::getBrain() const {
	return (_brain);
}
