#include <iostream>
#include <string>

int		main(){
	std::string str = "HI THIS IS BRAIN";
	std::string *strptr = &str;
	std::string &strref = str;

	std::cout << *strptr << std::endl;
	std::cout << strref << std::endl;
	return (1);
}
