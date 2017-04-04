#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H
# include "Zombie.hpp"

class ZombieHorde{
	public:
		ZombieHorde(int n);
		~ZombieHorde();
		void	announce();
	private:
		int		nb_zombie;
		Zombie	*_zombies_list;
};

#endif
