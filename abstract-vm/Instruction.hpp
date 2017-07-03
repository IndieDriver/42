#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP
# include "avm.hpp"
# include "Operand.hpp"
# include "Memory.hpp"
# include "Exceptions.hpp"

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
	Exit,
	Null
};

/* Should always follow eInstruction enum */
const std::string instructionStr[] {
	"push",
	"pop",
	"dump",
	"assert",
	"add",
	"sub",
	"mul",
	"div",
	"mod",
	"print",
	"exit"
};

class Instruction {
	public:
		Instruction (eInstruction instruction, const IOperand *operand);
		virtual ~Instruction (void);
		Instruction  & operator=(Instruction  const & rhs);

		void			exec();
		eInstruction	getInstruction();
		const IOperand *getOperand();
	private:
		Instruction (void);
		Instruction (Instruction  const & src);
		eInstruction	_instruction;
		const IOperand	*_operand;
		void push();
		void pop();
		void dump();
		void assert();
		void add();
		void sub();
		void mul();
		void div();
		void mod();
		void print();
		void exit();
		void null();
};


#endif
