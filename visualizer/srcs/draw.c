/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 11:47:09 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:02:47 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "general.h"

void			draw_square(t_env *e, int i, int j, t_color c)
{
	int		k;
	int		l;

	i *= e->ratio;
	j *= e->ratio;
	k = i;
	while (++k < e->ratio + i)
	{
		l = j;
		while (++l < e->ratio + j)
			mlx_put(e, l + e->center_w, k + e->center_h, c);
	}
}

static void		draw_square_colors(t_env *e, int dw, int dh, t_color c)
{
	int		k;
	int		l;
	int		j;
	int		i;

	i = 0;
	j = 0;
	k = i;
	while (++k < 30 + i)
	{
		l = j;
		while (++l < 30 + j)
			mlx_put(e, 960 + l + (30 * dw), 200 + k + (dh), c);
	}
}

static void		draw_color_2(t_env *e)
{
	int m;
	int n;
	int d;
	int o;
	int size;

	size = 30;
	o = 1;
	d = 0;
	m = -1;
	while (++m < 3)
	{
		n = -1;
		while (++n < 4)
		{
			draw_square_colors(e, 6 + n, m * size + (size * o) + d,
									ft_hexrgb(e->player[0].color[m + 3][n]));
			draw_square_colors(e, 6 + n, m * size + size + (size * o) + d,
									ft_hexrgb(e->player[1].color[m + 3][n]));
		}
		o++;
		d += 15;
	}
}

void			draw_palette(t_env *e)
{
	int m;
	int n;
	int d;
	int o;
	int size;

	size = 30;
	o = 1;
	d = 0;
	m = -1;
	while (++m < 3)
	{
		n = -1;
		while (++n < 4)
		{
			draw_square_colors(e, n, m * size + (size * o) + d,
										ft_hexrgb(e->player[0].color[m][n]));
			draw_square_colors(e, n, m * size + size + (size * o) + d,
										ft_hexrgb(e->player[1].color[m][n]));
		}
		o++;
		d += 15;
	}
	draw_color_2(e);
}

void			draw_grid(t_env *e)
{
	int iw;
	int	ih;
	int	max;
	int min;

	max = ft_max((e->ratio * e->map.height), (e->ratio * e->map.width));
	min = ft_min((e->ratio * e->map.height), (e->ratio * e->map.width));
	if (e->map.height > e->map.width)
		ft_swap(&min, &max);
	ih = 0;
	while (ih < min + e->ratio)
	{
		iw = 0;
		while (++iw < max)
			mlx_put(e, iw + e->center_w, e->center_h + ih, ft_hexrgb(0x333333));
		ih += e->ratio;
	}
	iw = 0;
	while (iw < max + e->ratio)
	{
		ih = -1;
		while (++ih < min)
			mlx_put(e, iw + e->center_w, e->center_h + ih, ft_hexrgb(0x333333));
		iw += e->ratio;
	}
}
