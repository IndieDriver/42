#ifndef LEXER_HPP
# define LEXER_HPP
# include <string>
# include <iostream>

class Lexer {
	public:
		Lexer (std::string const &str);
		virtual ~Lexer (void);
		Lexer  & operator=(Lexer  const & rhs);

		bool 		nextToken();
		std::string	getToken();

	private:
		Lexer (void);
		Lexer (Lexer  const & src);
		const std::string	_string;
		size_t		_offset;
		std::string _token;
		const std::string _delimiters = " \t\r()\n";
		const std::string _keyword = "()\n";
};

#endif
