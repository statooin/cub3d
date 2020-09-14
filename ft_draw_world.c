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

void		ft_cut_scene()
{
	static int	imsec;
	static int	img_x;
	static int	img_y;
	static int	iblack;

	if (imsec > 30000)
	{
		g_plr.iplay_cut_scene = 0;
		imsec = 0;
	}
	else
	{
		imsec = (clock() - clstart) * 1000 / CLOCKS_PER_SEC;
		g_plr.fplr_a = -1.5 + (1.5f * imsec / 30000);
		g_plr.iplr_z = 300 - (imsec * 300 / 30000);
		g_math.isky_x = g_plr.fplr_a  * 650;
		if (imsec < 28500)
			iblack = 10;
		else
			iblack += 2;
		img_x = 0;
		while (img_x++ < g_game.iscr_width_m1)
		{
			img_y = 0;
			while (img_y++ < g_game.iscr_height / iblack)
			{
				g_game.win_buf.data[img_y * g_game.iscr_width + img_x] = 0;
				g_game.win_buf.data[(g_game.iscr_height_m1 - img_y) * g_game.iscr_width + img_x] = 0;
			}
		}
	}


}

/*
void	ft_anim_ui(clock_t *clstart, int istart_x, int istart_y, int istop_x, int istop_y, int istop_msec)
{
	int imsec;

	if (imsec > istop_msec)
	{
		//g_plr.iplay_ui = 0;
		imsec = 0;
	}
	else
	{
		imsec = (clock() - clstart) * 1000 / CLOCKS_PER_SEC;
		ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
			&g_tex.tex_map_ui, g_game.iscr_width05, g_game.iscr_height05 + 100);
	}
}
*/

void	ft_draw_ui_map()
{
	ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
		&g_tex.tex_map_ui, g_game.iscr_width05, g_game.iscr_height05 + 100);
}

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

	//ft_key_actions();
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

	if (g_plr.iplay_cut_scene != 0)
	{
		ft_cut_scene();
	}
	else
	{
		ft_key_actions();
		if ((g_plr.uikeys_prsd & PRSD_H) != 0)
		{
			ft_draw_crosshair();
			ft_shields();
			if (g_math.ishot > 0)
				ft_player_shot();
			//ft_draw_weapon();
		}
		if ((g_plr.uikeys_prsd & PRSD_M) != 0)
			ft_draw_ui_map();
	}
	ft_draw_vignette();//&g_game.win_buf, &g_game);

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
