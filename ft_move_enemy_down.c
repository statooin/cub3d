/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:11:25 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:12:10 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move_enemy_down(void)
{
	static int	i;
	static int	y;

	ft_next_anim();
	i = 0;
	while (i < 30)
	{
		if (g_math.enemy[g_math.ienemy_n][29][i] == '+')
		{
			if (g_math.map[g_enemies[g_math.ienemy_n].ienemy_y + 1][g_enemies[g_math.ienemy_n].ienemy_x] == ' ')
			{
				y = 0;
				while (y <= 9)
				{
					g_math.enemy[g_math.ienemy_n][y] = g_math.enemy[g_math.ienemy_n][29 - y];
					g_math.enemy[g_math.ienemy_n][29 - y] = g_math.enemy[g_math.ienemy_n][30];
					y++;
				}
				g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x] = ' ';
				g_enemies[g_math.ienemy_n].ienemy_y++;
				g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x] = g_math.ienemy_n + 'a';
			}
			return (1);
		}
		i++;
	}
	y = 30;
	while (y > 0)
	{
		g_math.enemy[g_math.ienemy_n][y] = g_math.enemy[g_math.ienemy_n][y - 1];
		y--;
	}
	g_math.enemy[g_math.ienemy_n][0] = g_math.enemy[g_math.ienemy_n][30];
	return (1);
}
