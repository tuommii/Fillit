/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:20:41 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/07 14:52:19 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "fillit.h"
#include "../libft/libft.h"

static t_list		*reverse_list(t_list *list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	curr = list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	list = prev;
	return (list);
}

int					solve_map(t_map *map, t_list *list)
{
	t_tetris *tetris;

	if (list == NULL)
		return (1);
	tetris = (t_tetris *)(list->content);
	tetris->y = 0;
	tetris->x = 0;
	while (in_bounds_y(tetris, map->size))
	{
		tetris->x = 0;
		while (in_bounds_x(tetris, map->size))
		{
			if (!is_overlapping(map, tetris))
			{
				place_tetris(tetris, map, tetris->c);
				if (solve_map(map, list->next))
					return (1);
				else
					place_tetris(tetris, map, '.');
			}
			tetris->x++;
		}
		tetris->y++;
	}
	return (0);
}

t_map				*fillit(t_list *list)
{
	t_map	*map;
	int		size;

	size = 2;
	map = create_map(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = NULL;
		map = create_map(size);
	}
	return (map);
}

int					main(int argc, char *argv[])
{
	int			fd;
	t_list		*list;
	t_map		*map;

	list = NULL;
	fd = 0;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (1);
	}
	if (argc == 2)
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (1);
	read_file(fd, &list);
	ft_lstiter(list, &transform);
	ft_lstiter(list, &normalize_tetrimino);
	list = reverse_list(list);
	map = fillit(list);
	print_map(map);
	free_map(map);
	close(fd);

	int i = 0;
	while (1)
		i++;

	return (0);
}
