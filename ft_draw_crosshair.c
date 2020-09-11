/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_crosshair.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:00:04 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:46:38 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_crosshair(void)
{
	static int	iaim;

	if (g_math.ishot > 0 && iaim < 100)
		iaim += 30;
	if ((g_plr.uikeys_prsd & PRSD_UP_W) != 0 \
		|| (g_plr.uikeys_prsd & PRSD_DOWN_S) != 0 \
		|| (g_plr.uikeys_prsd & PRSD_A) != 0 \
		|| (g_plr.uikeys_prsd & PRSD_D) != 0)
	{
		if ((g_plr.uikeys_prsd & PRSD_SHIFT) != 0 && iaim < 100)
			iaim += 10;
		else if (iaim < 50)
			iaim += 5;
		else if ((g_plr.uikeys_prsd & PRSD_SHIFT) == 0 && iaim > 50)
			iaim -= 10;
	}
	else
		iaim -= 20;
	if (iaim < 20)
		iaim = 20;
	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
		&g_tex.tex_c_line, g_game.iscr_width05, g_game.iscr_height05 - iaim);
	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
		&g_tex.tex_c_line, g_game.iscr_width05, g_game.iscr_height05 + iaim);
	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
		&g_tex.tex_c_line_h, g_game.iscr_width05 - iaim, g_game.iscr_height05);
	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
		&g_tex.tex_c_line_h, g_game.iscr_width05 + iaim, g_game.iscr_height05);
}
