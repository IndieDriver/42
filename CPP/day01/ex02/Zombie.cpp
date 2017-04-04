#include "Zombie.hpp"

Zombie::Zombie(const std::string &type, const std::string &name) : _type(type), _name(name) {
	std::cout << "Zombie " + _name + " created with type " + _type << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " + _name + " destroyed" << std::endl;
}

void Zombie::announce(){
	std::cout << "<" + _name << + " (" + _type + ")> Braiiiiiiinnnssss..." << std::endl;
}
