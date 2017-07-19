# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 11:09:29 by amathias          #+#    #+#              #
#    Updated: 2017/03/19 09:00:39 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC_NM =	nm.c			\
			fat.c			\
			nm_print.c		\
			nm_section.c	\
			nm_dylib.c		\
			nm_parse.c		\
			archive.c		\
			put_hex.c		\
			utils.c			\
			utils2.c		\


SRC_OT =	otool.c			\
			fat_otool.c		\
			otool_print.c	\
			archive_otool.c	\
			put_hex.c		\
			utils.c			\
			utils2.c		\

OBJ_NM = $(SRC_NM:.c=.o)
OBJ_OT = $(SRC_OT:.c=.o)
NAME = ft_nm
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g

LIB_PATH = ./libft/
LIB_NAME = -lft
LIB = $(addprefix -L,$(LIB_PATH))
LFLAGS = $(LIB) $(LIB_NAME)

INC_PATH = ./libft/
INC = $(addprefix -I,$(INC_PATH))

all: lib ft_nm ft_otool

lib:
	make -C ./libft

ft_nm: $(OBJ_NM)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ_NM) -o $@

ft_otool: $(OBJ_OT)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ_OT) -o $@

%.o: %.c
	$(CC) $(INC) -o $@ -c $^ $(CFLAGS)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all
