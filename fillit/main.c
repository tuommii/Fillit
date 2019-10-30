/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:04:07 by mtuomine          #+#    #+#             */
/*   Updated: 2019/10/30 10:23:24 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Remove this
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"
#include "fillit.h"


t_list	*read_tetris_file(int fd)
{
	char	*buf;
	size_t	bytes;
	t_list	*list;

	list = NULL;
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	while ((bytes = read(fd, buf, BUFFER_SIZE + 1)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		//printf("%s:%zu\n", buf, bytes);
		ft_lstadd(&list, ft_lstnew((char *)buf, sizeof(buf)));
	}
	free(buf);
	close(fd);
	return list;
}

void print_node(t_list *node)
{
	printf("%s\n", node->content);
}

void	print_list(t_list *list)
{
}

int main(int argc, const char **argv)
{
	t_list	*list;

	if (argc != 2)
		return (0);

	if (!(list = read_tetris_file(open(argv[1], O_RDONLY))))
		return (0);

	ft_lstiter(list, &print_node);
	//print_list(list);

	return (0);
}
