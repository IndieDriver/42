
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include <iostream>
#include <sstream>
#include "Contact.hpp"

class Phonebook {
	public:
		Phonebook(void);
		~Phonebook(void);
		void add(void);
		void search(void);
		void exit(void);
	private:
		Contact _contacts[8];
		int		_nb_contact;
};

#endif
