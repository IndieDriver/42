# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 11:09:29 by amathias          #+#    #+#              #
#    Updated: 2016/03/28 13:35:07 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC =	main.c			\
		draw.c			\
		hook.c			\
		raytracer.c		\
		light.c			\
		shadow.c		\
		iter_shape.c	\
		iter_utils.c	\
		get_dist.c		\
		cylinder_dist.c	\
		cone_dist.c		\
		get_normal.c	\
		get_ray.c		\
		vec_utils.c		\
		color.c			\
		parser.c		\
		parse_scene.c	\
		parse_object.c	\
		parse_shape.c	\
		parser_utils.c	\
		parse_spot.c	\
		parser_init.c	\

OBJ = $(SRC:.c=.o)
NAME = rtv1
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libft/ /usr/local/lib/
LIB_NAME = -lft -lpthread -lmlx -framework OpenGL -framework AppKit
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
