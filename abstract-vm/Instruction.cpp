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
	if (Memory::getInstance().g_stack.empty())
		throw PopOnEmptyStack();
	Memory::getInstance().g_stack.pop_front();
}

void Instruction::dump() {
	std::cout << "DUMP START:" << std::endl;
	for (const auto & elem : Memory::getInstance().g_stack) {
		//std::cout.precision(elem->getPrecision() + 1);
		std::cout << std::fixed << elem->toString() << std::endl;
	}
	std::cout << "DUMP END" << std::endl;
}

void Instruction::assert() {
	if (this->_operand == nullptr) {
		std::cout << "invalid operand in assert" << std::endl;
	}
	const IOperand *topStack = Memory::getInstance().g_stack.front();
	if (this->_operand->toString() != topStack->toString()) {
		throw AssertNotTrue();
	}
}

void Instruction::add() {
	if (Memory::getInstance().g_stack.size() < 2) {
		throw NotEnoughOperands();
	}
	IOperand const *v1 = Memory::getInstance().g_stack.front();
	pop();
	IOperand const *v2 = Memory::getInstance().g_stack.front();
	pop();
	Memory::getInstance().g_stack.push_front(*v2 + *v1);
}

void Instruction::sub() {
	if (Memory::getInstance().g_stack.size() < 2) {
		throw NotEnoughOperands();
	}
	const IOperand *v1 = Memory::getInstance().g_stack.front();
	pop();
	const IOperand *v2 = Memory::getInstance().g_stack.front();
	pop();
	Memory::getInstance().g_stack.push_front(*v2 - *v1);
}

void Instruction::mul() {
	if (Memory::getInstance().g_stack.size() < 2) {
		throw NotEnoughOperands();
	}
	const IOperand *v1 = Memory::getInstance().g_stack.front();
	pop();
	const IOperand *v2 = Memory::getInstance().g_stack.front();
	pop();
	Memory::getInstance().g_stack.push_front(*v2 * *v1);
}

void Instruction::div() {
	if (Memory::getInstance().g_stack.size() < 2) {
		throw NotEnoughOperands();
	}
	const IOperand *v1 = Memory::getInstance().g_stack.front();
	pop();
	const IOperand *v2 = Memory::getInstance().g_stack.front();
	pop();
	if (std::stoi(v1->toString()) == 0) {
		throw DivisionByZeroException();
	}
	Memory::getInstance().g_stack.push_front(*v2 / *v1);
}

void Instruction::mod() {
	if (Memory::getInstance().g_stack.size() < 2) {
		throw NotEnoughOperands();
	}
	const IOperand *v1 = Memory::getInstance().g_stack.front();
	pop();
	const IOperand *v2 = Memory::getInstance().g_stack.front();
	pop();
	if (std::stoi(v1->toString()) == 0) {
		throw ModuloByZeroException();
	}
	Memory::getInstance().g_stack.push_front(*v2 + *v1);
}

void Instruction::print() {
	if (Memory::getInstance().g_stack.size() < 1) {
		throw NotEnoughOperands();
	}
	const IOperand *v1 = Memory::getInstance().g_stack.front();
	if (v1->getType() == eOperandType::Int8) {
		std::cout << static_cast<char>(std::stoi(v1->toString())) << std::endl;
	} else {
		throw NotPrintableOperand();
	}
}

void Instruction::exit() {

}
