/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:20:41 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/06 07:01:47 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For debugging
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "fillit.h"
#include "../libft/libft.h"

void transform(t_list *node)
{
	t_tetris *tetris;
	int i;
	int j;
	int x;
	int y;

	tetris = node->content;
	i = 0;
	j = 0;
	while (tetris->shape[i])
	{
		if (tetris->shape[i] == BLOCK)
		{
			x = i % SIZE;
			y = i / SIZE;
			printf("%d, %d\n", x, y);
			tetris->arr[j] = x;
			tetris->arr[j += 1] = y;
			j++;
		}
		i++;
	}
	printf("\n");
}

void	print_node(t_list *node)
{
	t_tetris *tetris;
	int i;

	tetris = node->content;
	i = 0;
	while (i < 8)
	{
		printf("%d", tetris->arr[i]);
		i++;
	}
	printf("\n");
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_list	*list;
	t_map	*map;
	t_tetris *tetris;
	int		x;
	int		y;

	fd = 0;
	list = NULL;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return(1);
	}
	if (argc == 2)
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (1);
	read_file(fd, &list);
	ft_lstiter(list, &transform);
	ft_lstiter(list, &print_node);
	ft_lstiter(list, &normalize_tetrimino);

	map = create_map(8);
	printf("map created\n");
	print_map(map);

	tetris = list->content;
	printf("%c\n%s\n", tetris->c, tetris->shape);
	put_piece(map, tetris);
	print_map(map);

	list = list->next;
	tetris = list->content;
	printf("%c\n%s\n", tetris->c, tetris->shape);
//	map->x = 0;
//	map->y = 0;
	put_piece(map, tetris);
	print_map(map);

	close(fd);
}
