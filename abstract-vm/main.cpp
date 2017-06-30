#include "avm.hpp"
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
	if (ac == 2) {
		std::string fileContent = readFile(av[1]);
		std::vector<std::string> tokens;
		Lexer lexer(fileContent);
		while (lexer.nextToken()) {
			tokens.push_back(lexer.getToken());
		}
		std::vector<Instruction*> instructions;
		Parser parser(tokens);
		while (parser.nextInstruction()) {
			instructions.push_back(parser.getInstruction());
		}
		for (auto & instr : instructions) {
			instr->exec();
		}
	}
}
