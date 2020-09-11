/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shields.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:24:22 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:25:31 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_shields(void)
{
	if ((clock() - g_plr.cl_regen) * 1000 / CLOCKS_PER_SEC > 900)
	{
		if (g_plr.iplr_shield < 27)
			g_plr.iplr_shield++;
		g_plr.cl_regen = clock();
	}
	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
	&g_tex.tex_shield[g_plr.iplr_shield], g_game.iscr_width05,\
	g_game.iscr_height - 40);
	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
	&g_tex.tex_armor[g_plr.iplr_armor], g_game.iscr_width05,\
	g_game.iscr_height - 40);
}
