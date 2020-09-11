/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_scaled_img_lt_to_win.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:19:39 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:20:47 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_scaled_img_lt_to_win(t_img_n_tex *win_buf, t_game *g_game, t_img_n_tex *tex_01, int img_x_start, int img_y_start)
{
	static float	tex_y;
	static float	tex_x;
	static int		img_x_end;
	static int		img_y_end; //from center!!!
	static int		img_x; //from center!!!
	static int		img_y;
	static int		img_color;

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
					if (img_color > 0)
	//*(unsigned int*)(g_game.win_buf.addr +(y * g_game.win_buf.size_line + x * data->bpp_8)) = color;
						ft_mlx_pixel_put(win_buf, &img_x, &img_y, &img_color);
				}
				tex_x = tex_x + tex_01->step;
				img_x++;
			}
		}
		tex_y = tex_y + tex_01->step;
		img_y++;
	}
}
