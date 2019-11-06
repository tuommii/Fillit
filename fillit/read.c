/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesta <mdesta@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:25:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/06 10:45:51 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For debugging
#include <stdio.h>
#include "fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include "../libft/get_next_line.h"

static int	read_tetrimino(const int fd, char *line, t_list **list)
{
	int			n_line;
	int			total_blocks;
	int			blocks;
	char		*tetr;
	t_tetris	*tetris;

	n_line = 0;
	total_blocks = 0;
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
	tetris = create_tetris(tetr, 0, 0);
	ft_lstadd(list, ft_lstnew(tetris, sizeof(t_tetris)));
	return (1);
}

int			read_file(const int fd, t_list **list)
{
	char *line;

	line = NULL;
	while (1)
	{
		if (read_tetrimino(fd, line, list) == T_ERROR)
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
