/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:25:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/04 10:44:48 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include "../libft/get_next_line.h"

int		read_one(const int fd, char *line)
{
	int n_line;
	int count;

	n_line = 0;
	count = 0;
	while (n_line < 4)
	{
		if (get_next_line(fd, &line))
		{
			ft_putendl(line);		

		}
		n_line++;
	}
	if (count < 4)
		return(0);
	return (1);
}

int		readt(const int fd)
{
	char *line;

	line = NULL;
	while (1)
	{
		read_one(fd, line);
		if (!get_next_line(fd, &line))
			break ;
		free(line);
		if (ft_strlen(line) != 0)
			return(0);
	}
	close(fd);
	return (1);
}
