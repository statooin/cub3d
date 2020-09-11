/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_hp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:04:08 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:50:15 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_hp(void)
{
	static int	img_x_center;
	static int	img_y_center;

	img_x_center = g_game.iscr_width - (g_game.iscr_width / 7);
	img_y_center = g_game.iscr_height - (g_game.iscr_height * 0.92);
	g_tex.tex_hp[g_plr.hp_count].scale = g_tex.tex_hp[g_plr.hp_count].height;
	g_tex.tex_hp[g_plr.hp_count].scale /= 800;
	ft_put_scaled_img_to_win(&g_game.win_buf, \
	&g_game, &g_tex.tex_hp[1], img_x_center, img_y_center);
	ft_put_scaled_img_to_win(&g_game.win_buf, \
	&g_game, &g_tex.tex_hp[1], img_x_center, img_y_center);
}
