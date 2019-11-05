/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:37:23 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/05 11:04:52 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
// rremove stdio header

t_tetris *create_tetris(char *shape, char c, int x, int y)
{
	t_tetris *tetris;

	if (!(tetris = ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	tetris->shape = ft_strdup(shape);
	tetris->c = c;
	tetris->x = x;
	tetris->y = y;
	return (tetris);
}

static	int		min_x(int *tab)
{
	int x;
	int i;
	int size;

	size = 4;
	i = 0;
	x = tab[i];
	while (size--)
	{
		if (tab[i] >= 0 && tab[i] <= 3)
			if (tab[i] < x)
				x = tab[i];
		i += 2;
	}
	return (x);
}

static	int		min_y(int *tab)
{
	int y;
	int i;
	int size;

	size = 4;
	i = 1;
	y = tab[i];
	while (size--)
	{
		if (tab[i] >= 0 && tab[i] <= 3)
			if (tab[i] < y)
				y = tab[i];
		i += 2;
	}
	return (y);
}
void	normalize_tetrimino(t_list *node)
{
	int x;
	int y;
	int i;
	int size;
	int	j;
	t_tetris	*tetris;


	tetris = node->content;
	size = 4;
	x = min_x(tetris->arr);
	y = min_y(tetris->arr);
	printf("\nNormalizing factors: x = %d y= %d\n", x, y);
	i = 0;
	while (size--)
	{
		tetris->arr[i] -= x;
		tetris->arr[i + 1] -= y;
		i += 2;
	}
	j = 0;
	printf("Normalized tetrimono coordinates:\n");
	while (j < 8)
	{
		printf("%d", tetris->arr[j]);
		j++;
	}
}

