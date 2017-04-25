#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {
	Base *base = NULL;
	int rnd = rand() % 3;
	std::cout << "generating ";
	if (rnd == 0) {
		std::cout << "A";
		base = new A();
	}
	else if (rnd == 1) {
		std::cout << "B";
		base = new B();
	}
	else if (rnd == 2) {
		std::cout << "C";
		base = new C();
	}
	std::cout << std::endl;
	return (base);
}

void	identify_from_pointer(Base *p) {
	A *a = dynamic_cast<A*>(p);
	if (a != NULL) {
		std::cout << "A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B*>(p);
	if (b != NULL) {
		std::cout << "B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*>(p);
	if (c != NULL) {
		std::cout << "C" << std::endl;
		return ;
	}
}


void	identify_from_reference(Base & p) {
	Base *ptr = &p;
	A *a = dynamic_cast<A*>(ptr);
	if (a != NULL) {
		std::cout << "A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B*>(ptr);
	if (b != NULL) {
		std::cout << "B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*>(ptr);
	if (c != NULL) {
		std::cout << "C" << std::endl;
		return ;
	}
}

int		main(void) {
	srand(time(NULL));

	Base *base = generate();
	std::cout << "identify from pointer: ";
	identify_from_pointer(base);
	std::cout << "identify from reference: ";
	identify_from_reference(*base);
	delete base;
}
