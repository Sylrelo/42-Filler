/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 10:47:13 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:50:22 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "general.h"

short int		init_maps(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	if (!(e->map.map = malloc(sizeof(int *) * e->map.height)))
		return (0);
	while (++i < e->map.height)
	{
		if (!(e->map.map[i] = malloc(sizeof(int) * e->map.width)))
			return (0);
		j = -1;
		while (++j < e->map.width)
			e->map.map[i][j] = 0;
	}
	return (1);
}

static void		parse_players(t_env *e, char *line)
{
	char		*name;

	get_next_line(0, &line);
	if (!ft_strncmp("launched", line, 8))
	{
		name = ft_strrchr(line, '/') + 1;
		e->player[0].name = ft_strdup(name);
		ft_strdel(&line);
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	else
		exit(0);
	get_next_line(0, &line);
	if (!ft_strncmp("launched", line, 8))
	{
		name = ft_strrchr(line, '/') + 1;
		e->player[1].name = ft_strdup(name);
		ft_strdel(&line);
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	else
		exit(0);
}

void			get_players_and_map(t_env *e)
{
	char		*line;
	int			i;
	char		**split;

	e->map.height = 0;
	e->map.width = 0;
	i = -1;
	while (++i < 5)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	parse_players(e, line);
	get_next_line(0, &line);
	if (!(ft_strncmp("Plateau", line, 7)))
	{
		if (!(split = ft_strsplit(line, ' ')))
			exit(0);
		e->map.height = ft_atoi(split[1]);
		e->map.width = ft_atoi(split[2]);
		ft_splitdel(&split);
		ft_strdel(&line);
	}
	else
		exit(0);
}

void			free_maps(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->map.height)
		free(e->map.map[i]);
	free(e->map.map);
}
