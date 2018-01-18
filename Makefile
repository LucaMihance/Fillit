# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmihance <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 17:51:34 by lmihance          #+#    #+#              #
#    Updated: 2018/01/09 14:08:08 by lmihance         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FUNCTIONS = check.c ft_actualread.c ft_read.c main.c matrix.c solve.c

OBJ = $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror ./src/*.c ./includes/*ft_*.c -I ./src/fillit.h -c
	gcc -Wall -Wextra -Werror *.o -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
