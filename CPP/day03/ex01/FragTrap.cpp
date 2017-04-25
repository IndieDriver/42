#include "FragTrap.hpp"

FragTrap::FragTrap(void) : 	_hit_point(100),
							_max_hit_point(100),
							_energy_point(100),
							_max_energy_point(100),
							_level(1),
							_name("jerry"),
							_melee_attack_damage(30),
							_ranged_attack_damage(20),
							_armor_damage_reduction(5)
{
	std::cout << "A new FR4G-TP named " << _name << " is born !" << std::endl;
}

FragTrap::FragTrap(std::string name) : 	_hit_point(100),
										_max_hit_point(100),
										_energy_point(100),
										_max_energy_point(100),
										_level(1),
										_name(name),
										_melee_attack_damage(30),
										_ranged_attack_damage(20),
										_armor_damage_reduction(5)
{
	std::cout << "A new FR4G-TP named " << _name << " is born !" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) {
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "FR4G-TP named " << _name << " was destroyed" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
	if (this != &rhs){
	 	this->_hit_point = get_hit_point();
		this->_max_hit_point = get_max_hit_point();
		this->_energy_point = get_energy_point();
		this->_max_energy_point = get_max_energy_point();
		this->_level = get_level();
		this->_name = get_name();
		this->_melee_attack_damage = get_melee_attack_damage();
		this->_ranged_attack_damage = get_ranged_attack_damage();
		this->_armor_damage_reduction = get_armor_damage_reduction();
	}
	return (*this);
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

int		FragTrap::get_hit_point() {
	return (this->_hit_point);
}

void	FragTrap::set_hit_point(int value) {
	if (value > this->get_max_hit_point())
		value = this->get_max_hit_point();
	if (value < 0)
		value = 0;
	this->_hit_point = value;
}

int		FragTrap::get_max_hit_point() {
	return (this->_max_hit_point);
}

void	FragTrap::set_max_hit_point(int value) {
	this->_max_hit_point = value;
}

int		FragTrap::get_energy_point() {
	return (this->_energy_point);
}

void	FragTrap::set_energy_point(int value) {
	if (value > this->get_max_energy_point())
		value = this->get_max_energy_point();
	if (value < 0)
		value = 0;
	this->_energy_point = value;
}

int		FragTrap::get_max_energy_point() {
	return (this->_max_energy_point);
}

void	FragTrap::set_max_energy_point(int value) {
	this->_max_energy_point = value;
}

int		FragTrap::get_level() {
	return (this->_level);
}

void	FragTrap::set_level(int value) {
	this->_level = value;
}

std::string FragTrap::get_name() {
	return (this->_name);
}

void	FragTrap::set_name(std::string value) {
	this->_name = value;
}

int		FragTrap::get_melee_attack_damage() {
	return (this->_melee_attack_damage);
}

void	FragTrap::set_melee_attack_damage(int value) {
	this->_melee_attack_damage = value;
}

int		FragTrap::get_ranged_attack_damage() {
	return (this->_ranged_attack_damage);
}

void	FragTrap::set_ranged_attack_damage(int value) {
	this->_ranged_attack_damage = value;
}

int		FragTrap::get_armor_damage_reduction() {
	return (this->_armor_damage_reduction);
}

void	FragTrap::set_armor_damage_reduction(int value) {
	this->_armor_damage_reduction = value;
}

