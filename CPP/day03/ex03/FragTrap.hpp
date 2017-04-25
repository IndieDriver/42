#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();

		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void 		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		vaulthunter_dot_exe(std::string const & target);
};

#endif
