NAME		=	fillit

LIBFT_DIR	= 	libft/
LIBFT_A		= 	libft.a
LIBFT_H		= 	-I libft/
FILLIT_H	= 	-I fillit/

OBJ_DIR		= 	obj/
SRC_DIR		= 	fillit/

COMP		= 	gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

CFILE		= 	main.c

SRC =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all:
	gcc fillit/main.c fillit/read.c fillit/fillit.h libft/libft.a
