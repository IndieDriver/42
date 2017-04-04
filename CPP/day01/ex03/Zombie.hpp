#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie(const std::string &type = "default_type", const std::string &name = "default_name") ;
		~Zombie();
		void announce();
		std::string type;
		std::string name;
};

#endif
