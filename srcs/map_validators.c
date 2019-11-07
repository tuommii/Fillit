/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:01:58 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/07 13:26:51 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_overlapping(t_map *map, t_tetris *tetris)
{
	int i;
	int x;
	int y;

	i = 0;
	x = tetris->arr[i] + tetris->x;
	y = tetris->arr[i + 1] + tetris->y;
	while (i <= 6)
	{
		if (map->data[y][x] != '.')
			return (1);
		i += 2;
		x = tetris->arr[i] + tetris->x;
		y = tetris->arr[i + 1] + tetris->y;
	}
	return (0);
}

int		in_bounds_y(t_tetris *tetris, int map_size)
{
	return (tetris->arr[1] + tetris->y < map_size &&
	tetris->arr[3] + tetris->y < map_size &&
	tetris->arr[5] + tetris->y < map_size &&
	tetris->arr[7] + tetris->y < map_size);
}
int		in_bounds_x(t_tetris *tetris, int map_size)
{
	return (tetris->arr[0] + tetris->x < map_size &&
	tetris->arr[2] + tetris->x < map_size &&
	tetris->arr[4] + tetris->x < map_size &&
	tetris->arr[6] + tetris->x < map_size);
}
