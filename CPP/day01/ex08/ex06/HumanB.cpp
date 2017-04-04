#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {

}

HumanB::~HumanB() {

}

void HumanB::attack() {
	std::cout << _name + " attacks with ";
	if (_weapon != NULL)
		std::cout << _weapon->getType();
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
