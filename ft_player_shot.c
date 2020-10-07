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

void	ft_m8_reload(void)
{
	static int	pid;
	static int	ibullets;

	if (g_plr.iammo_full >= 0)
	{
		pid = fork();
		if (pid == 0)
		{
			system("mpg123 -q -f 22000 sound/m8_reload.mp3");
			exit(0);
		}

		ibullets = 45 - g_plr.iammo;
		if ((g_plr.iammo_full - ibullets) >= 0)
		{
			g_plr.iammo = 45;
			g_plr.iammo_full -= ibullets;
		}
		else
		{
			g_plr.iammo += g_plr.iammo_full;
			g_plr.iammo_full = 0;
		}
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			system("mpg123 -q -f 22000 sound/m8_empty.mp3");
			exit(0);
		}
	}
}

void	ft_player_shot(void)
{
	static int	pid;

	if (g_math.ishot > 0)
	{
		ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, &g_tex.tex_muz_00, g_game.iscr_width - 330, g_game.iscr_height - 210 - g_plr.igun_h);
		g_math.ishot--;
	}
	else
	{
		if (g_plr.iammo > 0)
		{
			pid = fork();
			if (pid == 0)
			{
				system("mpg123 -q -f 22000 sound/m8_burst.mp3");
				exit(0);
			}
			g_plr.iammo -= 3;
			g_math.ishot = 3;
			ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, &g_tex.tex_muz_00, g_game.iscr_width05, g_game.iscr_height05);
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				system("mpg123 -q -f 22000 sound/m8_empty.mp3");
				exit(0);
			}
			ft_m8_reload();
		}
	}
}
