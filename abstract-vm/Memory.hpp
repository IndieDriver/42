#ifndef MEMORY_HPP
# define MEMORY_HPP
# include <deque>
# include <list>
# include "Operand.hpp"

class Memory {
	public:
		static Memory& getInstance() {
            static Memory instance;
            return (instance);
        }
		std::list<const IOperand*>	g_stack;
		Memory(Memory const&) = delete;
        void operator=(Memory const&) = delete;
	private:
		Memory(void) {};
};

#endif
