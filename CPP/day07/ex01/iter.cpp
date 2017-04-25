#include <iostream>

template< typename T , typename U >
void iter(T * arr, int arraySize, U func) {
	for (int i = 0; i < arraySize; i++) {
		func(arr[i]);
	}
}

template< typename T >
void print_element(T element) {
	std::cout << element << std::endl;
}

void	double_int(int & value) {
	value *= 2;
}

void	double_float(float & value) {
	value *= 2;
}

int main () {
	int *intArray = new int[4];
	intArray[0] = 0;
	intArray[1] = 1;
	intArray[2] = 2;
	intArray[3] = 3;
	iter<int>(intArray, 4, *double_int);
	iter<int>(intArray, 4, *print_element<int>);

	float *floatArray = new float[4];
	floatArray[0] = 0.25f;
	floatArray[1] = 1.25f;
	floatArray[2] = 2.25f;
	floatArray[3] = 3.25f;
	iter<float>(floatArray, 4, *double_float);
	iter<float>(floatArray, 4, *print_element<float>);
	return (1);
}
