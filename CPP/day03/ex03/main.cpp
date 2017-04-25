#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int	main() {
	srand(time(NULL));

	FragTrap fragTrap("cl4p-tr4p");
	fragTrap.meleeAttack("Jack");
	fragTrap.vaulthunter_dot_exe("Jack");

	ScavTrap scavTrap("sc4v-tr4p");
	scavTrap.rangedAttack("Jack");
	scavTrap.challengeNewcomer();

	NinjaTrap ninjaTrap("ninj4-tr4p");
	ninjaTrap.meleeAttack("Jack");

	ninjaTrap.ninjaShoebox(fragTrap);
	ninjaTrap.ninjaShoebox(scavTrap);
	ninjaTrap.ninjaShoebox(ninjaTrap);

	return (1);
}
