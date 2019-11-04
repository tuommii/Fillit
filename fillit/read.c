/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:25:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/04 12:13:13 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For debugging
#include <stdio.h>
#include "fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include "../libft/get_next_line.h"


static int is_line_length_valid(char *line)
{
	if (ft_strlen(line) != SIZE)
		return (0);
	return (1);
}

static int is_char_valid(char c)
{
	if (!(c == BLOCK || c == EMPTY))
		return (0);
	return (1);
}

/*
** Return block count or T_ERROR (-1) if error
*/
static int get_blocks_and_validate_line(char *line)
{
	int counter;

	if (!is_line_length_valid(line))
		return (T_ERROR);
	counter = 0;
	while (*line)
	{
		if (!is_char_valid(*line))
			return (T_ERROR);
		if (*line == BLOCK)
			counter++;
		line++;
	}
	return (counter);
}

static int		read_tetrimino(const int fd, char *line)
{
	int n_line;
	int total_blocks;
	int blocks;

	n_line = 0;
	total_blocks = 0;
	blocks = 0;
	while (n_line < SIZE)
	{
		if (get_next_line(fd, &line))
		{
			ft_putendl(line);
			if ((blocks = get_blocks_and_validate_line(line)) == T_ERROR)
				return (T_ERROR);
			total_blocks += blocks;
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
