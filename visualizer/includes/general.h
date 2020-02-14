/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   general.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/26 19:55:17 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:04:54 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# define WIDTH 1280
# define HEIGHT 720

typedef struct			s_map
{
	int					height;
	int					width;
	short int			**map;
}						t_map;

typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	void				*imgptr;
	void				*img;
	char				*imgdata;
	int					size;
	int					endian;
	int					bpp;
}						t_mlx;

typedef struct			s_players
{
	char				*name;
	int					color[6][4];
	int					score;
	int					score_tmp;
}						t_players;

typedef struct			s_env
{
	t_mlx				mlx;
	t_map				map;
	t_players			player[2];
	int					color;
	int					ratio;
	int					center_h;
	int					center_w;
	int					redraw;
}						t_env;

short int				init_maps(t_env *e);
void					free_maps(t_env *e);
void					get_players_and_map(t_env *e);
void					draw_square(t_env *e, int i, int j, t_color c);
void					draw_grid(t_env *e);
void					mlx_put(t_env *e, int x, int y, t_color c);
int						mlx_quit(t_env *e);
void					mlx_background(t_env *e);
int						mlx_keypress(int k, t_env *e);
void					draw_palette(t_env *e);
int						mlx_mousepress(int x, int y, int k, t_env *e);
void					color_init_p1(t_env *e);
void					color_init_p2(t_env *e);
void					show_map(t_env *e);
void					show_everything(t_env *e);
void					show_infobar(t_env *e);
void					progressbar(t_env *e);
void					progressbar_fill(t_env *e, int pos, int player);
void					update_map(t_env *e, char *line);
void					show_map(t_env *e);

#endif
