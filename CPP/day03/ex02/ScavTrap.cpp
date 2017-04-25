#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(100, 100, 50, 50, 1, "scav-trap",20, 15, 3){
	std::cout << "A new SC4V-TP named " << _name << " is born !" << std::endl;
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3){
	std::cout << "A new SC4V-TP named " << _name << " is born !" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "SC4V-TP named " << _name << " was destroyed" << std::endl;
}

void	ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "SC4V-TP " + _name + " attacks " + target + " at range, causing "
		<< this->get_ranged_attack_damage() << " points of damage !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "SC4V-TP " + _name + " melee attacks " + target + " causing "
		<< this->get_melee_attack_damage() << " points of damage !" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	int tmp = this->get_hit_point();
	int new_amount = amount - this->get_armor_damage_reduction();
	this->set_hit_point(tmp - new_amount);
	std::cout << "SC4V-TP " + _name + " took " << tmp - this->get_hit_point()
		<< " points of damage !" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	int tmp = this->get_hit_point();
	this->set_hit_point(tmp + (int)amount);
	std::cout << "SC4V-TP " + _name + " is repaired by " << this->get_hit_point() - tmp
		<< " points !" << std::endl;
}

void	ScavTrap::challengeNewcomer() {
		std::string quoteArray[6] = {
			"challenge 1",
			"challenge 2",
			"challenge 3",
			"challenge 4",
			"challenge 5",
			"challenge 6"
		};
		std::cout << "SC4V-TP " + this->_name + " challenge you to "
			<< quoteArray[rand() % 6] << std::endl;
}
