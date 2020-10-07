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

void		ft_cut_scene_1()
{
	static int	imsec;
	static int	img_x;
	static int	img_y;
	static int	iblack;

	if (imsec > 30000)
	{
		g_plr.iplay_cut_scene = 0;
		imsec = 0;
		g_enemies[0].ienemy_width = 2; // / (8 / 3.2);
		g_enemies[0].fenemy_tall = 1.2f; //  * (8 / 3.2)
		g_enemies[0].ienemy_top = 0.2f;
		g_enemies[0].en_anim_i = 0;
		g_math.map[23][8] = ' ';
		g_math.map[23][7] = ' ';
		g_enemies[0].ihealth = 0;
	}
	else
	{
		imsec = (clock() - clstart) * 1000 / CLOCKS_PER_SEC;
		if (imsec < 28800)
		{
			g_plr.fplr_a = -1.3 + (1.3f * (float)imsec / 30000);
			g_math.isky_x = g_plr.fplr_a  * 650;
			g_plr.iplr_z = 300 - ((float)imsec * 300 / 30000);
		}
		if (imsec > 20000 && imsec < 28800)
			g_plr.fplr_y = g_plr.fplr_y - 0.039f * ((float)(imsec - 20000) / 10000);
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
		g_ui_anim.istart_y = g_game.iscr_height05 * 1.5f;
		g_ui_anim.istop_y = g_game.iscr_height05 / 3;
		g_ui_anim.istop_msec = 100;
		g_ui_anim.fstart_scale = 0.1f;
		g_ui_anim.fstop_scale = 1.0; ///!!! re do this
		g_ui_anim.fstart_opac = 0.1f;
		g_ui_anim.fstop_opac = 0.9f;
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
	if (g_math.ienemies_active == 1)// && g_plr.iplay_cut_scene == 0)
	{
		//ft_enemy_move();
		ft_reset_enemies();
		ft_left_enemies_prescan();
	}

	ft_draw_walls();
	//ft_draw_simple_color_sky();
	ft_draw_skybox();
	if (g_math.ienemies_active == 1 && g_plr.iplay_cut_scene == 0)
	{
		ft_enemy_aim();
		ft_enemy_move();
	}
	//ft_draw_hp(1);

	if (g_plr.iplay_cut_scene != 0)
	{
		ft_cut_scene_1();
	}
	else
	{
		ft_key_actions();
		if ((g_plr.uikeys_prsd & PRSD_M) != 0)
		{
			//ft_show_left_hand();
			ft_show_ui_map();
		}
		else if ((g_plr.uikeys_prsd & PRSD_M) == 0 && (g_plr.uikeys_prsd & PRSD_H) != 0)
		{
			ft_draw_crosshair();
			if (g_math.ishot > 0)
				ft_player_shot();
			//ft_draw_weapon();
		}
		if ((g_plr.uikeys_prsd & PRSD_H) != 0)
		{
			ft_shields();

			ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, \
				&g_tex.tex_gun, g_game.iscr_width - 380, g_game.iscr_height - 210 - g_plr.igun_h); //tex_gun

			ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
				&g_tex.tex_gun_ui, 20, g_game.iscr_height - 110); //tex_gun_ui

			ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
				&g_tex.tex_digits[g_plr.iammo_full / 100], 114, g_game.iscr_height - 60); //tex_gun_ui
			ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
				&g_tex.tex_digits[g_plr.iammo_full % 100 / 10], 134, g_game.iscr_height - 60); //tex_gun_ui
			ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
				&g_tex.tex_digits[g_plr.iammo_full % 10], 154, g_game.iscr_height - 60); //tex_gun_ui

			ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
				&g_tex.tex_digits[g_plr.iammo / 10], 34, g_game.iscr_height - 42); //tex_gun_ui
			ft_put_scaled_opac_img_lt_to_win(&g_game.win_buf, &g_game, \
				&g_tex.tex_digits[g_plr.iammo % 10], 54, g_game.iscr_height - 42); //tex_gun_ui
//g_plr.iammo_full

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
