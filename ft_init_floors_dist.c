/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_floors_dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:01:21 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:02:50 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_floors_dist(void)
{
	static float	ffloor_ang;
	static int		idraw_y;

	g_math.fdist_to_all_tiles = malloc(sizeof(float*) * g_game.iscr_height);
	idraw_y = g_game.iscr_height05;
	while (idraw_y <= g_game.iscr_height)
	{
		g_math.fdist_to_all_tiles[idraw_y] = \
		malloc(sizeof(float) * g_game.iscr_width);
		idraw_y++;
	}
	g_math.iray_x = 0;
	while (g_math.iray_x < g_game.iscr_width)
	{
		ffloor_ang = g_consts.ffloor_ang0;
		idraw_y = g_game.iscr_height - 1;
		while (idraw_y > g_game.iscr_height05)
		{
			g_math.fdist_to_all_tiles[idraw_y][g_math.iray_x] = tanf(ffloor_ang) * g_plr.fplr_zhead / cosf(g_consts.ffov05 - g_consts.fray_ang_step * g_math.iray_x);
			ffloor_ang = ffloor_ang + g_consts.ffloor_ang_step;
			idraw_y--;
		}
		g_math.iray_x++;
	}
	return (1);
}
