/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_skybox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:05:44 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:55:09 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_skybox(void)
{
	static int	tex_y;
	static int	tex_x;
	static int		img_x;
	static int		img_y;
	static int		tex_y_start;

	tex_y_start = 870 - g_game.iscr_height05 - g_plr.iplr_z;
	tex_x = 0 - g_math.isky_x;
	img_x = 0;
	while (img_x < g_game.iscr_width)
	{
		g_math.ibottom_sky[img_x] = g_math.ibottom_sky[img_x] + tex_y_start;
		if (g_math.ibottom_sky[img_x] > g_tex.tex_sky.height)
			g_math.ibottom_sky[img_x] = g_tex.tex_sky.height;
		tex_y = tex_y_start;
		img_y = 0;
		while (tex_y <= g_math.ibottom_sky[img_x])
		{
			g_game.win_buf.data[img_y * g_game.iscr_width + img_x] = g_tex.tex_sky.data[tex_y * g_tex.tex_sky.width + tex_x];
			tex_y++;
			img_y++;
		}
		tex_x++;
		img_x++;

	}
}
