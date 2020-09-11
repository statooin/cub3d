/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_scaled_opac_img_to_win.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:21:55 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:23:19 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_scaled_opac_img_to_win(t_img_n_tex *win_buf, t_game *g_game, t_img_n_tex *tex_01, int img_x_center, int img_y_center)
{
	static int		img_color;
	static int		color_old;
	static int		oct_bi;
	static int		oct_gi;
	static int		oct_ri;
	static int		img_x_start;
	static int		img_y_start;
	static int		img_x; //from center!!!
	static int		img_y;
	static int		img_x_end;
	static int		img_y_end; //from center!!!
	static float	tex_y;
	static float	tex_x;
	static int		oct_r;
	static int		oct_g;
	static int		oct_b;

	img_x_start = img_x_center - tex_01->width * tex_01->scale / 2;
	img_y_start = img_y_center - tex_01->height * tex_01->scale / 2;
	img_x_end = img_x_start + tex_01->width * tex_01->scale;
	img_y_end = img_y_start + tex_01->height * tex_01->scale; //from center!!!
	if (img_x_end >= g_game->iscr_width)
		img_x_end = g_game->iscr_width;
	if (img_y_end >= g_game->iscr_height)
		img_y_end = g_game->iscr_height;
	tex_y = 0;
	img_y = img_y_start;
	while (img_y < img_y_end)
	{
		if (img_y >= 0)
		{
			//if (img_y >= g_game->iscr_height)
			//	break;
			tex_x = 0;
			img_x = img_x_start;
			while (img_x < img_x_end)
			{
				if (img_x >= 0)
				{
					//if (img_x >= g_game->iscr_width)
					//	break;
					img_color = tex_01->data[(int)tex_y * tex_01->width + (int)tex_x];
					if (img_color > 0x030902 && img_color < 0xFFFFFF)
					{
						color_old = win_buf->data[img_y * g_game->iscr_width + img_x];
						oct_r = color_old >> 16 & 0xFF; //!!!!! re do all this in one line
						oct_g = color_old >> 8 & 0xFF;
						oct_b = color_old & 0xFF;
						oct_ri = img_color >> 16 & 0xFF; // разбиваем по октетам
						oct_gi = img_color >> 8 & 0xFF;
						oct_bi = img_color & 0xFF;
						oct_b = oct_b * tex_01->opacity_1 + oct_bi * tex_01->opacity; // меняем как хотим
						oct_g = oct_g * tex_01->opacity_1 + oct_gi * tex_01->opacity; // меняем как хотим
						oct_r = oct_r * tex_01->opacity_1 + oct_ri * tex_01->opacity; // меняем как хотим
						img_color = oct_r << 16 | oct_g << 8 | oct_b;
	//*(unsigned int*)(g_game.win_buf.addr +(y * g_game.win_buf.size_line + x * data->bpp_8)) = color;
						ft_mlx_pixel_put(win_buf, &img_x, &img_y, &img_color);
					}
				}
				tex_x = tex_x + tex_01->step;
				img_x++;
			}
		}
		tex_y = tex_y + tex_01->step;
		img_y++;
	}
}
