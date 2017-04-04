#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include <string>
#include <cstdlib>
#include "Zombie.hpp"

class ZombieEvent {
	public:
		ZombieEvent();
		~ZombieEvent();
		void	setZombieType(std::string type);
		Zombie	*newZombie(std::string name);
		void	randomChump();
	private:
		std::string _type;
};

#endif
