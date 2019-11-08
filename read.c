/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:25:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/08 06:18:08 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	clear_vars(char *tetr, char *line)
{
	ft_memdel((void **)&tetr);
	ft_memdel((void **)&line);
}

static int	handle_tetris(t_tetris *tetris, char *tetr, \
t_list **list, int blocks)
{
	if (blocks != SIZE || !is_tetrimino_valid(tetr))
		return (T_ERROR);
	tetris = create_tetris(tetr, 0, 0);
	ft_lstadd(list, ft_lstnew(tetris, sizeof(t_tetris)));
	ft_memdel((void **)&tetris);
	return (1);
}

static void	join(char *temp, char *line, char **tetr)
{
	temp = ft_strjoin(*tetr, line);
	ft_memdel((void **)tetr);
	*tetr = temp;
}

static int	read_tetrimino(const int fd, char *line, t_list **list)
{
	int			n_line;
	int			blocks;
	char		*tetr;
	char		*temp;
	t_tetris	*tetris;

	n_line = 0;
	blocks = 0;
	tetris = NULL;
	temp = NULL;
	if (!(tetr = ft_strnew(1)))
		return (T_ERROR);
	while (n_line++ < SIZE)
	{
		if (get_next_line(fd, &line))
		{
			if ((blocks += get_blocks_and_validate_line(line)) == T_ERROR)
				clear_vars(tetr, line);
			if ((get_blocks_and_validate_line(line)) == T_ERROR)
				return (T_ERROR);
			join(temp, line, &tetr);
		}
		ft_memdel((void **)&line);
	}
	return (handle_tetris(tetris, tetr, list, blocks));
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
			break ;
	}
	ft_memdel((void **)&line);
	close(fd);
	return (1);
}
