#include "avm.hpp"
#include "Factory.hpp"

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	Factory factory;
	factory.createOperand(eOperandType::Int8, "42");
}
