#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {

}

ZombieEvent::~ZombieEvent() {

}

void ZombieEvent::setZombieType(std::string type) {
	this->_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name) {
	Zombie *zombie = new Zombie(_type, name);
	return (zombie);
}

void	ZombieEvent::randomChump() {
	std::string nameArray[4] = {"Jean-Edouard", "Tom", "Roger", "Jerry"};
	srand(time(NULL));
	int randNum = rand() % 4;
	Zombie zombie = Zombie(_type, nameArray[randNum]);
	zombie.announce();
}
