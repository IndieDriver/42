#include "Lexer.hpp"

Lexer::Lexer(void) {

}


Lexer::Lexer (std::string const &str) : _string(str), _offset(0) {

}

Lexer::Lexer(Lexer const & src) {
	*this = src;
}

Lexer::~Lexer(void) {

}

Lexer &	Lexer::operator=(Lexer const & rhs) {
	if (this != &rhs){
		this->_offset = rhs._offset;
	}
	return (*this);
}

bool Lexer::nextToken() {
	size_t begin = _string.find_first_of(_keyword, _offset);
	if (std::string::npos != begin && begin == _offset) {
		_token = _string.substr(begin, 1);
		_offset = begin + 1;
		return true;
	}
    begin = _string.find_first_not_of(_delimiters, _offset);
    if (std::string::npos == begin) {
        _offset = _string.length();
        return false;
    }
    size_t end = _string.find_first_of(_delimiters, begin);
    if (std::string::npos == end) {
        _token = _string.substr(begin);
        _offset = _string.length();
        return true;
    }
   	_token = _string.substr(begin, end - begin);
    _offset = end;
    return true;
}

std::string Lexer::getToken() {
	return (this->_token);
}
