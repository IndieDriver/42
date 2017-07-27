# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:24:02 by amathias          #+#    #+#              #
#    Updated: 2015/12/02 16:39:36 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC_NAME = ft_bzero.s			\
		   ft_strcat.s			\
		   ft_isalpha.s			\
		   ft_isdigit.s			\
		   ft_isalnum.s			\
		   ft_isascii.s			\
		   ft_isprint.s			\
		   ft_tolower.s			\
		   ft_toupper.s			\
		   ft_strlen.s			\
		   ft_memcpy.s			\
		   ft_memset.s			\
		   ft_puts.s			\
		   ft_strdup.s			\
		   ft_cat.s				\
		   ft_vec4len.s			\
		   ft_vec4scale.s		\
		   ft_vec4dot.s			\
		   ft_vec4distance.s	\
		   ft_vec4normalize.s	\


OBJ_NAME = $(SRC_NAME:.s=.o)
NAME = libfts.a
CC_C = gcc
CC_ASM = nasm
ARCH = macho64
AR = ar rc
RAN = ranlib
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_NAME)
	$(AR) $(NAME) $(OBJ_NAME)
	$(RAN) $(NAME)

%.o: %.s
	$(CC_ASM) -f $(ARCH) -F dwarf -g $< -o $@


test:
	$(CC_C) -g main.c -I./ -L./ -lfts
	gcc -Wextra -Wall -Werror tests/main_bonus.c libfts.a
	./a.out

clean:
	$(RM) $(OBJ_NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all
