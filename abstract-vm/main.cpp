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

std::vector<std::string> tokenize(std::string content) {
	std::vector<std::string> tokens;

	Lexer lexer(content);
	while (lexer.nextToken()) {
		tokens.push_back(lexer.getToken());

	}
	return (tokens);
}

std::vector<Instruction*>
	parse(std::vector<std::string> tokens, bool hasExit){
	std::vector<Instruction*> instructions;
	Parser parser(tokens);
	while (parser.nextInstruction()) {
		instructions.push_back(parser.getInstruction());
		if (parser.getInstruction()->getInstruction()
				== eInstruction::Exit) {
			hasExit = true;
		}
	}
	if (!hasExit) {
		throw MissingExitInstruction();
	}
	return (instructions);
}

void run(std::string content, bool shouldStopOnExit) {
	std::vector<std::string> tokens;
	std::vector<Instruction*> instructions;

	tokens = tokenize(content);
	try {
		instructions = parse(tokens, !shouldStopOnExit);
	} catch (std::exception &e) {
		std::cout << "[Parsing Exception] " << e.what()
			<< std::endl;
	}
	try {
		for (auto & instr : instructions) {
			instr->exec();
		}
	} catch (std::exception &e) {
		std::cout << "[Exception] " << e.what() << std::endl;
	}
}

int main(int ac, char **av) {
	if (ac > 1) {
		run (readFile(av[1]), true);
	} else {
		for (std::string line; std::getline(std::cin, line);) {
			if (line.compare(";;") == 0)
				break ;
			run(line, false);
    	}
	}
}
