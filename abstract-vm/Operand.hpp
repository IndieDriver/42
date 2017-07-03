#ifndef OPERAND_HPP
# define OPERAND_HPP
# pragma once
# include "IOperand.hpp"
# include "Factory.hpp"
# include <iostream>
# include <sstream>
# include <limits>

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
		Operand(std::string const & value, eOperandType type) {
			double dvalue = std::stod(value);
			if (dvalue < std::numeric_limits<T>::min())
				throw UnderflowException();
			if (dvalue > std::numeric_limits<T>::max())
				throw OverflowException();
			this->_value = static_cast<T>(dvalue);
			this->_stringValue = value;
			this->_opType = type;
		}

		virtual ~Operand(void) {

		}

		int getPrecision(void) const {
			return (static_cast<int>(this->_opType));
		}

		eOperandType getType(void) const {
			return (this->_opType);
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
	eOperandType newType = op1.getPrecision() >= op2.getPrecision() ?
		op1.getType() : op2.getType();
	double op1Value = std::stod(op1.toString());
	double op2Value = std::stod(op2.toString());
	double res = op1Value + op2Value;
	ss << std::fixed << res;
	return (Factory::getInstance().createOperand(newType, ss.str()));
}

static inline IOperand const * sub(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	eOperandType newType = op1.getPrecision() >= op2.getPrecision() ?
		op1.getType() : op2.getType();
	double op1Value = std::stod(op1.toString());
	double op2Value = std::stod(op2.toString());
	double res = op1Value - op2Value;
	ss << std::fixed << res;
	return (Factory::getInstance().createOperand(newType, ss.str()));
}

static inline IOperand const * mul(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	eOperandType newType = op1.getPrecision() >= op2.getPrecision() ?
		op1.getType() : op2.getType();
	double op1Value = std::stod(op1.toString());
	double op2Value = std::stod(op2.toString());
	double res = op1Value * op2Value;
	ss << std::fixed << res;
	return (Factory::getInstance().createOperand(newType, ss.str()));
}

static inline IOperand const * div(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	eOperandType newType = op1.getPrecision() >= op2.getPrecision() ?
		op1.getType() : op2.getType();
	double op1Value = std::stod(op1.toString());
	double op2Value = std::stod(op2.toString());
	double res = op1Value / op2Value;
	ss << std::fixed << res;
	return (Factory::getInstance().createOperand(newType, ss.str()));
}

static inline IOperand const * mod(IOperand const & op1, IOperand const & op2) {
	std::ostringstream ss;
	eOperandType newType = op1.getPrecision() >= op2.getPrecision() ?
		op1.getType() : op2.getType();
	int op1Value = std::stod(op1.toString());
	int op2Value = std::stod(op2.toString());
	int res = op1Value % op2Value;
	ss << std::fixed << res;
	return (Factory::getInstance().createOperand(newType, ss.str()));
}
#endif
