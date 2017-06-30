#ifndef OPERAND_HPP
# define OPERAND_HPP
# pragma once

#include "IOperand.hpp"
#include "Factory.hpp"
#include <iostream>
#include <sstream>

static inline IOperand const * add(IOperand const & op1, IOperand const & op2);
static inline IOperand const * sub(IOperand const & op1, IOperand const & op2);
static inline IOperand const * mul(IOperand const & op1, IOperand const & op2);
static inline IOperand const * div(IOperand const & op1, IOperand const & op2);
static inline IOperand const * mod(IOperand const & op1, IOperand const & op2);

template <class T>
class Operand : public IOperand {
	public:
		//Operand(void);
		Operand(Operand const & src) {
			*this = src;
		}
		Operand(std::string const & value) {
			this->_value = std::stoi(value);
			_stringValue = value;

		}

		virtual ~Operand(void) {

		}

		int getPrecision(void) const {
			return (static_cast<int>(_opType));
		}

		eOperandType getType(void) const {
			return (eOperandType::Int8);
		}

		IOperand const * operator+(IOperand const & rhs) const {
			return (add(*this, rhs));
		}

		IOperand const * operator-(IOperand const & rhs) const {
			return (sub(*this, rhs));
		}

		IOperand const * operator*(IOperand const & rhs) const {
			return (mul(*this, rhs));
		}

		IOperand const * operator/(IOperand const & rhs) const  {
			return (div(*this, rhs));
		}

		IOperand const * operator%(IOperand const & rhs) const {
			return (mod(*this, rhs));
		}

		std::string const & toString(void) const {
			return (this->_stringValue);
		}
	private:
		T				_value;
		std::string		_stringValue;
		eOperandType	_opType;
};

static inline IOperand const * add(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	double op1Value = std::stoi(op1.toString());
	double op2Value = std::stoi(op2.toString());
	double res = op1Value + op2Value;
	ss << res;
	return (Factory::getInstance().createOperand(eOperandType::Int8, ss.str()));
}

static inline IOperand const * sub(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	double op1Value = std::stoi(op1.toString());
	double op2Value = std::stoi(op2.toString());
	double res = op1Value - op2Value;
	ss << res;
	return (Factory::getInstance().createOperand(eOperandType::Int8, ss.str()));
}

static inline IOperand const * mul(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	double op1Value = std::stoi(op1.toString());
	double op2Value = std::stoi(op2.toString());
	double res = op1Value * op2Value;
	ss << res;
	return (Factory::getInstance().createOperand(eOperandType::Int8, ss.str()));
}

static inline IOperand const * div(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	double op1Value = std::stoi(op1.toString());
	double op2Value = std::stoi(op2.toString());
	double res = op1Value / op2Value;
	ss << res;
	return (Factory::getInstance().createOperand(eOperandType::Int8, ss.str()));
}

static inline IOperand const * mod(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	int op1Value = std::stoi(op1.toString());
	int op2Value = std::stoi(op2.toString());
	int res = op1Value % op2Value;
	ss << res;
	return (Factory::getInstance().createOperand(eOperandType::Int8, ss.str()));
}
#endif
