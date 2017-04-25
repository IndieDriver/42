#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# include <iostream>

template < typename T >
class Array {
	public:
		Array(void) : _size(0), _arr(NULL) {

		}

		Array(unsigned int n) : _size(n) {
			this->_arr = new T[this->_size]();
		}

		Array(Array const & src) : _size(0) {
			*this = src;
		}

		Array &	operator=(Array const & rhs) {
			if (this != &rhs){
				if (this->_size != 0) {
						delete this->_arr;
				}
				if (rhs._size != 0) {
					this->_arr = new T[rhs._size]();
					this->_size = rhs._size;
					for (unsigned int i = 0; i < this->_size; i++) {
						this->_arr[i] = rhs._arr[i];
					}
				}
			}
			return (*this);
		}

		T & operator[](int index) {
			if (static_cast<unsigned int>(index) >= this->_size)
				throw std::exception();
			return _arr[index];
		}

		virtual ~Array(void) {
			if (this->_size > 0)
				delete [] this->_arr;
		}

		unsigned int size() const {
			return (this->_size);
		}

	private:
		T				*_arr;
		unsigned int	_size;
};

#endif
