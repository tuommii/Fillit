/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:20:41 by mdesta            #+#    #+#             */
/*   Updated: 2019/11/04 10:14:50 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "fillit.h"


int		main(int argc, char *argv[])
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return(1);
	}
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	else if (fd > 0)
	{
		read(fd)
	}
	close(fd);
}
