/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vignette.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:11:52 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:55:53 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_vignette()//t_img_n_tex *win_buf, t_game *g_game)
{
	static int	color_old;
	static int	img_x;
	static int	img_y;
	static int	oct_r;
	static int	oct_g;
	static int	oct_b;

/*
	img_y = 0;
	while (img_y < g_game.iscr_height)
	{
		img_x = 0;
		while (img_x < g_game.iscr_width)
		{
			if (g_math.fvignette[img_y][img_x] < 1)
			{
				color_old = win_buf.data[img_y * g_game.iscr_width + img_x];
				oct_r = (color_old >> 16) * g_math.fvignette[img_y][img_x];
				oct_g = (color_old >> 8 & 0xFF) * g_math.fvignette[img_y][img_x];
				oct_b = (color_old & 0xFF) * g_math.fvignette[img_y][img_x];
				vig_color = oct_r << 16 | oct_g << 8 | oct_b;
				ft_mlx_pixel_put(win_buf, &img_x, &img_y, &vig_color);
			}
			img_x++;
		}
		img_y++;
	}
*/
	static int	img_x_stop;
	img_x_stop = g_game.iscr_height05;
	img_y = 0;
	while (img_y < g_game.iscr_height05)
	{
		img_x = 0;
		while (img_x < img_x_stop)
		{
			if (g_math.fvignette[img_y][img_x] < 1)
			{
				color_old = g_game.win_buf.data[img_y * g_game.iscr_width + img_x];
				oct_r = (color_old >> 16) * g_math.fvignette[img_y][img_x];
				oct_g = (color_old >> 8 & 0xFF) * g_math.fvignette[img_y][img_x];
				oct_b = (color_old & 0xFF) * g_math.fvignette[img_y][img_x];
				g_game.win_buf.data[img_y * g_game.iscr_width + img_x] = oct_r << 16 | oct_g << 8 | oct_b;
			}
			img_x++;
		}
		img_y++;
		img_x_stop--;
	}

	img_x_stop = g_game.iscr_width - g_game.iscr_height05;
	img_y = 0;
	while (img_y < g_game.iscr_height05)
	{
		img_x = g_game.iscr_width_m1;
		while (img_x > img_x_stop)
		{
			if (g_math.fvignette[img_y][img_x] < 1)
			{
				color_old = g_game.win_buf.data[img_y * g_game.iscr_width + img_x];
				oct_r = (color_old >> 16) * g_math.fvignette[img_y][img_x];
				oct_g = (color_old >> 8 & 0xFF) * g_math.fvignette[img_y][img_x];
				oct_b = (color_old & 0xFF) * g_math.fvignette[img_y][img_x];
				g_game.win_buf.data[img_y * g_game.iscr_width + img_x] = oct_r << 16 | oct_g << 8 | oct_b;
			}
			img_x--;
		}
		img_y++;
		img_x_stop--;
	}

	img_x_stop = g_game.iscr_height05;
	img_y = g_game.iscr_height_m1;
	while (img_y > g_game.iscr_height05)
	{
		img_x = 0;
		while (img_x < img_x_stop)
		{
			if (g_math.fvignette[img_y][img_x] < 1)
			{
				color_old = g_game.win_buf.data[img_y * g_game.iscr_width + img_x];
				oct_r = (color_old >> 16) * g_math.fvignette[img_y][img_x];
				oct_g = (color_old >> 8 & 0xFF) * g_math.fvignette[img_y][img_x];
				oct_b = (color_old & 0xFF) * g_math.fvignette[img_y][img_x];
				g_game.win_buf.data[img_y * g_game.iscr_width + img_x] = oct_r << 16 | oct_g << 8 | oct_b;
			}
			img_x++;
		}
		img_y--;
		img_x_stop--;
	}

	img_x_stop = g_game.iscr_width - g_game.iscr_height05;
	img_y = g_game.iscr_height_m1;
	while (img_y > g_game.iscr_height05)
	{
		img_x = g_game.iscr_width_m1;
		while (img_x > img_x_stop)
		{
			if (g_math.fvignette[img_y][img_x] < 1)
			{
				color_old = g_game.win_buf.data[img_y * g_game.iscr_width + img_x];
				oct_r = (color_old >> 16) * g_math.fvignette[img_y][img_x];
				oct_g = (color_old >> 8 & 0xFF) * g_math.fvignette[img_y][img_x];
				oct_b = (color_old & 0xFF) * g_math.fvignette[img_y][img_x];
				g_game.win_buf.data[img_y * g_game.iscr_width + img_x] = oct_r << 16 | oct_g << 8 | oct_b;
			}
			img_x--;
		}
		img_y--;
		img_x_stop--;
	}


}
