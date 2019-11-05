/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:42:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/05 14:48:47 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../libft/libft.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

# define BLOCK '#'
# define EMPTY '.'
# define SIZE 4
# define T_ERROR -1

typedef struct		s_map
{
	int 			x;
	int 			y;
	int 			size;
	char			**data;
}					t_map;

typedef struct		s_tetris
{
	char			*shape;
	int				arr[8];
	char			c;
	int				x;
	int				y;
}					t_tetris;

int					read_file(const int fd, t_list **list);

int					get_blocks_and_validate_line(char *line);
int 				is_tetrimino_valid(char *str);

void				print_map(t_map *map);
t_map				*create_map(int size);

void put_piece(t_map *map, t_tetris *tetris);

t_tetris *create_tetris(char *shape, int x, int y);
void	normalize_tetrimino(t_list *node);

# define USAGE "usage:\t./fillit source_file\n"
# define ERROR_MSG "error\n"

#endif
