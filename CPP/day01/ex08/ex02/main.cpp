#include "ZombieEvent.hpp"

int		main(void) {
	ZombieEvent zombieEvent = ZombieEvent();
	zombieEvent.setZombieType("alpha");
	Zombie *zomb1 = zombieEvent.newZombie("George");
	Zombie *zomb2 = zombieEvent.newZombie("Jean-Pierre");
	zomb1->announce();
	zomb2->announce();
	zombieEvent.setZombieType("beta");
	zombieEvent.randomChump();
	delete zomb1;
	delete zomb2;
}
