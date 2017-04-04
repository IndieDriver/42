#include "Brain.hpp"

Brain::Brain() {

}

Brain::~Brain() {

}

std::string Brain::identify() const {
	std::stringstream ss;
	ss << this;
	return (ss.str());
}
