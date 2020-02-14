/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/25 18:59:01 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 11:28:48 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

short int	init_maps(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	if (!(e->map.map = malloc(sizeof(int *) * e->map.height)))
		return (0);
	if (!(e->map.heat = malloc(sizeof(int *) * e->map.height)))
		return (0);
	while (++i < e->map.height)
	{
		if (!(e->map.map[i] = malloc(sizeof(int) * e->map.width)))
			return (0);
		if (!(e->map.heat[i] = malloc(sizeof(int) * e->map.width)))
			return (0);
		j = -1;
		while (++j < e->map.width)
			e->map.map[i][j] = 0;
	}
	return (1);
}

static void	heatmap_update_populate(t_env *e, int i, int j, int val)
{
	int		new;

	new = val - 1;
	if (j - 1 >= 0 && e->map.heat[i][j - 1] < val)
		e->map.heat[i][j - 1] = new;
	if (j - 1 >= 0 && i - 1 >= 0 && e->map.heat[i - 1][j - 1] < val)
		e->map.heat[i - 1][j - 1] = new;
	if (j < e->map.width && e->map.heat[i][j + 1] < val)
		e->map.heat[i][j + 1] = new;
	if (j < e->map.width && i + 1 < e->map.height &&
			e->map.heat[i + 1][j + 1] < val)
		e->map.heat[i + 1][j + 1] = new;
	if (i - 1 >= 0 && e->map.heat[i - 1][j] < val)
		e->map.heat[i - 1][j] = new;
	if (i - 1 >= 0 && j - 1 >= 0 && e->map.heat[i - 1][j + 1] < val)
		e->map.heat[i - 1][j + 1] = new;
	if (i + 1 < e->map.height && e->map.heat[i + 1][j] < val)
		e->map.heat[i + 1][j] = new;
	if (i + 1 < e->map.height && i + 1 < e->map.width &&
			e->map.heat[i + 1][j - 1] < val)
		e->map.heat[i + 1][j - 1] = new;
}

static void	heatmap_update(t_env *e)
{
	int		i;
	int		j;
	int		heat;

	heat = e->heatmax;
	while (heat--)
	{
		i = -1;
		while (++i < e->map.height)
		{
			j = -1;
			while (++j < e->map.width)
				if (e->map.heat[i][j] >= 0)
					heatmap_update_populate(e, i, j, e->map.heat[i][j]);
		}
	}
}

void		update_map(t_env *e)
{
	char	*line;
	int		i;
	int		j;

	get_next_line(0, &line);
	ft_strdel(&line);
	i = 0;
	while (i < e->map.height)
	{
		get_next_line(0, &line);
		j = -1;
		while (++j < e->map.width)
		{
			if (line[4 + j] != '.')
				e->map.map[i][j] = (line[4 + j] == 'O' ? 1 : 2);
			e->map.heat[i][j] = (e->map.map[i][j] == e->foe) ? e->heatmax : 0;
		}
		ft_strdel(&line);
		i++;
	}
	heatmap_update(e);
}

void		free_maps(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->map.height)
	{
		free(e->map.map[i]);
		free(e->map.heat[i]);
	}
	free(e->map.map);
	free(e->map.heat);
}
