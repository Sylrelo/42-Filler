/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isalpha.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:30:43 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:30:25 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isalpha(int c)
{
	if ((c < 97 || c > 122) && (c < 65 || c > 90))
		return (0);
	return (1);
}
