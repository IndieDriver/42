#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <sstream>

class Contact {
	public:
		Contact();
		~Contact();
		void prompt(int index);
		void display();
		void display_full();
	private:
		int	index;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _login;
		std::string _postal_address;
		std::string _email_address;
		std::string _phone_number;
		std::string _birthday;
		std::string _favorite_meal;
		std::string _underwear_color;
		std::string _darkest_secret;
		bool is_empty();
};

std::string formatString(std::string field);

#endif
