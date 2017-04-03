# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 11:09:29 by amathias          #+#    #+#              #
#    Updated: 2017/04/03 16:07:07 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC =	tests.cpp			\
		Account.class.cpp	\


OBJ = $(SRC:.cpp=.o)
NAME = tests
CC = g++
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
