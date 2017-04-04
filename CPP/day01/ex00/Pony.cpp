#include "Pony.hpp"

Pony::Pony(std::string col, std::string tail_col) : color(col), tail_color(tail_col){
	std::cout << color + " pony is born" << std::endl;
}

Pony::~Pony(){
	std::cout << color + " pony died" << std::endl;
}

void Pony::description() {
	std::cout << "I'm a " + color + " pony with a " + tail_color + " tail" << std::endl;
}
