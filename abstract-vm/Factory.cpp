#include "Factory.hpp"
#include "Operand.hpp"

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const {
	int index = static_cast<int>(type);
	return ((this->*(_operands[index]))(value));
}

IOperand const * Factory::createInt8(std::string const & value) const {
	IOperand *operand = new Operand<int8_t>(value, eOperandType::Int8);
	return (operand);
}

IOperand const * Factory::createInt16(std::string const & value) const {
	IOperand *operand = new Operand<int16_t>(value, eOperandType::Int16);
	return (operand);
}

IOperand const * Factory::createInt32(std::string const & value) const {
	IOperand *operand = new Operand<int32_t>(value, eOperandType::Int32);
	return (operand);
}

IOperand const * Factory::createFloat(std::string const & value) const {
	IOperand *operand = new Operand<float>(value, eOperandType::Float);
	return (operand);
}

IOperand const * Factory::createDouble(std::string const & value) const {
	IOperand *operand = new Operand<double>(value, eOperandType::Double);
	return (operand);
}
