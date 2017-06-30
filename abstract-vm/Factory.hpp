#ifndef FACTORY_HPP
# define FACTORY_HPP

#include "IOperand.hpp"

class IOperand;

class Factory {
	public:
		static Factory& getInstance() {
            static Factory instance;
            return (instance);
        }
		Factory(Factory const&) = delete;
        void operator=(Factory const&) = delete;
		IOperand const * createOperand(eOperandType type, std::string const & value) const;
	private:
		Factory(void) {};
		IOperand const * createInt8(std::string const & value) const;
		IOperand const * createInt16(std::string const & value) const;
		IOperand const * createInt32(std::string const & value) const;
		IOperand const * createFloat(std::string const & value) const;
		IOperand const * createDouble(std::string const & value) const;
		typedef IOperand const * (Factory::*fn)(std::string const & value) const;
		fn _operands[5] {
			&Factory::createInt8,
			&Factory::createInt16,
			&Factory::createInt32,
			&Factory::createFloat,
			&Factory::createDouble
		};
};

#endif
