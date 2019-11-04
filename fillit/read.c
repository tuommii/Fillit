/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:25:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/04 10:58:49 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include "../libft/get_next_line.h"

static int		read_tetrimino(const int fd, char *line)
{
	int n_line;

	n_line = 0;
	while (n_line < 4)
	{
		if (get_next_line(fd, &line))
		{
			ft_putendl(line);
		}
		n_line++;
	}
	return (1);
}

int		read_file(const int fd)
{
	char *line;

	line = NULL;
	while (1)
	{
		read_tetrimino(fd, line);
		if (!get_next_line(fd, &line))
		{
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
	return (1);
}
