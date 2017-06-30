#include "Parser.hpp"

Parser::Parser(void) {

}


Parser::Parser (std::vector<std::string> tokens) : _tokens(tokens), _offset(0) {

}

Parser::Parser(Parser const & src) {
	*this = src;
}

Parser::~Parser(void) {

}

Parser &	Parser::operator=(Parser const & rhs) {
	if (this != &rhs){
		this->_offset = rhs._offset;
	}
	return (*this);
}

eInstruction Parser::readInstruction() {
	eInstruction instruction = eInstruction::Null;
	while (_offset < _tokens.size() && _tokens.at(_offset).compare("\n") == 0) {
		_offset++;
	}
	if (_offset >= _tokens.size()) {
		return (instruction);
	}
	std::string instr = _tokens.at(_offset);
	for (int i = 0; i < 11; i++) {
		if (!instr.compare(instructionStr[i])) {
			std::cout << "instruction: " << instructionStr[i] << std::endl;
			instruction = static_cast<eInstruction>(i);
		}
	}
	_offset++;
	if (instruction == eInstruction::Null) {
		std::cout << "instruction " << instr << " not found" << std::endl;
		//error wrong instruction
	}
	return (instruction);
}

IOperand const *Parser::readOperand() {
	IOperand *operand = nullptr;
	if (_offset + 3 < _tokens.size()){
		std::string op = _tokens.at(_offset);
		std::string open_parentheis = _tokens.at(_offset + 1);
		std::string value = _tokens.at(_offset + 2);
		std::string close_parentheis = _tokens.at(_offset + 3);

		std::cout << "type " << op << std::endl;
		std::cout << "value " << value << std::endl;
		_offset += 4;

		for (int i = 0; i < 5; i++) {
			if (!op.compare(operandStr[i])) {
				std::cout << "operand: " << operandStr[i] << std::endl;
				if (open_parentheis.compare("(")) {
					std::cout << "error missing open" << std::endl;
				}
				if (close_parentheis.compare(")")) {
					std::cout << "error missing close" << std::endl;
				}
				IOperand const *operand = Factory::getInstance().createOperand(static_cast<eOperandType>(i), value);
				return (operand);
			}
		}
	}
	if (operand == nullptr) {
		std::cout << "invalid operand" << std::endl;
	}
	return (operand);
}

bool Parser::nextInstruction() {
	_instruction = nullptr;
	eInstruction instructionType = readInstruction();
	if (instructionType != eInstruction::Null
			&& (instructionType == eInstruction::Push || instructionType == eInstruction::Assert)) {
		const IOperand *operand = readOperand();
		_instruction = new Instruction(instructionType, operand);
		return (true);
	} else if (instructionType != eInstruction::Null){
		_instruction = new Instruction(instructionType, nullptr);
		return (true);
	}
	return (false);
}

Instruction *Parser::getInstruction() {
	return (_instruction);
}
