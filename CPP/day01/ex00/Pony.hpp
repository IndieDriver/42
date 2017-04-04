#ifndef PONY_H
# define PONY_H
#include <string>
#include <iostream>

class Pony {
	public:
		Pony(std::string color, std::string tail_color);
		~Pony();
		std::string color;
		std::string tail_color;
		void description(void);
};

#endif
