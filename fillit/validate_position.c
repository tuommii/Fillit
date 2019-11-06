/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:01:58 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/06 13:15:13 by mtuomine         ###   ########.fr       */
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

	i = 0;
	size = map->size;
	while (i < 8)
	{
		if (map->data[tetris->arr[i + 1] + map->x][tetris->arr[i] + map->y] != '.')
		{
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
	if (x >= (map->size - map->x) || y >= (map->size - map->y))
		return (0);
	return (1);
}

//int		conditions(char **map, int *t_coord, int size)
int			is_location_valid(t_map *map, t_tetris *tetris)
{
	return ((inside_map(map, tetris->arr)) && (another_piece(map, tetris)));
}
