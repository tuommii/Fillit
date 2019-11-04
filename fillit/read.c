/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:25:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/04 14:55:53 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For debugging
#include <stdio.h>
#include "fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include "../libft/get_next_line.h"

static int		read_tetrimino(const int fd, char *line)
{
	int n_line;
	int total_blocks;
	int blocks;
	char *tetr;

	n_line = 0;
	total_blocks = 0;
	blocks = 0;
	if (!(tetr = ft_strnew(1)))
		return (T_ERROR);
	while (n_line++ < SIZE)
	{
		if (get_next_line(fd, &line))
		{
			if ((blocks = get_blocks_and_validate_line(line)) == T_ERROR)
				return (T_ERROR);
			total_blocks += blocks;
			tetr = ft_strjoin(tetr, line);
		}
	}
	if (total_blocks != SIZE || !is_tetrimino_valid(tetr))
		return (T_ERROR);
	// Now we can pass tetr to some function that stores those
	printf("%s", tetr);
	return (1);
}

int		read_file(const int fd)
{
	char *line;

	line = NULL;
	while (1)
	{
		if (read_tetrimino(fd, line) == T_ERROR)
		{
			ft_putstr("error\n");
			exit(1);
		}

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
