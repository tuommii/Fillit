/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:04:07 by mtuomine          #+#    #+#             */
/*   Updated: 2019/10/29 16:07:30 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Remove this
#include <stdio.h>
#include "libft.h"

int main(int argc, const char **argv)
{
	char **line;

	if (argc != 2)
		return (0);

	get_next_line();
	ft_putstr("Hello!");
	return (0);
}
