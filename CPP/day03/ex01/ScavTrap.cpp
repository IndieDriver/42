#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : 	_hit_point(100),
							_max_hit_point(100),
							_energy_point(50),
							_max_energy_point(50),
							_level(1),
							_name("scav"),
							_melee_attack_damage(20),
							_ranged_attack_damage(15),
							_armor_damage_reduction(3)
{
	std::cout << "A new SC4V-TP named " << _name << " is born !" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : 	_hit_point(100),
										_max_hit_point(100),
										_energy_point(50),
										_max_energy_point(50),
										_level(1),
										_name(name),
										_melee_attack_damage(20),
										_ranged_attack_damage(15),
										_armor_damage_reduction(3)
{
	std::cout << "A new SC4V-TP named " << _name << " is born !" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "SC4V-TP named " << _name << " was destroyed" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
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

int		ScavTrap::get_hit_point() {
	return (this->_hit_point);
}

void	ScavTrap::set_hit_point(int value) {
	if (value > this->get_max_hit_point())
		value = this->get_max_hit_point();
	if (value < 0)
		value = 0;
	this->_hit_point = value;
}

int		ScavTrap::get_max_hit_point() {
	return (this->_max_hit_point);
}

void	ScavTrap::set_max_hit_point(int value) {
	this->_max_hit_point = value;
}

int		ScavTrap::get_energy_point() {
	return (this->_energy_point);
}

void	ScavTrap::set_energy_point(int value) {
	if (value > this->get_max_energy_point())
		value = this->get_max_energy_point();
	if (value < 0)
		value = 0;
	this->_energy_point = value;
}

int		ScavTrap::get_max_energy_point() {
	return (this->_max_energy_point);
}

void	ScavTrap::set_max_energy_point(int value) {
	this->_max_energy_point = value;
}

int		ScavTrap::get_level() {
	return (this->_level);
}

void	ScavTrap::set_level(int value) {
	this->_level = value;
}

std::string ScavTrap::get_name() {
	return (this->_name);
}

void	ScavTrap::set_name(std::string value) {
	this->_name = value;
}

int		ScavTrap::get_melee_attack_damage() {
	return (this->_melee_attack_damage);
}

void	ScavTrap::set_melee_attack_damage(int value) {
	this->_melee_attack_damage = value;
}

int		ScavTrap::get_ranged_attack_damage() {
	return (this->_ranged_attack_damage);
}

void	ScavTrap::set_ranged_attack_damage(int value) {
	this->_ranged_attack_damage = value;
}

int		ScavTrap::get_armor_damage_reduction() {
	return (this->_armor_damage_reduction);
}

void	ScavTrap::set_armor_damage_reduction(int value) {
	this->_armor_damage_reduction = value;
}

