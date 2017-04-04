#include "Human.hpp"

void Human::meleeAttack(std::string const & target){
	std::cout << "melee attack on " + target << std::endl;
}

void Human::rangedAttack(std::string const & target){
	std::cout << "ranged attach on " + target << std::endl;
}

void Human::intimidatingShout(std::string const & target){
	std::cout << "intimidating shoud on " + target << std::endl;
}

void Human::action(std::string const & action_name, std::string const &target) {

}
