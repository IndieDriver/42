#ifndef AVM_HPP
# define AVM_HPP
# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include <deque>

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
