#include <iostream>
#include <fstream>
#include <string>

void 	replace(std::string const & filename, std::string const & s1, std::string const & s2) {
	std::ifstream ifs(filename);
	std::ofstream ofs(filename + ".replace");
	if (ifs.is_open() && ofs.is_open()){
		std::string line;
		while (getline(ifs, line)) {
			std::size_t found;
			while ((found = line.find(s1)) != std::string::npos) {
				line = line.replace(found, s1.length(), s2);
			}
			ofs << line << std::endl;
		}
		ifs.close();
		ofs.close();
	}
}

int		main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Invalid usage" << std::endl << "./replace <file> \"s1\" \"s2\"" << std::endl;
	} else {
		replace(std::string(av[1]), std::string(av[2]), std::string(av[3]));
	}
	return (1);
}
