#include "Contact.hpp"

Contact::Contact(void) {
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_login = "";
	_postal_address = "";
	_email_address = "";
	_phone_number = "";
	_birthday = "";
	_favorite_meal = "";
	_underwear_color = "";
	_darkest_secret = "";
}

void Contact::prompt(int i) {
	index = i;
	std::cout << "First name: ";
 	std::cin >> _first_name;
	std::cout << "Last name: ";
 	std::cin >> _last_name;
	std::cout << "Nickname: ";
 	std::cin >> _nickname;
	std::cout << "Login: ";
 	std::cin >> _login;
	std::cout << "Postal address: ";
 	std::cin >> _postal_address;
	std::cout << "Email address: ";
 	std::cin >> _email_address;
	std::cout << "Phone number: ";
 	std::cin >> _phone_number;
	std::cout << "Birthday: ";
 	std::cin >> _birthday;
	std::cout << "Favorite meal: ";
 	std::cin >> _favorite_meal;
	std::cout << "Underwear color: ";
 	std::cin >> _underwear_color;
	std::cout << "Darkest secret: ";
 	std::cin >> _darkest_secret;
}

bool	Contact::is_empty(){
	if (_first_name.empty() && _last_name.empty() && _nickname.empty() &&
		_login.empty() && _postal_address.empty() && _email_address.empty() &&
		_phone_number.empty() && _birthday.empty() && _favorite_meal.empty() &&
		_underwear_color.empty() && _darkest_secret.empty())
		return (true);
	return (false);
}

void Contact::display(){
	if (!this->is_empty()){
		std::stringstream ss;
		ss << index;
		std::cout << "|" + formatString(ss.str());
		std::cout << "|" + formatString(this->_first_name);
		std::cout << "|" + formatString(this->_last_name);
		std::cout << "|" + formatString(this->_nickname) + "|" << std::endl;
	}
}

void Contact::display_full(){
	std::cout << "First name: " + _first_name << std::endl;
	std::cout << "Last name: " + _last_name << std::endl;
	std::cout << "Nickname: " + _nickname << std::endl;
	std::cout << "Login: " + _login << std::endl;
	std::cout << "Postal address: " + _postal_address << std::endl;
	std::cout << "Email address: " + _email_address << std::endl;
	std::cout << "Phone number: " + _phone_number << std::endl;
	std::cout << "Birthday: " + _birthday << std::endl;
	std::cout << "Favorite meal" + _favorite_meal << std::endl;
	std::cout << "Underwear color: " + _underwear_color << std::endl;
	std::cout << "Darkest secret: " + _darkest_secret << std::endl;
}

Contact::~Contact(void){

}

std::string formatString(std::string field){
	if (field.length() > 9) {
		field = field.substr(0, 10);
		field[9] = '.';
	} else {
		field.insert(0, 10 - field.length(), ' ');
	}
	return (field);
}
