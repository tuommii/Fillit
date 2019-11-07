/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:33 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/07 12:33:39 by mtuomine         ###   ########.fr       */
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
	ft_putchar('\n');
}

void	add(t_map *map, t_tetris *tetris)
{
	int	i;
	int	j;
	int k;

	k = 0;
	i = 0;
	j = 1;
	while (k < 4)
	{
		map->data[tetris->x][tetris->y] = tetris->c;
		k++;
		i += 2;
		j += 2;
	}
}

void	clear(t_map *map, t_tetris *tetris)
{
	map->data[tetris->x][tetris->y] = '.';
}

int			put_piece(t_map *map, t_list *node)
{
	map->y = -1;
	while (map->y++ < map->size)
	{
		map->x = -1;
		while (map->x++ < map->size)
		{
			if (is_location_valid(map, node->content))
			{
				add(map, node->content);
				return (1);
			}
		}
	}
	return (0);
}
