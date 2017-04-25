#include <iostream>
#include <string>
#include <climits>

struct Data {
	std::string s1;
	int			n;
	std::string s2;
};

void	* serialize(void) {
	Data *data = new Data;
	data->s1 = "";
	for (int i = 0; i < 8; i++) {
		int rnd = rand() % 255;
		if (std::isalnum(rnd))
			data->s1 += static_cast<char>(rnd);
		else
			i--;
	}
	data->n = rand() % INT_MAX;
	data->s2 = "";
	for (int i = 0; i < 8; i++) {
		int rnd = rand() % 255;
		if (std::isalnum(rnd))
			data->s2 += static_cast<char>(rnd);
		else
			i--;
	}
	std::cout << "Serialize of:" << std::endl;
	std::cout << "s1: " + data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " + data->s2 << std::endl << std::endl;

	return (static_cast<void *>(data));
}

Data	*deserialize(void *raw) {
	return (static_cast<Data*>(raw));
}

int main(void) {
	srand(time(NULL));
	void	*raw_data = serialize();
	void	*raw_data2 = serialize();
	void	*raw_data3 = serialize();

	Data *data = deserialize(raw_data);
	std::cout << "##########" << std::endl;
	std::cout << "s1: " + data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " + data->s2 << std::endl;
	delete data;

	data = deserialize(raw_data2);
	std::cout << "##########" << std::endl;
	std::cout << "s1: " + data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " + data->s2 << std::endl;
	delete data;


	data = deserialize(raw_data3);
	std::cout << "##########" << std::endl;
	std::cout << "s1: " + data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " + data->s2 << std::endl;
	delete data;

	return (1);
}
