#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include <iostream>
# include <string>

class FragTrap {
	private:
		int 		_hit_point;
		int 		_max_hit_point;
		int 		_energy_point;
		int 		_max_energy_point;
		int 		_level;
		std::string	_name;
		int 		_melee_attack_damage;
		int 		_ranged_attack_damage;
		int 		_armor_damage_reduction;
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();
		FragTrap & operator=(FragTrap const & rhs);

		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void 		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		vaulthunter_dot_exe(std::string const & target);

		int 		get_hit_point();
		void		set_hit_point(int value);
		int			get_max_hit_point();
		void		set_max_hit_point(int value);
		int			get_energy_point();
		void 		set_energy_point(int value);
		int			get_max_energy_point();
		void		set_max_energy_point(int value);
		int			get_level();
		void		set_level(int value);
		std::string	get_name();
		void 		set_name(std::string value);
		int			get_melee_attack_damage();
		void		set_melee_attack_damage(int value);
		int			get_ranged_attack_damage();
		void 		set_ranged_attack_damage(int value);
		int			get_armor_damage_reduction();
		void		set_armor_damage_reduction(int value);
};

#endif
