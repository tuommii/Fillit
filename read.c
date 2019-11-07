/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:25:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/07 16:47:27 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	read_tetrimino(const int fd, char *line, t_list **list)
{
	int			n_line;
	int			total_blocks;
	int			blocks;
	char		*tetr;
	char		*temp;
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
			{
				ft_memdel((void **)&tetr);
				ft_memdel((void **)&line);
				return (T_ERROR);
			}
			total_blocks += blocks;
			temp = ft_strjoin(tetr, line);
			ft_memdel((void **)&tetr);
			tetr = temp;
		}
		ft_memdel((void **)&line);
	}
	if (total_blocks != SIZE || !is_tetrimino_valid(tetr))
		return (T_ERROR);
	tetris = create_tetris(tetr, 0, 0);
	ft_lstadd(list, ft_lstnew(tetris, sizeof(t_tetris)));
	ft_memdel((void **)&tetris);
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
			ft_memdel((void **)&line);
			ft_putstr("error\n");
			return (T_ERROR);
		}
		if (!get_next_line(fd, &line))
		{
			ft_memdel((void **)&line);
			break ;
		}
		ft_memdel((void **)&line);
	}
	close(fd);
	return (1);
}
