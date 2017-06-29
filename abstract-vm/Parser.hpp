#ifndef PARSER_HPP
# define PARSER_HPP
# include <string>
# include <iostream>
# include <vector>
# include "Instruction.hpp"
# include "Factory.hpp"

class Parser {
	public:
		Parser (std::vector<std::string> tokens);
		virtual ~Parser (void);
		Parser  & operator=(Parser  const & rhs);

		bool				nextInstruction();
		Instruction			*getInstruction();

	private:
		Parser (void);
		Parser (Parser  const & src);
		const std::string	_string;
		std::vector <std::string>	_tokens;
		size_t						_offset;
		std::string					_token;
		eInstruction		readInstruction();
		IOperand const 		*readOperand();
		Instruction			*_instruction;
};

#endif
