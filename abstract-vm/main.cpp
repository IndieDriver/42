#include "avm.hpp"
#include "Factory.hpp"
#include "Instruction.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"

std::string readFile(std::string filename) {
    std::string line;
    std::ifstream file(filename);
    std::string buffer = "";

    if (file){
        while (getline(file, line))
            buffer += line + "\n";
        file.close();
    }
	return (buffer);
}

int main(int ac, char **av) {
	/*
	Factory factory;
	factory.createOperand(eOperandType::Int8, "42");

	Instruction push(eInstruction::Push);
	Instruction pop(eInstruction::Pop);
	push.exec();
	pop.exec(); */
	if (ac == 2) {
		std::string fileContent = readFile(av[1]);
		//std::cout << fileContent << std::endl;
		std::vector<std::string> tokens;
		Lexer lexer(fileContent);
		while (lexer.nextToken()) {
			std::cout << lexer.getToken() << std::endl;
			tokens.push_back(lexer.getToken());
		}
		Parser parser(tokens);
		while (parser.nextInstruction() != nullptr) {

		}
	}
}
