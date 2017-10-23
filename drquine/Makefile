# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amathias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 11:09:29 by amathias          #+#    #+#              #
#    Updated: 2016/09/15 10:30:20 by amathias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = /

SRC =	main.c	\

OBJ = $(SRC:.c=.o)
COLLEEN = Colleen
GRACE = Grace
SULLY = Sully
CC = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: $(COLLEEN) $(GRACE) $(SULLY)

$(COLLEEN): Colleen.o
	$(CC) $(CFLAGS) $(LFLAGS) Colleen.c -o $@

$(GRACE): Grace.o
	$(CC) $(CFLAGS) $(LFLAGS) Grace.c -o $@

$(SULLY): Sully.o
	$(CC) $(CFLAGS) $(LFLAGS) Sully.c -o $@

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	$(RM) Colleen.o
	$(RM) Grace.o
	$(RM) Sully.o

fclean: clean
	$(RM) $(COLLEEN)
	$(RM) $(GRACE)
	$(RM) $(SULLY)

re: fclean all
