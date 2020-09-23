/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:36:31 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:48:15 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_floor(void)
{
	static int		y;
	static int		ihit_floor;
	static float	fray_ang;
	static float	ffloor_tilex;
	static float	ffloor_tiley;
	static int		idraw_y;
	static float	fsinf_a;
	static float	fcosf_a;
	static int		t_w;
	static int		t_h;

	g_math.iray_x = 0;
	fray_ang = g_plr.fplr_a + g_consts.ffov05;
	while (g_math.iray_x < g_game.iscr_width)
	{
		fsinf_a = sinf(fray_ang);
		fcosf_a = cosf(fray_ang);
		idraw_y = g_game.iscr_height_m1 + g_game.iscr_height05;// - g_plr.iplr_z;
		//idraw_y = g_game.iscr_height_m1;
		while (idraw_y > g_game.iscr_height05)
		{
			ffloor_tilex = g_plr.fplr_x - fsinf_a * g_math.fdist_to_all_tiles[idraw_y][g_math.iray_x];
			ffloor_tiley = g_plr.fplr_y - fcosf_a * g_math.fdist_to_all_tiles[idraw_y][g_math.iray_x];
			ihit_floor = g_math.map_floor[(int)ffloor_tiley][(int)ffloor_tilex] - '0';
			if (ihit_floor < 0)
				break;
			else if (idraw_y + g_plr.iplr_z < g_game.iscr_height)
			{
				y = idraw_y + g_plr.iplr_z;
				t_w = (ffloor_tilex - (int)ffloor_tilex) * g_tex.tex_floor[ihit_floor].width; //fastest!
				t_h = (ffloor_tiley - (int)ffloor_tiley) * g_tex.tex_floor[ihit_floor].height;
				g_game.win_buf.data[y * g_game.iscr_width + g_math.iray_x] = ft_shades(&g_tex.tex_floor[ihit_floor].data[t_h * g_tex.tex_floor[ihit_floor].width + t_w], &g_math.fdist_to_all_tiles[idraw_y][g_math.iray_x]);

				//y = g_game.iscr_height - y; ///!!! ceeling!!!
				//g_game.win_buf.data[y * g_game.iscr_width + g_math.iray_x] = ft_shades(&g_tex.tex_floor[ihit_floor].data[t_h * g_tex.tex_floor[ihit_floor].width + t_w], &g_math.fdist_to_all_tiles[idraw_y][g_math.iray_x]);
			}
			idraw_y--; //make adaptive
		}
		fray_ang = fray_ang - g_consts.fray_ang_step;
		g_math.iray_x++;
	}
}
