#include "Instruction.hpp"

Instruction::Instruction(void) {

}

Instruction::Instruction (eInstruction instruction, IOperand *operand)
	: _instruction(instruction),
		_operand(operand) {

}

Instruction::Instruction(Instruction const & src) {
	*this = src;
}

Instruction::~Instruction(void) {

}

Instruction &	Instruction::operator=(Instruction const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}

void Instruction::exec() {
	_operand = nullptr;
	switch(this->_instruction) {
		case eInstruction::Push : std::cout << "push" << std::endl; break;
		case eInstruction::Pop : std::cout << "pop" << std::endl; break;
		case eInstruction::Dump : std::cout << "dump" << std::endl; break;
		case eInstruction::Assert : std::cout << "assert" << std::endl; break;
		case eInstruction::Add : std::cout << "add" << std::endl; break;
		case eInstruction::Sub : std::cout << "sub" << std::endl; break;
		case eInstruction::Mul : std::cout << "mul" << std::endl; break;
		case eInstruction::Div : std::cout << "div" << std::endl; break;
		case eInstruction::Mod : std::cout << "mod" << std::endl; break;
		case eInstruction::Print : std::cout << "print" << std::endl; break;
		case eInstruction::Exit : std::cout << "exit" << std::endl; break;
	}
}
