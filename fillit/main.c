/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:04:07 by mtuomine          #+#    #+#             */
/*   Updated: 2019/10/30 09:32:08 by mtuomine         ###   ########.fr       */
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
	char *buf;
	size_t bytes;
	t_list *list;

	list = ft_lstnew(NULL, 0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return NULL;
	while ((bytes = read(fd, buf, BUFFER_SIZE + 1)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		printf("%s", buf);

	}
	free(buf);
	close(fd);
	return list;
}

int main(int argc, const char **argv)
{
	t_list	*list;

	if (argc != 2)
		return (0);

	list = read_tetris_file(open(argv[1], O_RDONLY));
	return (0);
}
