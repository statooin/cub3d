/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_enemies_prescan.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:07:29 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:07:30 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_left_enemies_prescan(void)
{
	static float	fray_ang;
	static int		itest_x;
	static int		itest_y;
	static float	fdist_to_wall;

	g_math.iray_x = -400;
	fray_ang = g_plr.fplr_a + g_consts.ffov05 - g_math.iray_x * g_consts.fray_ang_step;
	while (g_math.iray_x < 0)
	{
		fdist_to_wall = 0;
		g_math.ftest_x = g_plr.fplr_x;
		g_math.ftest_y = g_plr.fplr_y;
		itest_x = (int)(g_math.ftest_x);
		itest_y = (int)(g_math.ftest_y);
		g_consts.fsinf_ang_step = sinf(fray_ang) * 0.09f;
		g_consts.fcosf_ang_step = cosf(fray_ang) * 0.09f;
		while (g_math.map[itest_y][itest_x] != '#')
		{
			fdist_to_wall += 0.09f;
			g_math.ftest_x = g_math.ftest_x - g_consts.fsinf_ang_step;
			g_math.ftest_y = g_math.ftest_y - g_consts.fcosf_ang_step;
			itest_x = (int)(g_math.ftest_x);
			itest_y = (int)(g_math.ftest_y);
			if (g_math.map[itest_y][itest_x] >= 'a' && g_math.map[itest_y][itest_x] < 's')
			{
				g_math.ienemy_n = g_math.map[itest_y][itest_x] - 'a';
				ft_draw_enemy(&fdist_to_wall);
			}
		}
		g_math.iray_x++;
		fray_ang -= g_consts.fray_ang_step;
	}
}
