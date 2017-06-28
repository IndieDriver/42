#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"

template <class T>
class Operand : public IOperand {
	public:
		//Operand(void);
		//Operand(Operand const & src);
		Operand(std::string const & value) {
			_value = value;
		}

		virtual ~Operand(void) {

		}

		//Operand & operator=(Operand const & rhs);

		int getPrecision(void) const {
			return (0);
		}

		eOperandType getType(void) const {
			return (eOperandType::Int8);
		}

		IOperand const * operator+(IOperand const & rhs) const {
			(void)rhs;
			return (this);
		}

		IOperand const * operator-(IOperand const & rhs) const {
			(void)rhs;
			return (this);
		}

		IOperand const * operator*(IOperand const & rhs) const {
			(void)rhs;
			return (this);
		}

		IOperand const * operator/(IOperand const & rhs) const  {
			(void)rhs;
			return (this);
		}

		IOperand const * operator%(IOperand const & rhs) const {
			(void)rhs;
			return (this);
		}

		std::string const & toString(void) const {
			return (_value);
		}
	private:
		std::string		_value;
		eOperandType	_opType;
};

#endif
