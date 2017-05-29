# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:24:02 by amathias          #+#    #+#              #
#    Updated: 2017/03/11 09:38:27 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC_NAME =  free.c              \
            malloc.c		    \
			realloc.c			\
			show_alloc_mem.c	\
            utils.c				\

OBJ_NAME = $(SRC_NAME:.c=.o)

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME = libft_malloc_$(HOSTTYPE).so
CC = gcc
AR = ar rc
RAN = ranlib
RM = rm -f
#CFLAGS = -Wall -Werror -Wextra -fPIC
CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libft/
LIB_NAME = -lft
LIB = $(addprefix -L,$(LIB_PATH))
LFLAGS = $(LIB) $(LIB_NAME)

INC_PATH = ./libft/
INC = $(addprefix -I,$(INC_PATH))

all: lib $(NAME)

lib:
	make -C ./libft

$(NAME): $(OBJ_NAME)
	$(CC) -shared $(OBJ_NAME) -o $(NAME) $(LFLAGS)
	ln -s $(NAME) libft_malloc.so

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ_NAME)
	make clean -C ./libft

fclean: clean
	$(RM) libft_malloc.so
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all
