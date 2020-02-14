/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx.utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 10:44:02 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:03:12 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "general.h"

void			mlx_put(t_env *e, int x, int y, t_color c)
{
	int		i;

	if (!((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT)))
		return ;
	i = (x * 4) + (y * e->mlx.size);
	e->mlx.imgdata[i] = (char)c.b;
	e->mlx.imgdata[i + 1] = (char)c.g;
	e->mlx.imgdata[i + 2] = (char)c.r;
	e->mlx.imgdata[i + 3] = (char)c.a;
}

int				mlx_quit(t_env *e)
{
	mlx_destroy_window(e->mlx.ptr, e->mlx.win);
	free_maps(e);
	exit(1);
	return (1);
}

void			mlx_background(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			mlx_put(e, j, i, (t_color){35, 35, 35, 0});
	}
}

int				mlx_keypress(int k, t_env *e)
{
	if (k == 53)
		mlx_quit(e);
	return (1);
}

int				mlx_mousepress(int k, int x, int y, t_env *e)
{
	if (k != 1)
		return (0);
	if (x >= 964 && x <= 1080 && y >= 230 && y <= 288)
		e->color = 0;
	if (x >= 964 && x <= 1080 && y >= 310 && y <= 365)
		e->color = 1;
	if (x >= 964 && x <= 1080 && y >= 386 && y <= 440)
		e->color = 2;
	if (x >= 1140 && x <= 1257 && y >= 230 && y <= 288)
		e->color = 3;
	if (x >= 1140 && x <= 1257 && y >= 310 && y <= 365)
		e->color = 4;
	if (x >= 1140 && x <= 1257 && y >= 386 && y <= 440)
		e->color = 5;
	e->redraw = 1;
	return (1);
}
