/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:02:37 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 19:03:55 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_enemy(float *fdist_to_wall)
{
	static int		ienemy_stop;
	static int		x;
	static int		y;
	static float	fcount_h;
	static int		ipixel_color;

	x = (g_math.ftest_x - (int)g_math.ftest_x) * 30;
	y = (g_math.ftest_y - (int)g_math.ftest_y) * 30;

	if (g_math.enemy[g_math.ienemy_n][y][x] == '+')
	{
		if (g_enemies[g_math.ienemy_n].ifirst_rayx == -401)
		{
			g_enemies[g_math.ienemy_n].fe_count_w = 0;
			g_enemies[g_math.ienemy_n].fenemy_width = g_game.iscr_height / *fdist_to_wall / g_enemies[g_math.ienemy_n].ienemy_width; //
			g_enemies[g_math.ienemy_n].fenemy_stepw = g_tex.en_anim[0][g_enemies[g_math.ienemy_n].en_anim_i].width / g_enemies[g_math.ienemy_n].fenemy_width;
			g_enemies[g_math.ienemy_n].fenemy_h = g_game.iscr_height / *fdist_to_wall * g_enemies[g_math.ienemy_n].fenemy_tall;
			g_enemies[g_math.ienemy_n].fenemy_texh_step = (float)g_tex.en_anim[0][g_enemies[g_math.ienemy_n].en_anim_i].height / g_enemies[g_math.ienemy_n].fenemy_h;
		}
		if (g_math.iray_x > g_enemies[g_math.ienemy_n].ifirst_rayx)
		{
			g_enemies[g_math.ienemy_n].fe_count_w += g_enemies[g_math.ienemy_n].fenemy_stepw;

			if (g_math.iray_x >= 0)
			{
				fcount_h = g_tex.en_anim[0][g_enemies[g_math.ienemy_n].en_anim_i].height * g_enemies[g_math.ienemy_n].ienemy_top; // ???? need to be in struct
				y = g_game.iscr_height05 + g_plr.iplr_z; //
				if ((ienemy_stop = g_game.iscr_height05 - g_enemies[g_math.ienemy_n].fenemy_h * g_enemies[g_math.ienemy_n].ienemy_top + g_plr.iplr_z) < 0) //
					ienemy_stop = 0;


				while (y > ienemy_stop)
				{
					if (y < g_enemies[g_math.ienemy_n].isprite_y_start)
					{
						ipixel_color = g_tex.en_anim[0][g_enemies[g_math.ienemy_n].en_anim_i].data[(int)fcount_h * g_tex.en_anim[0][g_enemies[g_math.ienemy_n].en_anim_i].width + (int)g_enemies[g_math.ienemy_n].fe_count_w];
						//if (ipixel_color == 0)
						//	break;
						//else if (ipixel_color != 0xFFFFFF)
						if (ipixel_color > 100)
						{
							g_game.win_buf.data[y * g_game.iscr_width + g_math.iray_x] = ft_shades(&ipixel_color, fdist_to_wall);
							//g_math.ibottom_sky[g_math.iray_x] = y;
							if (g_math.ishot > 0 && y == g_game.iscr_height05 && g_math.iray_x == g_game.iscr_width05) ///!!!
								g_enemies[g_math.ienemy_n].ihealth -= 20; ///headshot
						}
					}
					fcount_h -= g_enemies[g_math.ienemy_n].fenemy_texh_step;
					y--;
				}
				//g_math.ibottom_sky[g_math.iray_x] = y;

				fcount_h = g_tex.en_anim[0][g_enemies[g_math.ienemy_n].en_anim_i].height * g_enemies[g_math.ienemy_n].ienemy_top; //
				y = g_game.iscr_height05 + g_plr.iplr_z; // how start from different eyes level height
				ienemy_stop = ienemy_stop + g_enemies[g_math.ienemy_n].fenemy_h;
				if (ienemy_stop > g_game.iscr_height)
					ienemy_stop = g_game.iscr_height;
				//if ((ienemy_stop = g_game.iscr_height05 + g_enemies[g_math.ienemy_n].fenemy_h * g_enemies[g_math.ienemy_n].ienemy_bottom + (int)g_plr.iplr_z) > g_game.iscr_height) //
				if (ienemy_stop > g_enemies[g_math.ienemy_n].isprite_y_start)
					ienemy_stop = g_enemies[g_math.ienemy_n].isprite_y_start;
				while (y < ienemy_stop)
				{
					ipixel_color = g_tex.en_anim[0][g_enemies[g_math.ienemy_n].en_anim_i].data[(int)fcount_h * g_tex.en_anim[0][g_enemies[g_math.ienemy_n].en_anim_i].width + (int)g_enemies[g_math.ienemy_n].fe_count_w];
					//if (ipixel_color == 0)
					//	break;
					/*else*/ if (ipixel_color > 100)//!= 0xFFFFFF)
					{
						g_game.win_buf.data[y * g_game.iscr_width + g_math.iray_x] = ft_shades(&ipixel_color, fdist_to_wall);
						if (g_math.ishot > 0 && y == g_game.iscr_height05 && g_math.iray_x == g_game.iscr_width05) ///!!!
							g_enemies[g_math.ienemy_n].ihealth -= 5; /// shot in body
					}
					fcount_h += g_enemies[g_math.ienemy_n].fenemy_texh_step;
					y++;
				}
			}
			g_enemies[g_math.ienemy_n].ifirst_rayx = g_math.iray_x;
		}
	}
}
