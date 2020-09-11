/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:44:51 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:42:44 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_draw_world(void)
{
	static int buf_num;
	//static int	i;

	static int	itime;
	itime++;
	if ((clock() - fps) * 1000 / CLOCKS_PER_SEC > 10000)
	{
		ft_fps(itime);
		fps = clock();
		itime = 0;
	}

	ft_key_actions();
	ft_draw_floor();
	//ft_draw_simple_color_floor();
	if (g_math.ienemies_active == 1)
	{
		ft_left_enemies_prescan();
		//ft_enemy_act();
		ft_enemy_move();
		ft_enemy_aim(); //!! re do this - flash will be not visible!!
	}

	ft_draw_walls();
	//ft_draw_simple_color_sky();
	ft_draw_skybox();
	//ft_draw_hp(1);

	if ((g_plr.uikeys_prsd & PRSD_H) != 0)
	{
		ft_draw_crosshair();
		ft_shields();
		if (g_math.ishot > 0)
			ft_player_shot();
		//ft_draw_weapon();
	}
	ft_draw_vignette(&g_game.win_buf, &g_game);

	if (buf_num == 0)
	{
		mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf0.ptr, 0, 0);
		g_game.win_buf.ptr = g_game.win_buf1.ptr;
		g_game.win_buf.addr = g_game.win_buf1.addr;
		g_game.win_buf.data = g_game.win_buf1.data;
		buf_num = 1;
	}
	else
	{
		mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf1.ptr, 0, 0);
		g_game.win_buf.ptr = g_game.win_buf0.ptr;
		g_game.win_buf.addr = g_game.win_buf0.addr;
		g_game.win_buf.data = g_game.win_buf0.data;
		buf_num = 0;
	}
	return (1);
}
