# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 11:09:29 by amathias          #+#    #+#              #
#    Updated: 2015/12/09 13:47:26 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC =	main.c			\
		ft_tetrimino.c	\
		ft_grid.c		\
		ft_solve.c		\
		ft_valid.c		\

OBJ = $(SRC:.c=.o)
NAME = fillit
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./lib/
LIB_NAME = -lft
LIB = $(addprefix -L,$(LIB_PATH))
LFLAGS = $(LIB) $(LIB_NAME)

INC_PATH = ./include/
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(INC) -o $@ -c $^ $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
