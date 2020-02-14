/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 12:08:29 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/26 17:44:09 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_gnl
{
	int				fd;
	char			*save;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(int fd, char **line);
#endif
