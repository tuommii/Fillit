/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:42:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/04 14:07:25 by mtuomine         ###   ########.fr       */
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

typedef struct		s_tetris
{
	void			*shape;
	char			c;
	int				x;
	int				y;
	struct s_tetris	*next;
}					t_tetris;

int					read_file(const int fd);

# define USAGE "usage:\t./fillit source_file\n"
# define ERROR_MSG "error\n"

#endif
