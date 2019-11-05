/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:33 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/05 14:03:02 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char **create_map(int size)
{
	char **map;
	int i;
	int j;

	i = 0;
	map = malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * size);
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	print_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		int j = 0;
		while (j < size)
		{
			printf("%c", map[i][j]);
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
	new[k] = new[k] + i;
	new[k + 1] = new[k + 1] + j;
	k += 2;
	}
}

static int is_location_valid(int i, int j)
{
	if (i < 4 && j < 4)
		return (1);
	return (0);
}
// is_location_valid
void put_piece(char **map, int map_size, t_tetris *tetris)
{
	int i;
	int j;
	int z;
	i = 0;
	z = 0;
	while (i < map_size)
	{
		int j = 0;
		while (j < map_size)
		{
			if(is_location_valid(i, j))
			{
				add(i, j, tetris->arr);
				while (z < 8)
				{
					map[tetris->arr[z]][tetris->arr[z+1]] = tetris->c;
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
