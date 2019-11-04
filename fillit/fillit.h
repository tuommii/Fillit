/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:53:23 by phtruong          #+#    #+#             */
/*   Updated: 2019/11/04 10:19:11 by mdesta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct		s_tetris
{
	void			*tet_id;
	char			c;
	struct s_tetris	*next;
}					t_tetris;

# define USAGE "usage:\t./fillit source_file\n"

#endif
