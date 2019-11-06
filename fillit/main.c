/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesta <mdesta@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:20:41 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/06 14:06:56 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For debugging
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "fillit.h"
#include "../libft/libft.h"

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

void	print_node(t_list *node)
{
	t_tetris	*tetris;
	int			i;

	tetris = node->content;
	i = 0;
	while (i < 8)
	{
		printf("%d", tetris->arr[i]);
		i++;
	}
	printf("\n");
}

t_list				*ft_lstreverse(t_list *list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	curr = list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	list = prev;
	return (list);
}

void  handle_tetris(t_list *node, t_map *map, int size)
{
	t_list *head;

	head = node;
	while (node != NULL)
	{
		if (!put_piece(map, node->content))
		{
			free(map);
			map = NULL;
			map = create_map(size + 1);
			handle_tetris(head, map, size + 1);
		}
		node = node->next;
	}
}

int		main(int argc, char *argv[])
{
	int			fd;
	t_list		*list;
	t_map		*map;
	int			start;

	start = 1;
	fd = 0;
	list = NULL;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (1);
	}
	if (argc == 2)
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (1);
	read_file(fd, &list);
	ft_lstiter(list, &transform);
	ft_lstiter(list, &print_node);
	ft_lstiter(list, &normalize_tetrimino);

	list = ft_lstreverse(list);

	map = create_map(start);
	handle_tetris(list, map, start);
	print_map(map);
	// Maybe we should use ft_lstdel
	close(fd);
}
