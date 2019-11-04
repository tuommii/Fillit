/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtuomine <mtuomine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:04:21 by mtuomine          #+#    #+#             */
/*   Updated: 2019/11/04 09:02:59 by mtuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// Whatever u wanna use
# define ROWS 4
# define COLS 4
# define SIZE 4

# define BUFFER_SIZE 20

# define EMPTY	"."
# define BLOCK 	"#"


typedef struct s_tetris
{
	char	*buffer;
	int		test;
} t_tetris;

#endif
