/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_shoot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:55:50 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 19:56:22 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_enemy_shoot(void)
{
	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
	&g_tex.tex_muz_00, g_game.iscr_width05, g_game.iscr_height05); // / 2.1
	if (g_plr.iplr_shield > 0)
		g_plr.iplr_shield--;
	else if (g_plr.iplr_armor > 0)
		g_plr.iplr_armor--;
	//else gg :)
}
