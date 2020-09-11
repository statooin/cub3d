/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_most_far_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:08:15 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:08:16 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_most_far_wall(float *fray_ang, int *ipriority)
{
	static float	fdist_to_wall;
//	static int	itype;
//	static int	i;
	static int		itest_x;
	static int		itest_y;
	static int		itest_xold;
	static int		itest_yold;

	ipriority[0] = 1;
//	i = 0;
//	itype = 0;
	// finding the most far wall 'W'
	fdist_to_wall = 0;
	g_math.ftest_x = g_plr.fplr_x;
	g_math.ftest_y = g_plr.fplr_y;
	itest_x = (int)(g_math.ftest_x);
	itest_y = (int)(g_math.ftest_y);
	g_consts.fsinf_ang_step = sinf(*fray_ang) * 0.4f; //!!pre calc this in array!!
	g_consts.fcosf_ang_step = cosf(*fray_ang) * 0.4f;
	while (g_math.map[itest_y][itest_x] != '#') //!!here check walls priority!
	{
		fdist_to_wall += 0.4f;
		g_math.ftest_x = g_math.ftest_x - g_consts.fsinf_ang_step;
		g_math.ftest_y = g_math.ftest_y - g_consts.fcosf_ang_step;
		itest_x = (int)(g_math.ftest_x);
		itest_y = (int)(g_math.ftest_y);
		if (g_math.map[itest_y][itest_x] != ' ')
		{
			if (itest_xold != itest_x && itest_yold != itest_y)
			{
			//	itype = g_math.map[itest_y][itest_x] - '0';
				itest_xold = itest_x;
				itest_yold = itest_y;
			}
		}
	}
	// now we know most far distance
	return (fdist_to_wall);
}
