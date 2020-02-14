/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dstrutils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 19:15:55 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/06 11:42:04 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_dstrlen(char **str)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_printdstr(char **str)
{
	int i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		ft_putendl(str[i]);
}

int		ft_dstr_add(char ***dest, char *newvalue)
{
	int		i;
	int		nb;
	char	**new;

	if (!newvalue)
		return (0);
	i = ft_dstrlen((*dest));
	new = malloc(sizeof(char *) * (i + 2));
	nb = 0;
	while (nb < i)
	{
		if (!(new[nb] = ft_strdup((const char *)((*dest)[nb]))))
			return (0);
		nb++;
	}
	if (!(new[nb] = ft_strdup(newvalue)))
		return (0);
	new[nb + 1] = NULL;
	ft_dstr_free((*dest));
	(*dest) = new;
	return (1);
}

int		ft_cpy_dstr(char ***dest, char **src)
{
	int		i;
	int		nb;

	if (!src)
		return (0);
	i = ft_dstrlen(src);
	if (!((*dest) = malloc(sizeof(*dest) * (i + 1))))
		return (0);
	nb = 0;
	while (nb < i)
	{
		if (!((*dest)[nb] = ft_strdup((const char *)(src[nb]))))
			return (0);
		nb++;
	}
	(*dest)[nb] = NULL;
	return (1);
}
