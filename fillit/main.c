/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:04:07 by mtuomine          #+#    #+#             */
/*   Updated: 2019/10/29 16:31:46 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Remove this
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include "fillit.h"


void handle_line(const char *line)
{
	static int count = 0;
	count++;
}

int main(int argc, const char **argv)
{
	char *line;
	int fd;
	int bytes;

	if (argc != 2)
		return (0);

	fd = open(argv[1], O_RDONLY);
	while ((bytes = get_next_line(fd, &line)) > 0)
	{
		handle_line(line);
		//ft_putstr(line);
		free(line);
	}
	close(fd);
	return (0);
}
