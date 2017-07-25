#ifndef AVM_HPP
# define AVM_HPP
# define COL_RES "\e[39m"
# define COL_RED "\e[31m"
# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include <deque>
# include "Exceptions.hpp"

enum eOperandType {
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

const std::string operandStr[] {
	"int8",
	"int16",
	"int32",
	"float",
	"double"
};

#endif
