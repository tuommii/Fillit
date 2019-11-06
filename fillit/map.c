/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:33 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/06 09:21:00 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
			printf("%c", map->data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static void	add(t_map *map, t_tetris *tetris)
{
	int	i;
	int	j;
	int k;

	k = 0;
	i = 0;
	j = 1;
	print_map(map);
//	printf("\nAdd at location: %d %d\n", i, j);
	printf("\nAdd at location map?: %d %d\n", map->x, map->y);
	while (k < 4)
	{
//		printf("k: %d %d %d\n", k, new[k + 1], (new[k + 1] + j));
//		new[k + 1] = new[k + 1] + j;
		map->data[map->x + tetris->arr[i]][map->y + tetris->arr[j]] = tetris->c;
		print_map(map);
		printf("\n");
		k++;
		i += 2;
		j += 2;
	}
}

int			put_piece(t_map *map, t_tetris *tetris)
{
	int i;

	map->y = -1;
	while (map->y++ < map->size)
	{
		map->x = -1;
		while (map->x++ < map->size)
		{
			if (is_location_valid(map, tetris))
			{
				add(map, tetris);
				i = 0;
				while (i < 8)
				{
					map->data[tetris->arr[i]][tetris->arr[i + 1]] = tetris->c;
					i += 2;
				}
				return (1);
			}
		}
	}
	return (0);
}
