#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	srand(time(NULL));

	FragTrap fragTrap("cl4p-tr4p");

	fragTrap.rangedAttack("Jack");
	fragTrap.meleeAttack("Jack");

	std::cout << "health: " << fragTrap.get_hit_point() << std::endl;
	fragTrap.takeDamage(20);
	std::cout << "health: " << fragTrap.get_hit_point() << std::endl;
	fragTrap.takeDamage(420);
	std::cout << "health: " << fragTrap.get_hit_point() << std::endl;
	fragTrap.beRepaired(420);
	std::cout << "health: " << fragTrap.get_hit_point() << std::endl;

	fragTrap.vaulthunter_dot_exe("Jack");
	fragTrap.vaulthunter_dot_exe("Jack");
	fragTrap.vaulthunter_dot_exe("Jack");
	fragTrap.vaulthunter_dot_exe("Jack");
	fragTrap.vaulthunter_dot_exe("Jack");

	ScavTrap scavTrap("sc4v-tr4p");

	scavTrap.rangedAttack("Jack");
	scavTrap.meleeAttack("Jack");

	std::cout << "health: " << scavTrap.get_hit_point() << std::endl;
	scavTrap.takeDamage(40);
	std::cout << "health: " << scavTrap.get_hit_point() << std::endl;
	scavTrap.takeDamage(100);
	std::cout << "health: " << scavTrap.get_hit_point() << std::endl;
	scavTrap.beRepaired(42);
	std::cout << "health: " << scavTrap.get_hit_point() << std::endl;


	scavTrap.challengeNewcomer();
	scavTrap.challengeNewcomer();
	scavTrap.challengeNewcomer();
	scavTrap.challengeNewcomer();

	return (1);
}
