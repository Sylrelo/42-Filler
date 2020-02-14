/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/26 19:54:54 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 18:05:29 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "general.h"

int				run(t_env *e)
{
	char	*line;

	if (get_next_line(0, &line) == 1)
	{
		if (ft_isdigit(line[0]) && ft_isdigit(line[1]) && ft_isdigit(line[2])
			&& line[3] == ' ')
		{
			update_map(e, line);
			show_everything(e);
		}
		else
			ft_strdel(&line);
	}
	else
	{
		if (!e->redraw)
			;
		e->redraw = 0;
		show_everything(e);
		ft_strdel(&line);
	}
	return (0);
}

void			init(t_env *e)
{
	e->mlx.ptr = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.ptr, WIDTH, HEIGHT, "FILLER VISUALIZER (SLOPEZ)");
	e->mlx.imgptr = mlx_new_image(e->mlx.ptr, WIDTH, HEIGHT);
	e->mlx.imgdata = mlx_get_data_addr(e->mlx.imgptr, &e->mlx.bpp, &e->mlx.size,
					&e->mlx.endian);
	mlx_background(e);
	get_players_and_map(e);
	if (!(init_maps(e)))
		exit(0);
	color_init_p1(e);
	color_init_p2(e);
	draw_palette(e);
	e->ratio = ft_min(940 / e->map.width, 720 / e->map.height);
	e->center_w = (940 - (e->ratio * e->map.width)) / 2;
	e->center_h = (720 - (e->ratio * e->map.height)) / 2;
	e->redraw = 0;
	draw_grid(e);
	progressbar(e);
}

int				main(void)
{
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
		exit(0);
	init(e);
	e->color = 4;
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win, e->mlx.imgptr, 0, 0);
	mlx_loop_hook(e->mlx.ptr, run, e);
	mlx_hook(e->mlx.win, 4, 0, mlx_mousepress, e);
	mlx_hook(e->mlx.win, 2, 0, mlx_keypress, e);
	mlx_hook(e->mlx.win, 17, 0, mlx_quit, e);
	mlx_loop(e->mlx.ptr);
	free_maps(e);
	ft_strdel(&e->player[0].name);
	ft_strdel(&e->player[1].name);
	free(e);
	return (0);
}
