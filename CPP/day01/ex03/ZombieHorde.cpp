#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : nb_zombie(n){
	srand(time(NULL));
	std::string nameArray[4] = {"Jean-Edouard", "Tom", "Roger", "Jerry"};
	_zombies_list = new Zombie[n]();
	for (int i = 0; i < n; i++){
		_zombies_list[i].type = "alpha";
		_zombies_list[i].name = nameArray[rand() % 4];
	}
}

ZombieHorde::~ZombieHorde() {
	delete [] _zombies_list;
}

void ZombieHorde::announce() {
	for (int i = 0; i < nb_zombie; i++){
		_zombies_list[i].announce();
	}
}
