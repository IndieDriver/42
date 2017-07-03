#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP
# include <exception>
# include <string>

class ParserException : public std::exception {
	public:
		ParserException(const std::string& message)
			: _message(message) {

		}

        virtual const char* what() const throw () {
            return _message.c_str();
        }

        virtual ~ParserException() throw (){}
    private:
        std::string         _message;

};

class DivisionByZeroException : public std::exception {
	public:
  		virtual const char* what() const throw() {
    		return "Division by zero";
  		}
};

class ModuloByZeroException : public std::exception {
	public:
  		virtual const char* what() const throw() {
    		return "Division by zero";
  		}
};

class OverflowException : public std::exception {
	public:
  		virtual const char* what() const throw() {
    		return "Overflow";
  		}
};

class UnderflowException : public std::exception {
	public:
  		virtual const char* what() const throw() {
    		return "Underflow";
  		}
};

class AssertNotTrue : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Assert not true";
		}
};

class NotEnoughOperands : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Not enough operand on the stack";
		}
};

class PopOnEmptyStack : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "pop instruction on empty stack";
		}
};

class NotPrintableOperand : public std::exception {
	public:
		virtual const char * what() const throw() {
			return "Can't print operand other than int8";
		}
};

class MissingExitInstruction : public std::exception {
	public:
		virtual const char * what() const throw() {
			return "Missing exit instruction";
		}
};
#endif
