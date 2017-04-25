#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap(void) : ClapTrap(60, 60, 120, 120, 1, "ninja-trap", 60, 5, 0){
	std::cout << "A new NINJ4-TP named " << _name << " is born !" << std::endl;
}


NinjaTrap::NinjaTrap(std::string name) : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0){
	std::cout << "A new NINJ4-TP named " << _name << " is born !" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) {
	*this = src;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "NINJ4-TP named " << _name << " was destroyed" << std::endl;
}

void	NinjaTrap::rangedAttack(std::string const & target) {
	std::cout << "NINJ4-TP " + _name + " attacks " + target + " at range, causing "
		<< this->get_ranged_attack_damage() << " points of damage !" << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << "NINJ4-TP " + _name + " melee attacks " + target + " causing "
		<< this->get_melee_attack_damage() << " points of damage !" << std::endl;
}

void	NinjaTrap::takeDamage(unsigned int amount) {
	int tmp = this->get_hit_point();
	int new_amount = amount - this->get_armor_damage_reduction();
	this->set_hit_point(tmp - new_amount);
	std::cout << "NINJ4-TP " + _name + " took " << tmp - this->get_hit_point()
		<< " points of damage !" << std::endl;
}

void	NinjaTrap::beRepaired(unsigned int amount) {
	int tmp = this->get_hit_point();
	this->set_hit_point(tmp + (int)amount);
	std::cout << "NINJ4-TP " + _name + " is repaired by " << this->get_hit_point() - tmp
		<< " points !" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & ninjaTrap) {
	ninjaTrap.beRepaired(5);
}

void	NinjaTrap::ninjaShoebox(FragTrap & fragTrap) {
	fragTrap.takeDamage(1);

}

void	NinjaTrap::ninjaShoebox(ScavTrap & scavTrap) {
	scavTrap.meleeAttack("Jack");
}
