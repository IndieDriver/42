#ifndef OPERAND_HPP
# define OPERAND_HPP
# pragma once
# include "IOperand.hpp"
# include "Factory.hpp"
# include <iostream>
# include <sstream>
# include <limits>


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
			std::ostringstream ss;
			eOperandType newType = this->getPrecision() >= rhs.getPrecision() ?
				this->getType() : rhs.getType();
			double op1Value = std::stod(this->toString());
			double op2Value = std::stod(rhs.toString());
			double res = op1Value + op2Value;
			ss << res;
			return (Factory::getInstance().createOperand(newType, ss.str()));
		}

		IOperand const * operator-(IOperand const & rhs) const {
			std::ostringstream ss;
			eOperandType newType = this->getPrecision() >= rhs.getPrecision() ?
				this->getType() : rhs.getType();
			double op1Value = std::stod(this->toString());
			double op2Value = std::stod(rhs.toString());
			double res = op1Value - op2Value;
			ss << res;
			return (Factory::getInstance().createOperand(newType, ss.str()));
		}

		IOperand const * operator*(IOperand const & rhs) const {
			std::ostringstream ss;
			eOperandType newType = this->getPrecision() >= rhs.getPrecision() ?
				this->getType() : rhs.getType();
			double op1Value = std::stod(this->toString());
			double op2Value = std::stod(rhs.toString());
			double res = op1Value * op2Value;
			ss << res;
			return (Factory::getInstance().createOperand(newType, ss.str()));
		}

		IOperand const * operator/(IOperand const & rhs) const  {
			std::ostringstream ss;
			eOperandType newType = this->getPrecision() >= rhs.getPrecision() ?
				this->getType() : rhs.getType();
			double op1Value = std::stod(this->toString());
			double op2Value = std::stod(rhs.toString());
			double res = op1Value / op2Value;
			ss << res;
			return (Factory::getInstance().createOperand(newType, ss.str()));
		}

		IOperand const * operator%(IOperand const & rhs) const {
			std::ostringstream ss;
			eOperandType newType = this->getPrecision() >= rhs.getPrecision() ?
				this->getType() : rhs.getType();
			int op1Value = std::stod(this->toString());
			int op2Value = std::stod(rhs.toString());
			int res = op1Value % op2Value;
			ss << res;
			return (Factory::getInstance().createOperand(newType, ss.str()));
		}

		std::string const & toString(void) const {
			return (this->_stringValue);
		}

	private:
		T				_value;
		std::string		_stringValue;
		eOperandType	_opType;
};

#endif
