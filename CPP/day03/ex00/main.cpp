#include <iostream>
#include "FragTrap.hpp"

int	main() {
	FragTrap fragTrap("cl4p-tr4p");
	srand(time(NULL));

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

	return (1);
}
