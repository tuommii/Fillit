/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:33 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/05 21:46:57 by mdesta           ###   ########.fr       */
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

// is_location_valid
int	 put_piece(t_map *map, t_tetris *tetris)
{
	int i;
	int j;
	int z;
	i = 0;
	z = 0;
	printf("X: %d and Y: %d\n", map->x, map->y);
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			map->x = j;
			map->y = i;
			printf("Point in map X: %d and Y: %d\n", map->x, map->y);
			if(is_location_valid(map, tetris))
			{
				printf("yes\n");
				add(map, tetris);
				while (z < 8)
				{
					map->data[tetris->arr[z]][tetris->arr[z+1]] = tetris->c;
					z += 2;
				}
				return (1);
			}
			else
				printf("no\n");
			j++;
		}
		i++;
	}
	printf("X: %d and Y: %d\n", map->x, map->y);
	return (0);
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
