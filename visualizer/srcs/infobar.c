/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   infobar.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 18:33:19 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 18:05:00 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "general.h"

void			progressbar(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (++i < 35)
	{
		j = -1;
		while (++j < 305)
		{
			mlx_put(e, 960 + j, 45, ft_hexrgb(0xCCCCCC));
			mlx_put(e, 960 + j, 80, ft_hexrgb(0xCCCCCC));
			mlx_put(e, 960 + j, 150, ft_hexrgb(0xCCCCCC));
			mlx_put(e, 960 + j, 185, ft_hexrgb(0xCCCCCC));
		}
		mlx_put(e, 960, 45 + i, ft_hexrgb(0xCCCCCC));
		mlx_put(e, 1265, 45 + i, ft_hexrgb(0xCCCCCC));
		mlx_put(e, 960, 150 + i, ft_hexrgb(0xCCCCCC));
		mlx_put(e, 1265, 150 + i, ft_hexrgb(0xCCCCCC));
	}
}

void			progressbar_fill(t_env *e, int pos, int player)
{
	int i;
	int j;

	i = -1;
	while (++i < 32)
	{
		j = -1;
		while (++j < (e->player[player].score * 302 /
						(e->map.height * e->map.width)))
			mlx_put(e, 962 + j, i + pos,
				ft_hexrgb(e->player[player].color[e->color][0]));
	}
}

void			show_infobar(t_env *e)
{
	char	*tmp;
	int		size;

	mlx_string_put(e->mlx.ptr, e->mlx.win, 960, 10,
							e->player[0].color[e->color][0], e->player[0].name);
	progressbar_fill(e, 47, 0);
	tmp = ft_itoa(e->player[0].score + e->player[0].score_tmp);
	size = ft_strlen(tmp);
	mlx_string_put(e->mlx.ptr, e->mlx.win, 1265 - (10 * size), 10,
										e->player[0].color[e->color][0], tmp);
	ft_strdel(&tmp);
	mlx_string_put(e->mlx.ptr, e->mlx.win, 960, 120,
							e->player[1].color[e->color][0], e->player[1].name);
	tmp = ft_itoa(e->player[1].score + e->player[1].score_tmp);
	progressbar_fill(e, 152, 1);
	size = ft_strlen(tmp);
	mlx_string_put(e->mlx.ptr, e->mlx.win, 1265 - (10 * size), 120,
										e->player[1].color[e->color][0], tmp);
	
	mlx_string_put(e->mlx.ptr, e->mlx.win, WIDTH - (ft_strlen("slopez") * 10) - 5, HEIGHT - 25, 0x999999, "slopez");
	ft_strdel(&tmp);
}

void			show_everything(t_env *e)
{
	show_map(e);
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win, e->mlx.imgptr, 0, 0);
	show_infobar(e);
}
