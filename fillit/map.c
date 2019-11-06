/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:33 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/05 15:32:26 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_map *create_map(int size)
{
	t_map	*map;

	if (!(map = ft_memalloc(sizeof(t_map))))
		return (NULL);

	map->size	= size;
	map->y		= 0;
	map->data = malloc(sizeof(char *) * size + 1);
	map->y = 0;
	while (map->y < size)
	{
		map->x		= 0;
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

void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size)
	{
		int j = 0;
		while (j < map->size)
		{
			printf("%c", map->data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


static void	add(int i, int j, int *new)
{
	int k;

	k = 0;
	while (k < 8)
	{
	new[k + 1] = new[k + 1] + j;
	k += 2;
	}
}

// is_location_valid
void put_piece(t_map *map, t_tetris *tetris)
{
	int i;
	int j;
	int z;
	i = 0;
	z = 0;
	while (i < map->size)
	{
		int j = 0;
		while (j < map->size)
		{
			map->x = j;
			map->y = i;
			if(is_location_valid(map, tetris))
			{
				add(map->y, map->x, tetris->arr);
				while (z < 8)
				{
					map->data[tetris->arr[z]][tetris->arr[z+1]] = tetris->c;
					z += 2;
				}
			}
			j++;
		}
		i++;
	}
}

/*void loop_arr(int x, int y, t_tetris *tetris)
{
	int i;

	i = 0:
	while (i < 8)
	{
		tetris->
	}
}
*/
