#include <iostream>
#include "Pony.hpp"

void	ponyOnTheStack() {
	Pony 	ponyStack = Pony("green", "blue");

	ponyStack.description();
}

void	ponyOnTheHeap() {
	Pony	*ponyHeap = new Pony("white", "yellow");

	ponyHeap->description();
	delete ponyHeap;
}

int 	main(void) {
	ponyOnTheStack();
	ponyOnTheHeap();

	return (0);
}
