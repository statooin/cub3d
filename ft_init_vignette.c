/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vignette.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:04:06 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:04:07 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_vignette(t_game *g_game, t_img_n_tex *tex_vign)
{
	static int	idraw_y;
	float		step_x;
	float		step_y;
	float		tex_y;
	float		tex_x;

	g_math.fvignette = malloc(sizeof(float*) * g_game->iscr_height);
	idraw_y = 0;
	while (idraw_y <= g_game->iscr_height)
	{
		g_math.fvignette[idraw_y] = malloc(sizeof(float) * g_game->iscr_width);
		idraw_y++;
	}
	step_x = (float)tex_vign->width / g_game->iscr_width;
	step_y = (float)tex_vign->height / g_game->iscr_height;
	tex_x = 0;
	g_math.iray_x = 0;
	while (g_math.iray_x < g_game->iscr_width)
	{
		tex_y = 0;
		idraw_y = 0;
		while (idraw_y < g_game->iscr_height)
		{
			g_math.fvignette[idraw_y][g_math.iray_x] = (float)(tex_vign->data[(int)tex_y * tex_vign->width + (int)tex_x] & 0xFF) / 0xAA; //0xFF
			tex_y = tex_y + step_y;
			idraw_y++;
		}
		tex_x = tex_x + step_x;
		g_math.iray_x++;
	}
	return (1);
}
