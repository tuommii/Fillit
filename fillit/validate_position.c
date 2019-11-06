/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesta <mdesta@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:01:58 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/06 12:30:46 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	y_limit(int *t_coord)
{
	int size;
	int i;
	int y;

	i = 1;
	size = 3;
	y = t_coord[i];
	while (size--)
	{
		i += 2;
		if (y < t_coord[i])
			y = t_coord[i];
	}
	return (y);
}

static int	x_limit(int *t_coord)
{
	int size;
	int i;
	int x;

	i = 0;
	size = 3;
	x = t_coord[i];
	while (size--)
	{
		i += 2;
		if (x < t_coord[i])
			x = t_coord[i];
	}
	return (x);
}

static int	another_piece(t_map *map, t_tetris *tetris)
{
	int size;
	int i;
	int	j;

	i = 0;
	size = map->size;
	j = 0;
	while (j < 8)
	{
		printf("%d", tetris->arr[j]);
		j++;
	}
	printf("\n");
	print_map(map);
	while (i < 8)
	{
		printf("%d %d\n", tetris->arr[i + 1] + map->x, tetris->arr[i] + map->y);
		if (map->data[tetris->arr[i + 1] + map->x][tetris->arr[i] + map->y] != '.')
		{
			printf("no another piece\n");
			return (0);
		}
		i += 2;
	}
	return (1);
}

static int	inside_map(t_map *map, int *t_coord)
{
	int x;
	int y;

	y = x_limit(t_coord);
	x = y_limit(t_coord);
	printf("limits: x_limit =  %d y_limit = %d\n", x, y);
	printf("Map coord: map->x = %d mp->y = %d size = %d\n", map->x, map->y, map->size);
	if (x >= (map->size - map->x) || y >= (map->size - map->y))
		return (0);
	return (1);
}

//int		conditions(char **map, int *t_coord, int size)
int			is_location_valid(t_map *map, t_tetris *tetris)
{
	return ((inside_map(map, tetris->arr)) && (another_piece(map, tetris)));
}
