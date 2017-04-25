#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> intarray(3);
	intarray[0] = 0;
	intarray[1] = 1;
	intarray[2] = 2;

	Array<int> intarray2(5);
	intarray2[0] = 4;
	intarray2[1] = 3;
	intarray2[2] = 2;
	intarray2[3] = 1;
	intarray2[4] = 0;

	//Copy constructor
	std::cout << "### COPY CONSTRUCTOR ###" << std::endl;
	Array<int> intarray3(intarray);
	std::cout << intarray3[0] << std::endl;
	std::cout << intarray3[1] << std::endl;
	std::cout << intarray3[2] << std::endl;

	//Assignation
	std::cout << "### ASSIGNATION ###" << std::endl;
	intarray2 = intarray3;
	std::cout << intarray2[0] << std::endl;
	std::cout << intarray2[1] << std::endl;
	std::cout << intarray2[2] << std::endl;

	//Deep copy
	std::cout << "### TEST DEEP COPY ###" << std::endl;
	intarray3[0] = 42;
	std::cout << intarray3[0] << std::endl;
	std::cout << intarray2[0] << std::endl;
	intarray2[0] = 21;
	std::cout << intarray3[0] << std::endl;
	std::cout << intarray2[0] << std::endl;

	intarray[0] = 33;
	std::cout << intarray3[0] << std::endl;
	std::cout << intarray[0] << std::endl;


	std::cout << "### SIZE ###" << std::endl;
	std::cout << "size(): " << intarray.size() << std::endl;
	Array<int> intarray4(42);
	std::cout << "size(): " << intarray4.size() << std::endl;


	std::cout << "### OTHER TYPE ###" << std::endl;
	Array<float> floatarray(4);
	floatarray[0] = 0.5f;
	floatarray[1] = 1.5f;
	floatarray[2] = 2.5f;
	floatarray[3] = 3.5f;

	std::cout << floatarray[0]  << std::endl;
	std::cout << floatarray[1]  << std::endl;
	std::cout << floatarray[2]  << std::endl;
	std::cout << floatarray[3]  << std::endl;

	std::cout << "### EXCEPTION ###" << std::endl;
	try {
		floatarray[4] = 4.0f;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (1);
}
