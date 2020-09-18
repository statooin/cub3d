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
			while (img_y < g_game.iscr_height / iblack)
			{
				g_game.win_buf.data[img_y * g_game.iscr_width + img_x] = 0;
				g_game.win_buf.data[(g_game.iscr_height_m1 - img_y) * g_game.iscr_width + img_x] = 0;
				img_y++;
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

void	ft_ui_move()
{
	static int	imsec;
	static int	x;
	static int	y;

	if (imsec > g_ui_anim.istop_msec)
	{
		ft_put_scaled_opac_img_to_win (&g_game.win_buf, &g_game, \
			g_ui_anim.tex_anim , x, y);
		imsec = 0;
		g_ui_anim.ianim = 0;
		g_ui_anim.uishown |= SHOWN_MAP;
	}
	else
	{
		if ((imsec = (clock() - g_ui_anim.clstart) * 1000 / CLOCKS_PER_SEC) > g_ui_anim.istop_msec)
			imsec = g_ui_anim.istop_msec;
		x = g_ui_anim.istart_x + (g_ui_anim.istop_x - g_ui_anim.istart_x) * imsec / g_ui_anim.istop_msec;
		y = g_ui_anim.istart_y + (g_ui_anim.istop_y - g_ui_anim.istart_y) * imsec / g_ui_anim.istop_msec;
		g_ui_anim.tex_anim->opacity = g_ui_anim.fstart_opac + (g_ui_anim.fstop_opac - g_ui_anim.fstart_opac) * imsec / g_ui_anim.istop_msec;
		g_ui_anim.tex_anim->scale = g_ui_anim.fstart_scale + (g_ui_anim.fstop_scale - g_ui_anim.fstart_scale) * imsec / g_ui_anim.istop_msec;
		g_ui_anim.tex_anim->step = 1 / g_ui_anim.tex_anim->scale;
		if (g_ui_anim.tex_anim->opacity < 1)
			ft_put_scaled_opac_img_to_win(&g_game.win_buf, &g_game, \
				g_ui_anim.tex_anim , x, y);
		else
			ft_put_scaled_img_to_win(&g_game.win_buf, &g_game, \
				g_ui_anim.tex_anim , x, y);
	}
}


void	ft_ui_move_lt()
{
	static int	imsec;
	static int	x;
	static int	y;

	if (imsec >= g_ui_anim.istop_msec)
	{
		if (g_ui_anim.tex_anim->opacity < 1)
			ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
				g_ui_anim.tex_anim , x, y);
		else
			ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, \
				g_ui_anim.tex_anim , x, y);
		imsec = 0;
		g_ui_anim.ianim = 0;
		g_ui_anim.uishown |= SHOWN_MAP;
	}
	else
	{
		if ((imsec = (clock() - g_ui_anim.clstart) * 1000 / CLOCKS_PER_SEC) > g_ui_anim.istop_msec)
			imsec = g_ui_anim.istop_msec;
		x = g_ui_anim.istart_x + (g_ui_anim.istop_x - g_ui_anim.istart_x) * imsec / g_ui_anim.istop_msec;
		y = g_ui_anim.istart_y + (g_ui_anim.istop_y - g_ui_anim.istart_y) * imsec / g_ui_anim.istop_msec;
		g_ui_anim.tex_anim->opacity = g_ui_anim.fstart_opac + (g_ui_anim.fstop_opac - g_ui_anim.fstart_opac) * imsec / g_ui_anim.istop_msec;
		g_ui_anim.tex_anim->scale = g_ui_anim.fstart_scale + (g_ui_anim.fstop_scale - g_ui_anim.fstart_scale) * imsec / g_ui_anim.istop_msec;
		g_ui_anim.tex_anim->step = 1 / g_ui_anim.tex_anim->scale;
		if (g_ui_anim.tex_anim->opacity < 1)
			ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
				g_ui_anim.tex_anim , x, y);
		else
			ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, \
				g_ui_anim.tex_anim , x, y);
	}
}

void	ft_show_ui_map_pl()
{
	static int	idir;
	static int	ix;
	static int	iy;

	idir = (int)(g_plr.fplr_a / PI2 * 8) % 8;
	//printf("idir = %d\n", idir);
	idir = (idir >= 0) ? idir : 8 + idir;
	//printf("idir = %d\n", idir);
ix = g_game.iscr_width05 / 3 + (float)g_tex.tex_map_ui.width * g_plr.fplr_x / g_math.imap_w;
iy = g_game.iscr_height05 / 3 + (float)g_tex.tex_map_ui.height * g_plr.fplr_y / g_math.imap_h;


		ft_put_scaled_img_to_win(&g_game.win_buf, &g_game, \
			&g_tex.tex_arr[idir], ix, iy);
}

void	ft_show_ui_map()
{
	if ((g_ui_anim.uishown & SHOWN_MAP) == 0 && g_ui_anim.ianim == 0)//g_ui_anim.ianim == 0)
	{
		g_ui_anim.clstart = clock();
		g_ui_anim.istart_x = g_game.iscr_width05;
		g_ui_anim.istop_x = g_game.iscr_width05 / 3;
		g_ui_anim.istart_y = g_game.iscr_height05 * 1.5;
		g_ui_anim.istop_y = g_game.iscr_height05 / 3;
		g_ui_anim.istop_msec = 100;
		g_ui_anim.fstart_scale = 0.1;
		g_ui_anim.fstop_scale = 1.0; ///!!! re do this
		g_ui_anim.fstart_opac = 0.1;
		g_ui_anim.fstop_opac = 0.9;
		g_ui_anim.ianim = 1;
		g_ui_anim.tex_anim = &g_tex.tex_map_ui;
		ft_ui_move_lt();
	}
	else if ((g_ui_anim.uishown & SHOWN_MAP) == 0 && g_ui_anim.ianim == 1)//&& g_ui_anim.ianim == 1)
		ft_ui_move_lt();
	else if ((g_ui_anim.uishown & SHOWN_MAP) != 0)
	{
		ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
			&g_tex.tex_map_ui, g_game.iscr_width05 / 3, g_game.iscr_height05 / 3);
		ft_show_ui_map_pl();
	}
}


int	ft_draw_world(void)
{
	static int buf_num;

	static int	itime;
	itime++;
	if ((clock() - fps) * 1000 / CLOCKS_PER_SEC > 10000)
	{
		ft_fps(itime);
		fps = clock();
		itime = 0;
	}

	ft_draw_floor();
	//ft_draw_simple_color_floor();
	if (g_math.ienemies_active == 1 && g_plr.iplay_cut_scene == 0)
	{
		ft_enemy_move();
		ft_reset_enemies();
		ft_left_enemies_prescan();
		//ft_enemy_act();
	}

	ft_draw_walls();
	//ft_draw_simple_color_sky();
	ft_draw_skybox();
	if (g_math.ienemies_active == 1)
		ft_enemy_aim();
	//ft_draw_hp(1);

	if (g_plr.iplay_cut_scene != 0)
	{
		ft_cut_scene();
	}
	else
	{
		ft_key_actions();
		if ((g_plr.uikeys_prsd & PRSD_M) != 0)
		{
			//ft_show_left_hand();
			ft_show_ui_map();
		}
		if ((g_plr.uikeys_prsd & PRSD_M) != 0 && (g_plr.uikeys_prsd & PRSD_H) != 0)
		{
			ft_shields();
		}
		else if ((g_plr.uikeys_prsd & PRSD_M) == 0 && (g_plr.uikeys_prsd & PRSD_H) != 0)
		{
			ft_draw_crosshair();
			ft_shields();
			if (g_math.ishot > 0)
				ft_player_shot();
			//ft_draw_weapon();
		}
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
