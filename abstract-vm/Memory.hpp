#ifndef MEMORY_HPP
# define MEMORY_HPP
# include <deque>
# include "Operand.hpp"

class Memory {
	public:
		static Memory& getInstance() {
            static Memory instance;
            return (instance);
        }
		std::deque<const IOperand*>	g_stack;
		Memory(Memory const&) = delete;
        void operator=(Memory const&) = delete;
		void clean() {
			for (auto & op : g_stack) {
				delete op;
			}
			g_stack.clear();
		}
	private:
		Memory(void) {};
};

#endif
