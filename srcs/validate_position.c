/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:01:58 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/07 12:22:50 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		overlap(t_map *map, t_tetris *piece)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->arr[i] + piece->x;
	y = piece->arr[i + 1] + piece->y;
	while (i <= 6 && map->data[y][x] == '.')
	{
		i += 2;
		x = piece->arr[i] + piece->x;
		y = piece->arr[i + 1] + piece->y;
	}
	return (i != 8);
}


int		in_bounds(t_tetris *tetris, int map_size, char axis)
{
	if (axis == 'y')
		return (tetris->arr[1] + tetris->y < map_size &&
				tetris->arr[3] + tetris->y < map_size &&
				tetris->arr[5] + tetris->y < map_size &&
				tetris->arr[7] + tetris->y < map_size);
	else
		return (tetris->arr[0] + tetris->x < map_size &&
				tetris->arr[2] + tetris->x < map_size &&
				tetris->arr[4] + tetris->x < map_size &&
				tetris->arr[6] + tetris->x < map_size);
}


int			is_location_valid(t_map *map, t_tetris *tetris)
{
	return ((in_bounds(tetris, map->size, 'y')) && (in_bounds(tetris, map->size, 'x') &&
	(!overlap(map, tetris))));
}
