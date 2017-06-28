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

Instruction *Parser::readInstruction() {
	Instruction *instruction = nullptr;
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
			instruction = new Instruction(static_cast<eInstruction>(i));
		}
	}
	_offset++;
	if (instruction == nullptr) {
		std::cout << "instruction " << instr << " not found" << std::endl;
		//error wrong instruction
	}
	return (instruction);
}

IOperand const *Parser::readOperand() {
	IOperand *operand = nullptr;
	std::string op = _tokens.at(_offset);
	for (int i = 0; i < 5; i++) {
		if (!op.compare(operandStr[i])) {
			std::cout << "operand: " << operandStr[i] << std::endl;
			_offset++;
			if (_offset < _tokens.size()) {
				std::string value = _tokens.at(_offset);
				Factory factory;
				IOperand const *operand = factory.createOperand(static_cast<eOperandType>(i), value);
				return (operand);
				_offset++;

			}
		}
	}


	return (operand);
}


Instruction * Parser::nextInstruction() {
	Instruction * instruction = readInstruction();
	if (instruction != nullptr
			&& (instruction->getInstruction() == eInstruction::Push
				|| instruction->getInstruction() == eInstruction::Assert)) {
		instruction->setOperand(readOperand());
	}
	return (readInstruction());
}



/*
bool Parser::nextToken() {
	size_t begin = _string.find_first_of(_keyword, _offset);
	if (std::string::npos != begin && begin == _offset) {
		_token = _string.substr(begin, 1);
		_offset = begin + 1;
		return true;
	}
    begin = _string.find_first_not_of(_delimiters, _offset);
    if (std::string::npos == begin) {
        _offset = _string.length();
        return false;
    }
    size_t end = _string.find_first_of(_delimiters, begin);
    if (std::string::npos == end) {
        _token = _string.substr(begin);
        _offset = _string.length();
        return true;
    }
   	_token = _string.substr(begin, end - begin);
    _offset = end;
    return true;
} */
