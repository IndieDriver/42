#include "Instruction.hpp"

Instruction::Instruction(void) {

}

Instruction::Instruction (eInstruction instruction, const IOperand *operand)
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
	switch(this->_instruction) {
		case eInstruction::Push : push(); break;
		case eInstruction::Pop : pop(); break;
		case eInstruction::Dump : dump(); break;
		case eInstruction::Assert : assert(); break;
		case eInstruction::Add : add(); break;
		case eInstruction::Sub : sub(); break;
		case eInstruction::Mul : mul(); break;
		case eInstruction::Div : div(); break;
		case eInstruction::Mod : mod(); break;
		case eInstruction::Print : print(); break;
		case eInstruction::Exit : exit(); break;
		case eInstruction::Null : std::cout << "null" << std::endl; break;
	}
}

eInstruction Instruction::getInstruction() {
	return (this->_instruction);
}

void Instruction::push() {
	if (this->_operand == nullptr) {
		std::cout << "invalid operand in push" << std::endl;
	}
	Memory::getInstance().g_stack.push_front(this->_operand);
}

void Instruction::pop() {
	Memory::getInstance().g_stack.pop_front();
}

void Instruction::dump() {
	std::cout << "dump size: " << Memory::getInstance().g_stack.size() << std::endl;
	for (const auto & elem : Memory::getInstance().g_stack) {
		std::cout << elem->toString() << std::endl;
	}
}

void Instruction::assert() {
	if (this->_operand == nullptr) {
		std::cout << "invalid operand in assert" << std::endl;
	}
	const IOperand *topStack = Memory::getInstance().g_stack.front();
	if (this->_operand->toString() != topStack->_operand->toString()) {
		std::cout << "assert failed" << std::endl;
	}
}

void Instruction::add() {

}

void Instruction::sub() {

}

void Instruction::mul() {

}

void Instruction::div() {

}

void Instruction::mod() {

}

void Instruction::print() {

}

void Instruction::exit() {

}
