#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>
# include <string>

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();
		ClapTrap & operator=(ClapTrap const & rhs);

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

	protected:
		ClapTrap(int hp, int max_hp, int ep, int max_ep, int level,
				std::string name, int melee_atk,int ranged_atk, int armor_reduc);
		int 		_hit_point;
		int 		_max_hit_point;
		int 		_energy_point;
		int 		_max_energy_point;
		int 		_level;
		std::string	_name;
		int 		_melee_attack_damage;
		int 		_ranged_attack_damage;
		int 		_armor_damage_reduction;
};

#endif
