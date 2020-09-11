/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:12:57 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:13:23 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move_enemy_right(void)
{
	static int	i;
	static int	x;
	static int	y;

	ft_next_anim();
	i = 0;
	while (i < 30)
	{
		if (g_math.enemy[g_math.ienemy_n][i][29] == '+')
		{
			if (g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x + 1] == ' ')
			{
				y = 0;
				while (y < 30)
				{
					x = 0;
					while (x <= 9)
					{
						g_math.enemy[g_math.ienemy_n][y][x] = g_math.enemy[g_math.ienemy_n][y][29 - x];
						g_math.enemy[g_math.ienemy_n][y][29 - x] = '-';
						x++;
					}
					//g_math.enemy[29][y] = g_math.enemy[30][y];
					y++;
				}
				g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x] = ' ';
				g_enemies[g_math.ienemy_n].ienemy_x++;
				g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x] = g_math.ienemy_n + 'a';
			}
			return (1);
		}
		i++;
	}
	y = 0;
	while (y < 30)
	{
		x = 29;
		while (x > 0)
		{
			g_math.enemy[g_math.ienemy_n][y][x] = g_math.enemy[g_math.ienemy_n][y][x - 1];
			x--;
		}
		g_math.enemy[g_math.ienemy_n][y][0] = g_math.enemy[g_math.ienemy_n][y][30];
		y++;
	}
	return (1);
}
