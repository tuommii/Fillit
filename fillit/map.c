/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:33 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/05 12:05:55 by mtuomine         ###   ########.fr       */
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
	map[i][j] = '\0';
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
