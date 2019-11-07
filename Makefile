# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesta <mdesta@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 14:20:34 by mdesta            #+#    #+#              #
#    Updated: 2019/11/07 14:48:23 by mdesta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCL = -I fillit.h
INCL_LIB = ./libft/libft.a
OBJS = main.o read.o map_validators.o tetris_validators.o \
	   tetris.o map.o
SRCS = main.c read.c map_validators.c tetris_validators.c \
	   tetris.c map.c
LIB = make -C ./libft/

all: $(NAME)

$(NAME):
		$(LIB)
		@$(CC) $(CFLAGS) -c $(SRCS) $(INCL)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCL_LIB)


clean:
	rm -rf $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft/ fclean

re: fclean all
