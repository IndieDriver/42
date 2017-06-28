#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP
# include "Operand.hpp"
# include <iostream>

enum eInstruction {
	Push,
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Print,
	Exit
};

class Instruction {
	public:
		Instruction (eInstruction instruction, IOperand *operand = nullptr);
		virtual ~Instruction (void);
		Instruction  & operator=(Instruction  const & rhs);

		void exec();
	private:
		Instruction (void);
		Instruction (Instruction  const & src);
		eInstruction	_instruction;
		IOperand		*_operand = nullptr;

};

#endif
