/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:33 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/07 18:38:22 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*create_map(int size)
{
	t_map	*map;

	if (!(map = ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	map->y = 0;
	map->data = malloc(sizeof(char *) * size + 1);
	map->y = 0;
	while (map->y < size)
	{
		map->x = 0;
		map->data[map->y] = malloc(sizeof(char) * size);
		while (map->x < size)
		{
			map->data[map->y][map->x] = '.';
			map->x++;
		}
		map->y++;
	}
	map->x = 0;
	map->y = 0;
	return (map);
}

void		place_tetris(t_tetris *tetris, t_map *map, char c)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = tetris->arr[i] + tetris->x;
		y = tetris->arr[i + 1] + tetris->y;
		map->data[y][x] = c;
		i += 2;
	}
}

void		print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			ft_putchar(map->data[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&map->data[i]);
		i++;
	}
	ft_memdel((void **)&map->data);
	ft_memdel((void **)&map);
}

int			solve_map(t_map *map, t_list *list)
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
