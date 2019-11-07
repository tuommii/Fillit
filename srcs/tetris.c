/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:37:23 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/07 13:31:35 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*create_tetris(char *shape, int x, int y)
{
	t_tetris	*tetris;
	static char c = 'A';

	if (!(tetris = ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	tetris->shape = shape;
	tetris->c = c;
	tetris->x = x;
	tetris->y = y;
	c++;
	return (tetris);
}

static int	min_x(int *tab)
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

static	int	min_y(int *tab)
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

void	transform(t_list *node)
{
	t_tetris	*tetris;
	int			i;
	int			j;
	int			x;
	int			y;

	tetris = node->content;
	i = 0;
	j = 0;
	while (tetris->shape[i])
	{
		if (tetris->shape[i] == BLOCK)
		{
			x = i % SIZE;
			y = i / SIZE;
			tetris->arr[j] = x;
			tetris->arr[j += 1] = y;
			j++;
		}
		i++;
	}
}

void		normalize_tetrimino(t_list *node)
{
	int			x;
	int			y;
	int			i;
	int			size;
	t_tetris	*tetris;

	tetris = node->content;
	size = 4;
	x = min_x(tetris->arr);
	y = min_y(tetris->arr);
	i = 0;
	while (size--)
	{
		tetris->arr[i] -= x;
		tetris->arr[i + 1] -= y;
		i += 2;
	}
}
