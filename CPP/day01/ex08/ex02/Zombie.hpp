#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie(const std::string &type, const std::string &name);
		~Zombie();
		void announce();
	private:
		const std::string &_type;
		const std::string &_name;
};

#endif
