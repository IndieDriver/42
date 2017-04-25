#include "FragTrap.hpp"


FragTrap::FragTrap(void) : ClapTrap(100, 100, 100, 100, 1, "frag-trap", 30, 20, 5){
	std::cout << "A new FR4G-TP named " << _name << " is born !" << std::endl;
}


FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5){
	std::cout << "A new FR4G-TP named " << _name << " is born !" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) {
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "FR4G-TP named " << _name << " was destroyed" << std::endl;
}

void	FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP " + _name + " attacks " + target + " at range, causing "
		<< this->get_ranged_attack_damage() << " points of damage !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " + _name + " melee attacks " + target + " causing "
		<< this->get_melee_attack_damage() << " points of damage !" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	int tmp = this->get_hit_point();
	int new_amount = amount - this->get_armor_damage_reduction();
	this->set_hit_point(tmp - new_amount);
	std::cout << "FR4G-TP " + _name + " took " << tmp - this->get_hit_point()
		<< " points of damage !" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	int tmp = this->get_hit_point();
	this->set_hit_point(tmp + (int)amount);
	std::cout << "FR4G-TP " + _name + " is repaired by " << this->get_hit_point() - tmp
		<< " points !" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->get_energy_point() - 25 >= 0){
		this->set_energy_point(this->get_energy_point() - 25);
		std::string quoteArray[6] = {
			"This time it'll be awesome, I promise!",
			"Where'd all my bullets go?",
			"Wheeeee!",
			"RUN FOR YOUR LIIIIIVES!!!"
			"square the I, carry the 1... YES!",
			"Can I shoot something now? Or climb some stairs? SOMETHING exciting?",
			"Did you guys see that?!"
		};
		std::cout << "FR4G-TP " + this->_name + " attacks " + target
			+ " while screaming: \"" << quoteArray[rand() % 6] << "\"" << std::endl;
	} else {
		std::cout << "Out of energy :(" << std::endl;
	}

}
