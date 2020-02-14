/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dstrutils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 13:13:01 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 11:44:46 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_dstr_getindex(const char **haystack, const char *needle)
{
	int i;

	if (!haystack || !needle)
		return (-1);
	i = -1;
	while (haystack[++i])
		if (!(ft_strcmp(haystack[i], needle)))
			return (i);
	return (-1);
}

void	ft_dstr_free(char **str)
{
	int i;
	int j;

	if (!str)
		return ;
	i = ft_dstrlen((str));
	j = 0;
	while (j < i)
	{
		ft_strdel(&(str)[j]);
		j++;
	}
	free(str);
}

int		ft_dstr_del(char ***dest, char *todelete)
{
	int		i;
	int		nb;
	int		pos;
	char	**new;

	if (!todelete)
		return (0);
	if ((pos = ft_dstr_getindex((const char **)(*dest), todelete)) < 0)
		return (0);
	i = ft_dstrlen((*dest));
	new = malloc(sizeof(char *) * (i + 1));
	nb = 0;
	while (nb < i)
	{
		nb = ((nb == pos) ? nb + 1 : nb);
		if (!(new[nb - ((nb > pos) ? 1 : 0)] = ft_strdup((*dest)[nb])))
			return (0);
		nb++;
	}
	new[nb - ((nb > pos) ? 1 : 0)] = NULL;
	ft_dstr_free((*dest));
	(*dest) = new;
	return (1);
}
