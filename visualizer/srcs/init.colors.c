/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.colors.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/29 18:35:32 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 18:36:09 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "general.h"

void			color_init_p1(t_env *e)
{
	e->player[0].color[0][0] = 0xf16a70;
	e->player[0].color[0][1] = 0xf05c63;
	e->player[0].color[0][2] = 0xee444d;
	e->player[0].color[0][3] = 0xeb2d37;
	e->player[0].color[1][0] = 0xf6cde6;
	e->player[0].color[1][1] = 0xf3bedf;
	e->player[0].color[1][2] = 0xefa9d4;
	e->player[0].color[1][3] = 0xeb93ca;
	e->player[0].color[2][0] = 0x375e97;
	e->player[0].color[2][1] = 0x2f5183;
	e->player[0].color[2][2] = 0x294570;
	e->player[0].color[2][3] = 0x223a5e;
	e->player[0].color[3][0] = 0xffd859;
	e->player[0].color[3][1] = 0xffd54d;
	e->player[0].color[3][2] = 0xffcf33;
	e->player[0].color[3][3] = 0xffc91a;
	e->player[0].color[4][0] = 0xff893a;
	e->player[0].color[4][1] = 0xff8533;
	e->player[0].color[4][2] = 0xff751a;
	e->player[0].color[4][3] = 0xff6600;
	e->player[0].color[5][0] = 0xe6e6e6;
	e->player[0].color[5][1] = 0xd9d9d9;
	e->player[0].color[5][2] = 0xcccccc;
	e->player[0].color[5][3] = 0xbfbfbf;
}

void			color_init_p2(t_env *e)
{
	e->player[1].color[0][0] = 0xb1d877;
	e->player[1].color[0][1] = 0xb0d775;
	e->player[1].color[0][2] = 0xa4d161;
	e->player[1].color[0][3] = 0x99cb4d;
	e->player[1].color[1][0] = 0xffe5bc;
	e->player[1].color[1][1] = 0xffe2b3;
	e->player[1].color[1][2] = 0xffd899;
	e->player[1].color[1][3] = 0xffce80;
	e->player[1].color[2][0] = 0xffbb00;
	e->player[1].color[2][1] = 0xe6a800;
	e->player[1].color[2][2] = 0xcc9600;
	e->player[1].color[2][3] = 0xb38300;
	e->player[1].color[3][0] = 0xb259ff;
	e->player[1].color[3][1] = 0xac4dff;
	e->player[1].color[3][2] = 0xa033ff;
	e->player[1].color[3][3] = 0x941aff;
	e->player[1].color[4][0] = 0x3a89ff;
	e->player[1].color[4][1] = 0x3385ff;
	e->player[1].color[4][2] = 0x1a75ff;
	e->player[1].color[4][3] = 0x0066ff;
	e->player[1].color[5][0] = 0x737373;
	e->player[1].color[5][1] = 0x666666;
	e->player[1].color[5][2] = 0x595959;
	e->player[1].color[5][3] = 0x4d4d4d;
}
