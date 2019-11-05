/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:37:23 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/05 09:26:29 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
