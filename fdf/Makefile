# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 11:09:29 by amathias          #+#    #+#              #
#    Updated: 2016/02/10 13:18:41 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC =	main.c		\
		io.c		\
		isometric.c	\
		draw_line.c	\
		draw.c		\
		hook.c		\
		move.c		\

OBJ = $(SRC:.c=.o)
NAME = fdf
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libft/ /usr/local/lib/
LIB_NAME = -lft -lmlx -framework OpenGL -framework AppKit
LIB = $(addprefix -L,$(LIB_PATH))
LFLAGS = $(LIB) $(LIB_NAME)

INC_PATH = ./libft/ /usr/local/include/ /usr/X11/lib
INC = $(addprefix -I,$(INC_PATH))

all: lib $(NAME)

lib:
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(INC) -o $@ -c $^ $(CFLAGS)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all
