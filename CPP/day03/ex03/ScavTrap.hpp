#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();

		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void 		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		challengeNewcomer();
};

#endif
