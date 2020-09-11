/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall_stripe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:12:21 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 15:30:43 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_wall_stripe(float *fray_ang, int *itest_x, int *ihit_wall, float *fdist_to_wall, float *ftest_x, float *ftest_y)
{
	static int	idraw_y;
	static int	iceeling_y;
	static int ifloor_y;
	static float fcount_h;
	static int icount_w;
	static float ftex_hstep;
	static int	ipixel_color;

	iceeling_y = g_game.iscr_height05 - g_game.iscr_height / (*fdist_to_wall * cosf(*fray_ang - g_plr.fplr_a));
	ifloor_y = g_game.iscr_height - iceeling_y;
	iceeling_y = iceeling_y + iceeling_y - ifloor_y + g_plr.iplr_z; // x4 higher ceeling
	ifloor_y += g_plr.iplr_z;
	ftex_hstep = (float)g_tex.tex_wall[*ihit_wall].height / (ifloor_y - iceeling_y);


	if (iceeling_y <= g_math.ibottom_sky[g_math.iray_x]) ///!!!
	{
		if (iceeling_y < 0)
			iceeling_y = 0;
		fcount_h = g_tex.tex_wall[*ihit_wall].height;
		if (ifloor_y > g_math.ibottom_sky[g_math.iray_x])//g_game.iscr_height)
		{
			fcount_h -= ftex_hstep * (ifloor_y - g_math.ibottom_sky[g_math.iray_x]); ///!!!
			ifloor_y = g_math.ibottom_sky[g_math.iray_x]; //checked for branchless
		}

		if ((*ftest_x - g_consts.fstep_check) > (*itest_x) && (*ftest_x + g_consts.fstep_check) < (*itest_x + 1))
		//	icount_w = (int)(*ftest_x * g_tex.tex_wall[*ihit_wall].width) % g_tex.tex_wall[*ihit_wall].width; //!!! re do this !!!
			icount_w = (*ftest_x - (int)*ftest_x) * g_tex.tex_wall[*ihit_wall].width; //!!! fastest
		//	icount_w = fmodf(*ftest_x, 1) * g_tex.tex_wall[*ihit_wall].width; //!!! re do this !!!
		else
		//	icount_w = (int)(*ftest_y * g_tex.tex_wall[*ihit_wall].width) % g_tex.tex_wall[*ihit_wall].width; //!!! re do this !!!
			icount_w = (*ftest_y - (int)*ftest_y) * g_tex.tex_wall[*ihit_wall].width; //!!! fastest
		//	icount_w = fmodf(*ftest_y, 1) * g_tex.tex_wall[*ihit_wall].width; //!!! re do this !!!

		idraw_y = ifloor_y;//g_game.iscr_height05 + g_plr.iplr_z; ///!!!
		while (idraw_y >= iceeling_y)
		{
			ipixel_color = g_tex.tex_wall[*ihit_wall].data[(int)fcount_h * g_tex.tex_wall[*ihit_wall].width + icount_w];
			//if (ipixel_color > 0 && ipixel_color < 0xFFFFFF)
			if (ipixel_color == 0)
				break;
			g_game.win_buf.data[idraw_y * g_game.iscr_width + g_math.iray_x] = ft_shades(&ipixel_color, fdist_to_wall);
			fcount_h -= ftex_hstep;
			idraw_y--;
		}
		g_math.ibottom_sky[g_math.iray_x] = idraw_y;
	}
}
