#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("clap-trap"){
	std::cout << "A new CLAP-TRAP named" + _name + " is born !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "A new CLAP-TRAP named" + _name + " is born !" << std::endl;
}

ClapTrap::ClapTrap(int hp, int max_hp, int ep, int max_ep, int level,
		std::string name, int melee_atk,int ranged_atk,
		int armor_reduc) :	_hit_point(hp),
							_max_hit_point(max_hp),
							_energy_point(ep),
							_max_energy_point(max_ep),
							_level(level),
							_name(name),
							_melee_attack_damage(melee_atk),
							_ranged_attack_damage(ranged_atk),
							_armor_damage_reduction(armor_reduc) {
	std::cout << "A new CLAP-TRAP named" + _name + " is born !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap named " << _name << " was destroyed" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
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

int		ClapTrap::get_hit_point() {
	return (this->_hit_point);
}

void	ClapTrap::set_hit_point(int value) {
	if (value > this->get_max_hit_point())
		value = this->get_max_hit_point();
	if (value < 0)
		value = 0;
	this->_hit_point = value;
}

int		ClapTrap::get_max_hit_point() {
	return (this->_max_hit_point);
}

void	ClapTrap::set_max_hit_point(int value) {
	this->_max_hit_point = value;
}

int		ClapTrap::get_energy_point() {
	return (this->_energy_point);
}

void	ClapTrap::set_energy_point(int value) {
	if (value > this->get_max_energy_point())
		value = this->get_max_energy_point();
	if (value < 0)
		value = 0;
	this->_energy_point = value;
}

int		ClapTrap::get_max_energy_point() {
	return (this->_max_energy_point);
}

void	ClapTrap::set_max_energy_point(int value) {
	this->_max_energy_point = value;
}

int		ClapTrap::get_level() {
	return (this->_level);
}

void	ClapTrap::set_level(int value) {
	this->_level = value;
}

std::string ClapTrap::get_name() {
	return (this->_name);
}

void	ClapTrap::set_name(std::string value) {
	this->_name = value;
}

int		ClapTrap::get_melee_attack_damage() {
	return (this->_melee_attack_damage);
}

void	ClapTrap::set_melee_attack_damage(int value) {
	this->_melee_attack_damage = value;
}

int		ClapTrap::get_ranged_attack_damage() {
	return (this->_ranged_attack_damage);
}

void	ClapTrap::set_ranged_attack_damage(int value) {
	this->_ranged_attack_damage = value;
}

int		ClapTrap::get_armor_damage_reduction() {
	return (this->_armor_damage_reduction);
}

void	ClapTrap::set_armor_damage_reduction(int value) {
	this->_armor_damage_reduction = value;
}
