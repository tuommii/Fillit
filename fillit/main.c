/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:04:07 by mtuomine          #+#    #+#             */
/*   Updated: 2019/10/30 10:08:56 by mtuomine         ###   ########.fr       */
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
	t_list	*current;
	list = ft_lstnew(NULL, 0);
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	while ((bytes = read(fd, buf, BUFFER_SIZE + 1)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		current->content = buf;
		ft_lstadd(&list, current);
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

	ft_lstiter(list, print_node);
	//print_list(list);

	return (0);
}
