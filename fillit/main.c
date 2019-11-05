/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:20:41 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/05 09:27:39 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For debugging
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "fillit.h"
#include "../libft/libft.h"


void	print_node(t_list *node)
{
	t_tetris *tetris;

	tetris = node->content;

	printf("HELLO:%s\n", tetris->shape);
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_list	*list;
	fd = 0;
	list = NULL;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return(1);
	}
	if (argc == 2)
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (0);
	read_file(fd, &list);
	if (list == NULL)
		printf("LIST NULL");
	ft_lstiter(list, &print_node);
	close(fd);
}
