/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 18:29:34 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:02:08 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "general.h"

static void		map_fill(t_env *e, char *line, int i, int j)
{
	int		r;

	r = rand() % 4;
	if (line[4 + j] == 'O' && !e->map.map[i][j])
		e->map.map[i][j] = r + 1;
	if (line[4 + j] == 'X' && !e->map.map[i][j])
		e->map.map[i][j] = r + 5;
	if (line[4 + j] == 'x' || line[4 + j] == 'o')
	{
		draw_square(e, i, j, ft_hexrgb(0xffffff));
		e->player[(line[4 + j] == 'o' ? 0 : 1)].score_tmp++;
	}
}

void			update_map(t_env *e, char *line)
{
	int		i;
	int		j;

	e->player[0].score_tmp = 0;
	e->player[1].score_tmp = 0;
	i = -1;
	while (++i < e->map.height)
	{
		j = -1;
		while (++j < e->map.width)
		{
			if (line[4 + j] != '.')
				map_fill(e, line, i, j);
		}
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	ft_strdel(&line);
}

void			show_map(t_env *e)
{
	int		i;
	int		j;

	e->player[0].score = 0;
	e->player[1].score = 0;
	i = 0;
	while (i < e->map.height)
	{
		j = -1;
		while (++j < e->map.width)
		{
			if (e->map.map[i][j] >= 1 && e->map.map[i][j] <= 4 &&
					++e->player[0].score)
				draw_square(e, i, j,
				ft_hexrgb(e->player[0].color[e->color][e->map.map[i][j] - 1]));
			if (e->map.map[i][j] >= 5 && e->map.map[i][j] <= 8 &&
					++e->player[1].score)
				draw_square(e, i, j,
				ft_hexrgb(e->player[1].color[e->color][e->map.map[i][j] - 5]));
		}
		i++;
	}
}
