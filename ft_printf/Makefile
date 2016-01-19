# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 13:12:05 by amathias          #+#    #+#              #
#    Updated: 2016/01/19 10:38:46 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC_NAME =  ft_printf.c		\
			utils.c			\

OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = libftprintf.a
CC = gcc
AR = ar rc
RAN = ranlib
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./lib/
LIB_NAME = -lft
LIB = $(addprefix -L,$(LIB_PATH))
LFLAGS = $(LIB) $(LIB_NAME)

INC_PATH = ./includes/
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ_NAME)
	$(AR) $(NAME) $(LFAGS) $(OBJ_NAME)
	$(RAN) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	$(RM) $(OBJ_NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all
