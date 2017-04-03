/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:30:06 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 15:44:34 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

int		main(void) {
	Phonebook phonebook;
	std::string buffer;
	bool running;

	running = true;
	while (running){
		std::cout << "$ ";
		std::cin >> buffer;
		if (buffer == "EXIT")
			running = false;
		else if (buffer == "ADD")
			phonebook.add();
		else if (buffer == "SEARCH")
			phonebook.search();
	}
}
