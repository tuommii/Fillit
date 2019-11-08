/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:20:41 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/08 09:04:49 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map				*fillit(t_list *list)
{
	t_map	*map;
	int		size;

	size = 2;
	map = create_map(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = create_map(size);
	}
	return (map);
}

static void			free_tetris(t_tetris *tetris)
{
	ft_memdel((void **)&tetris->shape);
	ft_memdel((void **)&tetris);
}

static void			clean_memory(t_list *list, t_map *map)
{
	if (list)
		ft_lstdel(&list, (void *)free_tetris);
	if (map)
		free_map(map);
}

static int			check_args(int argc, char **argv, int *fd)
{
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (1);
	}
	if (argc == 2)
		if ((*fd = open(argv[1], O_RDONLY)) < 0)
			return (1);
	return (0);
}

int					main(int argc, char *argv[])
{
	int			fd;
	t_list		*list;
	t_map		*map;

	map = NULL;
	list = NULL;
	fd = 0;
	if (check_args(argc, argv, &fd))
		return (1);
	if (read_file(fd, &list) == T_ERROR)
	{
		clean_memory(list, map);
		return (1);
	}
	ft_lstiter(list, &transform);
	ft_lstiter(list, &normalize_tetrimino);
	list = ft_lstreverse(list);
	map = fillit(list);
	print_map(map);
	clean_memory(list, map);
	return (0);
}
