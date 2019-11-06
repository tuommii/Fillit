/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:20:41 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/06 21:30:48 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://github.com/Jemmeh/42-Fillit/blob/master/ProjectFiles/fillitproject/solver.c

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "fillit.h"
#include "../libft/libft.h"

void	transform(t_list *node)
{
	t_tetris	*tetris;
	int			i;
	int			j;
	int			x;
	int			y;

	tetris = node->content;
	i = 0;
	j = 0;
	while (tetris->shape[i])
	{
		if (tetris->shape[i] == BLOCK)
		{
			x = i % SIZE;
			y = i / SIZE;
			tetris->arr[j] = x;
			tetris->arr[j += 1] = y;
			j++;
		}
		i++;
	}
}

static t_list	*reverse_list(t_list *list)
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

int		place_tetris(t_tetris *tetris, t_map *map, int x, int y)
{
	map->x = x;
	map->y = y;
	if (!is_location_valid(map, tetris))
		return (0);
	add(map, tetris);
	return (1);
}

int		solve_map(t_map *map, t_list *list)
{
	int x;
	int y;
	t_tetris *tetris;
	if (list == NULL)
		return (1);
	y = 0;
	tetris = (t_tetris *)(list->content);
	while (y < (map->size))
	{
		x = 0;
		while (x < (map->size))
		{
			if (place_tetris(tetris, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					map->data[x][y] = '.';
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map *fillit(t_list *list)
{
	t_map *map;
	int size;

	size = 2;
	map = create_map(size);
	while (!solve_map(map, list))
	{
		size++;
		free(map);
		map = NULL;
		map = create_map(size);
		ft_putstr("Increasing map size\n");
	}
	return (map);
}

int		main(int argc, char *argv[])
{
	int			fd;
	t_list		*list;
	t_map		*map;

	list = NULL;
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
	close(fd);
}
