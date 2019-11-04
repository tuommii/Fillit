/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:53:23 by phtruong          #+#    #+#             */
/*   Updated: 2019/11/04 10:06:35 by mdesta           ###   ########.fr       */
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

# define I_PIECE (int [8]) {0,0,0,1,0,2,0,3}
# define IH_PIECE (int [8]) {0,0,1,0,2,0,3,0}
# define O_PIECE (int [8]) {0,0,1,0,0,1,1,1}
# define L_PIECE (int [8]) {0,0,0,1,0,2,1,2}
# define LR_PIECE (int [8]) {0,0,1,0,2,0,0,1}
# define LD_PIECE (int [8]) {0,0,1,0,1,1,1,2}
# define LL_PIECE (int [8]) {2,0,0,1,1,1,2,1}
# define J_PIECE (int [8]) {1,0,1,1,0,2,1,2}
# define JR_PIECE (int [8]) {0,0,0,1,1,1,2,1}
# define JD_PIECE (int [8]) {0,0,1,0,0,1,0,2}
# define JL_PIECE  (int [8]) {0,0,1,0,2,0,2,1}
# define T_PIECE (int [8]) {1,0,0,1,1,1,2,1}
# define TR_PIECE (int [8]) {0,0,0,1,1,1,0,2}
# define TD_PIECE (int [8]) {0,0,1,0,2,0,1,1}
# define TL_PIECE (int [8]) {1,0,0,1,1,1,1,2}
# define S_PIECE (int [8]) {1,0,2,0,0,1,1,1}
# define SR_PIECE (int [8]) {0,0,0,1,1,1,1,2}
# define Z_PIECE (int [8]) {0,0,1,0,1,1,2,1}
# define ZR_PIECE (int [8]) {1,0,0,1,1,1,0,2}
# define USAGE "usage:\t./fillit source_file\n"

#endif
