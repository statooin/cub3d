/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:51:21 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 19:55:29 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_enemy_move(void)
{
	g_math.ienemy_n = 0;
	while (g_math.ienemy_n < 3)
	{
		if ((clock() - g_enemies[g_math.ienemy_n].cl_move) \
		* 1000 / CLOCKS_PER_SEC > 100)
		{
			g_enemies[g_math.ienemy_n].cl_move = clock();
			if (g_enemies[g_math.ienemy_n].ienemy_y + 1 < (int)g_plr.fplr_y)
				ft_move_enemy_down();
			else if (g_enemies[g_math.ienemy_n].ienemy_y \
			- 1 > (int)g_plr.fplr_y)
				ft_move_enemy_up();
			if (g_enemies[g_math.ienemy_n].ienemy_x - 1 > (int)g_plr.fplr_x)
				ft_move_enemy_left();
			else if (g_enemies[g_math.ienemy_n].ienemy_x \
			+ 1 < (int)g_plr.fplr_x)
				ft_move_enemy_right();
		}
		g_math.ienemy_n++;
	}
}
