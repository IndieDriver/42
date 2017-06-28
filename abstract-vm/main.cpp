#include "avm.hpp"
#include "Factory.hpp"
#include "Instruction.hpp"

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	Factory factory;
	factory.createOperand(eOperandType::Int8, "42");

	Instruction push(eInstruction::Push);
	Instruction pop(eInstruction::Pop);
	push.exec();
	pop.exec();
}
