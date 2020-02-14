/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/25 13:48:04 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 12:12:21 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

static void			get_playerid_and_mapsize(t_env *e)
{
	char		*line;
	int			i;

	e->map.height = 0;
	e->map.width = 0;
	get_next_line(0, &line);
	e->player = line[10] - '0';
	e->foe = (e->player == 1 ? 2 : 1);
	ft_strdel(&line);
	get_next_line(0, &line);
	i = 8;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			e->map.height = e->map.height * 10 + (line[i] - '0');
		if (line[i] == ' ')
			break ;
		i++;
	}
	while (line[++i])
		if (ft_isdigit(line[i]))
			e->map.width = e->map.width * 10 + (line[i] - '0');
	e->heatmax = ft_sqrt((e->map.height * e->map.height) +
						(e->map.width * e->map.width));
	ft_strdel(&line);
}

static void			get_heatscore(t_env *e, int mi, int mj)
{
	int		i;
	int		j;
	int		heat_tmp;

	heat_tmp = 0;
	i = -1;
	while (++i < e->piece.real_height)
	{
		j = -1;
		while (++j < e->piece.real_width)
			if (e->piece.token[i + e->piece.ls][j + e->piece.cs])
				heat_tmp += e->map.heat[i + mi][j + mj];
	}
	if (heat_tmp > e->heatscore)
	{
		e->coords = (t_coords){.x = mi - e->piece.ls, .y = mj - e->piece.cs};
		e->heatscore = heat_tmp;
	}
}

static void			is_placeable(t_env *e, int mi, int mj)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (++i < e->piece.real_height && count < 2)
	{
		j = -1;
		while (++j < e->piece.real_width && count < 2)
			if (e->piece.token[i + e->piece.ls][j + e->piece.cs])
			{
				if (e->map.map[i + mi][j + mj] == e->player)
					count++;
				if (e->map.map[i + mi][j + mj] == e->foe)
					return ;
			}
	}
	if (count != 1)
		return ;
	get_heatscore(e, mi, mj);
	if (!e->heatscore)
		e->coords = (t_coords){.x = mi - e->piece.ls, .y = mj - e->piece.cs};
}

static void			start_filler(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i + e->piece.real_height <= e->map.height)
	{
		j = -1;
		while (++j + e->piece.real_width <= e->map.width)
			is_placeable(e, i, j);
	}
	ft_putnbr(e->coords.x);
	ft_putchar(' ');
	ft_putnbr(e->coords.y);
	ft_putchar('\n');
	e->coords = (t_coords){.x = 0, .y = 0};
	e->heatscore = 0;
}

int					main(void)
{
	t_env	*e;
	char	*line;

	if (!(e = malloc(sizeof(t_env))))
		return (1);
	e->heatscore = 0;
	get_playerid_and_mapsize(e);
	if (!init_maps(e))
		return (0);
	while (1)
	{
		update_map(e);
		get_piece(e);
		start_filler(e);
		free_piece(e);
		if (get_next_line(0, &line) <= 0)
			break ;
		if (line)
			ft_strdel(&line);
	}
	free_maps(e);
	free(e);
	return (0);
}
