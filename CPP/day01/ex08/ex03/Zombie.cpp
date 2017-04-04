#include "Zombie.hpp"

Zombie::Zombie(const std::string &type, const std::string &name) : type(type), name(name) {
	std::cout << "Zombie " + name + " created with type " + type << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " + name + " destroyed" << std::endl;
}

void Zombie::announce(){
	std::cout << "<" + name << + " (" + type + ")> Braiiiiiiinnnssss..." << std::endl;
}
