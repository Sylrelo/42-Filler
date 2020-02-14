/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   piece.utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/26 13:58:09 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 12:21:06 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

static void	get_piece_size(t_env *e, char *line)
{
	int i;

	i = 6;
	e->piece.height = 0;
	e->piece.width = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			e->piece.height = e->piece.height * 10 + (line[i] - '0');
		if (line[i] == ' ')
			break ;
		i++;
	}
	while (line[++i])
		if (ft_isdigit(line[i]))
			e->piece.width = e->piece.width * 10 + (line[i] - '0');
	e->piece.ce = -1;
	e->piece.cs = -1;
	e->piece.ls = -1;
	e->piece.le = -1;
}

void		piece_cols(t_env *e)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (++i < e->piece.width && e->piece.cs == -1)
	{
		j = -1;
		while (++j < e->piece.height && e->piece.cs == -1)
			if (e->piece.token[j][i])
				e->piece.cs = k;
		++k;
	}
	k = 0;
	i = e->piece.width;
	while (--i >= 0 && e->piece.ce == -1)
	{
		j = e->piece.height;
		while (--j >= 0 && e->piece.ce == -1)
			if (e->piece.token[j][i])
				e->piece.ce = k;
		++k;
	}
}

void		piece_lines(t_env *e)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (++i < e->piece.height && e->piece.ls == -1)
	{
		j = -1;
		while (++j < e->piece.width && e->piece.ls == -1)
			if (e->piece.token[i][j])
				e->piece.ls = k;
		++k;
	}
	k = 0;
	i = e->piece.height;
	while (--i >= 0 && e->piece.le == -1)
	{
		j = e->piece.width;
		while (--j >= 0 && e->piece.le == -1)
			if (e->piece.token[i][j])
				e->piece.le = k;
		++k;
	}
}

void		get_piece(t_env *e)
{
	int		i;
	int		j;
	char	*line;

	get_next_line(0, &line);
	get_piece_size(e, line);
	ft_strdel(&line);
	e->piece.token = malloc(sizeof(int *) * (e->piece.height));
	i = 0;
	while (i < e->piece.height)
	{
		e->piece.token[i] = malloc(sizeof(int) * (e->piece.width));
		j = -1;
		get_next_line(0, &line);
		while (++j < e->piece.width)
			e->piece.token[i][j] = ((line[j] == '.') ? 0 : 1);
		ft_strdel(&line);
		i++;
	}
	piece_cols(e);
	piece_lines(e);
	e->piece.real_height = e->piece.height - e->piece.ls - e->piece.le;
	e->piece.real_width = e->piece.width - e->piece.cs - e->piece.ce;
}

void		free_piece(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->piece.height)
		free(e->piece.token[i]);
	free(e->piece.token);
	e->piece.height = 0;
	e->piece.width = 0;
}
