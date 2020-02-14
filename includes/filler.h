/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/25 13:48:25 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 11:42:11 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_map
{
	int			height;
	int			width;
	short int	**map;
	short int	**heat;
}				t_map;

typedef struct	s_piece
{
	int			height;
	int			width;
	int			cs;
	int			ce;
	int			ls;
	int			le;
	int			real_height;
	int			real_width;
	int			**token;
}				t_piece;

typedef struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct	s_env
{
	short int	player;
	short int	foe;
	int			heatmax;
	int			heatscore;
	t_map		map;
	t_piece		piece;
	t_coords	coords;
}				t_env;

short int		init_maps(t_env *e);
void			free_maps(t_env *e);
void			update_map(t_env *e);

void			send_coordinates(t_env *e);
void			get_piece(t_env *e);
void			free_piece(t_env *e);

#endif
