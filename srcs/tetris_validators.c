/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_validators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:54:21 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/06 16:58:15 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

static int	is_line_length_valid(char *line)
{
	if (ft_strlen(line) != SIZE)
		return (0);
	return (1);
}

static int	is_char_valid(char c)
{
	if (!(c == BLOCK || c == EMPTY))
		return (0);
	return (1);
}

/*
** Return block count or T_ERROR (-1) if error
*/

int			get_blocks_and_validate_line(char *line)
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

/*
** Valid tetriminos should have 6 or 8 connections
*/

//.....##......##.
int			is_tetrimino_valid(char *str)
{
	int connections;

	connections = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] == BLOCK)
		{
			if ((i - SIZE) >= 0 && str[i - SIZE] == '#')
				connections++;
			if ((i + SIZE) < 16 && str[i + SIZE] == '#')
				connections++;
			if ((i + 1) < 16 && str[i + 1] == '#')
				connections++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				connections++;
		}
		i++;
	}
	if (connections == 6 || connections == 8)
		return (1);
	return (0);
}
