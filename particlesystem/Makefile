# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 11:09:29 by amathias          #+#    #+#              #
#    Updated: 2016/09/22 15:59:10 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c				\
		shader.cpp			\
OBJ = $(SRC:.c=.o)
NAME = particlesystem
CC = g++
RM = rm -f
CFLAGS = 

LIB_PATH = ./minilibx_macos/
LIB_NAME = -lmlx -framework OpenGL -framework AppKit
LIB = $(addprefix -L,$(LIB_PATH))
LFLAGS = $(LIB) $(LIB_NAME)

INC_PATH = ./minilibx_macos/
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $(LIB) $(CFLAGS) $(LFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(LIB) $(INC) -o $@ -c $^ $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
