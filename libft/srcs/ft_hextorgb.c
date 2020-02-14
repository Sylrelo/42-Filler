/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hextorgb.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 18:59:22 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 19:04:09 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_color			ft_hexrgb(int value)
{
	t_color rgba;

	rgba.r = ((value >> 16) & 0xFF);
	rgba.g = ((value >> 8) & 0xFF);
	rgba.b = ((value) & 0xFF);
	rgba.a = 0;
	return (rgba);
}
