/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_shot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:18:31 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:40:39 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_shot(void)
{
	//PRSD_LC
	//if (g_math.ishot > 0)
	//{
		ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, &g_tex.tex_muz_00, g_game.iscr_width05, g_game.iscr_height05);
		g_math.ishot--;
	//}
}
