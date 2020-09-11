/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_simple_color_sky.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:39:51 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:53:41 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_simple_color_sky(void)
{
	static int	x;
	static int	idraw_y;

	x = 0;
	while (x < g_game.iscr_width)
	{
		idraw_y = 0;
		while (idraw_y <= g_math.ibottom_sky[x])
		{
			g_game.win_buf.data[idraw_y * g_game.iscr_width + x] = \
				g_game.iceilling_col;
			idraw_y++;
		}
		x++;
	}
}
