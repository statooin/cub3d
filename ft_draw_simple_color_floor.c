/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_simple_color_floor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:49:57 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:54:05 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_simple_color_floor(void)
{
	static int	x;
	static int	idraw_y;

	x = 0;
	while (x < g_game.iscr_width)
	{
		idraw_y = g_game.iscr_height_m1;
		while (idraw_y >= 0)
		{
			g_game.win_buf.data[idraw_y * g_game.iscr_width + x] = \
				g_game.ifloor_col;
			idraw_y--;
		}
		x++;
	}
}
