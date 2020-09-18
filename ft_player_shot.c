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
	g_plr.iammo = 45;
}

void	ft_player_shot(void)
{
	static int	pid;

	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, &g_tex.tex_muz_00, g_game.iscr_width05, g_game.iscr_height05);
	if (g_plr.iammo > 0 && g_math.ishot == 3)
	{
		pid = fork();
		if (pid == 0)
		{
			system("mpg123 -q -f 22000 sound/m8_burst.mp3");
			exit(0);
		}
		g_plr.iammo -= 3;
	}
	else if (g_math.ishot == 3)
	{
		pid = fork();
		if (pid == 0)
		{
			system("mpg123 -q -f 22000 sound/m8_empty.mp3");
			system("mpg123 -q -f 22000 sound/m8_reload.mp3");
			exit(0);
		}
		ft_m8_reload();
	}
		g_math.ishot--;
}
