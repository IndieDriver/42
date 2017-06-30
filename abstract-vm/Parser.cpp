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

bool Parser::isComment() {
	if (_offset < _tokens.size()) {
		std::string token(_tokens.at(_offset));
		if (!token.empty() && token.size() > 0 && token[0] == ';') {
			return (true);
		}
	}
	return (false);
}

void Parser::discardComment() {
	while (_offset < _tokens.size() && _tokens.at(_offset).compare("\n") != 0) {
		_offset++;
	}
	/*
	if (_offset < _tokens.size() && _tokens.at(_offset).compare("\n") == 0) {

		isComment = false;
	} */
	while (_offset < _tokens.size() && _tokens.at(_offset).compare("\n") == 0) {
		_offset++;
	}
	if (isComment()) {
		discardComment();
	}
}

eInstruction Parser::readInstruction() {
	eInstruction instruction = eInstruction::Null;
	if (isComment())
		discardComment();
	while (_offset < _tokens.size() && _tokens.at(_offset).compare("\n") == 0) {
		_offset++;
	}
	if (isComment())
		discardComment();
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
	if (_offset + 4 < _tokens.size()){
		std::string op = _tokens.at(_offset);
		std::string open_parentheis = _tokens.at(_offset + 1);
		std::string value = _tokens.at(_offset + 2);
		std::string close_parentheis = _tokens.at(_offset + 3);

		_offset += 4;
		for (int i = 0; i < 5; i++) {
			if (!op.compare(operandStr[i])) {
				std::cout << "operand: " << operandStr[i] << std::endl;
				std::cout << "value " << value << std::endl;
				if (open_parentheis.compare("(")) {
					throw ParserException("missing opening brace");
				}
				if (close_parentheis.compare(")")) {
					throw ParserException("missing closing brace");
				}
				IOperand const *operand = Factory::getInstance().createOperand(static_cast<eOperandType>(i), value);
				return (operand);
			}
		}
	}
	if (operand == nullptr) {
		throw ParserException("unknown operand");
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
