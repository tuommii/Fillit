/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:42:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/04 10:43:01 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../libft/libft.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct		s_tetris
{
	void			*tet_id;
	char			c;
	struct s_tetris	*next;
}					t_tetris;

int					readt(const int fd);

# define USAGE "usage:\t./fillit source_file\n"

#endif
