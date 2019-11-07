/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:20:41 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/07 12:38:06 by mtuomine         ###   ########.fr       */
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

int		place_tetris(t_tetris *tetris, t_map *map)
{
	add(map, tetris);
	return (1);
}

void	place(t_tetris *piece, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->arr[i] + piece->x;
		y = piece->arr[i + 1] + piece->y;
		map->data[y][x] = letter;
		i += 2;
	}
}

int		solve_map(t_map *map, t_list *list)
{
	t_tetris *tetris;

	if (list == NULL)
		return (1);
	tetris = (t_tetris *)(list->content);
	tetris->y = 0;
	tetris->x = 0;
	while (in_bounds(tetris, map->size, 'y'))
	{
		while (in_bounds(tetris, map->size, 'x'))
		{
			if (!overlap(map, tetris))
			{
				place(tetris, map, tetris->c);
				if (solve_map(map, list->next))
					return (1);
				else
					place(tetris, map, '.');
					//map->data[tetris->y][tetris->x] = 0;
			}
			tetris->x++;
		}
		tetris->x = 0;
		tetris->y++;
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
	}
	return (map);
}

int		main(int argc, char *argv[])
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
	close(fd);
}
