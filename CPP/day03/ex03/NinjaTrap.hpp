#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>

class NinjaTrap : public ClapTrap{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap();

		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void 		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		ninjaShoebox(NinjaTrap & ninjaTrap);
		void		ninjaShoebox(FragTrap & fragTrap);
		void		ninjaShoebox(ScavTrap & scavTrap);
};

#endif
