/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:12:20 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:12:48 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move_enemy_left(void)
{
	static int	i;
	static int	x;
	static int	y;

	ft_next_anim();
	i = 0;
	while (i < 30)
	{
		if (g_math.enemy[g_math.ienemy_n][i][0] == '+')
		{
			if (g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x - 1] == ' ')
			{
				y = 0;
				while (y < 30)
				{
					x = 0;
					while (x <= 9)
					{
						g_math.enemy[g_math.ienemy_n][y][29 - x] = g_math.enemy[g_math.ienemy_n][y][x];
						g_math.enemy[g_math.ienemy_n][y][x] = '-';
						x++;
					}
					g_math.enemy[g_math.ienemy_n][y][29] = g_math.enemy[g_math.ienemy_n][y][30];
					y++;
				}
				g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x] = ' ';
				g_enemies[g_math.ienemy_n].ienemy_x--;
				g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x] = g_math.ienemy_n + 'a';
			}
			return (1);
		}
		i++;
	}
	y = 0;
	while (y < 30)
	{
		x = 0;
		while (x < 30)
		{
			g_math.enemy[g_math.ienemy_n][y][x] = g_math.enemy[g_math.ienemy_n][y][x + 1];
			x++;
		}
		g_math.enemy[g_math.ienemy_n][y][29] = g_math.enemy[g_math.ienemy_n][y][30];
		y++;
	}
	return (1);
}
