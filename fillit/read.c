/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:25:55 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/04 10:00:58 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
			
			count += h_count(line);
			if (ft_strlen(line) != 4 || count > 4 || !chk_char(line))
				ft_exit();
			free(line);
		}
		n_line++;
	}
	if (count < 4)
		ft_exit();
	return (1);
}

int		pre_read(const int fd)
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
			ft_exit();
	}
	close(fd);
	return (1);
}
