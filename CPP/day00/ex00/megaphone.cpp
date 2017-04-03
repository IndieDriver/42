/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 10:12:07 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 11:28:35 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int		main(int ac, char **av){
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"  << std::endl;
	} else {
		for (int i = 1; i < ac; i++) {
			int j = 0;
			while (av[i][j]) {
				av[i][j] = toupper(av[i][j]);
				j++;
			}
			std::cout << av[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
