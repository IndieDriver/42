#include "Phonebook.hpp"

Phonebook::Phonebook(void){
	_nb_contact = 0;
}

Phonebook::~Phonebook(void){

}

void Phonebook::add(void){
	if (_nb_contact < 8){
		_contacts[_nb_contact].prompt(_nb_contact);
		_nb_contact++;
	} else {
		std::cout << "No free slots remaining";
	}
}

void Phonebook::search(void){
	std::cout << "|" + formatString("index");
	std::cout << "|" + formatString("firstname");
	std::cout << "|" + formatString("lastname");
	std::cout << "|" + formatString("nickname") + "|" << std::endl;
	for (int i = 0; i < 8; i++){
		_contacts[i].display();
	}
	std::string buffer;
	std::cout << "id: ";
	std::cin >> buffer;

	int	selected_index;
	std::stringstream ss(buffer);
	ss >> selected_index;
	if (selected_index >= 0 && selected_index < 8){
		_contacts[selected_index].display_full();
	} else {
		std::cout << "Invalid index" << std::endl;
	}

}

