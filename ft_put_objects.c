/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:19:25 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:19:26 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_put_objects(int y, int x0)
{
	int	x;

	while (y >=0)
	{
		x = x0;
		while (x >= 0)
		{
			if (g_math.map[y][x] == 'N')
			{
				g_plr.fplr_x = x + 1.1f;//8.0f; // player's position on X
				g_plr.fplr_y = y + 0.4f;//23.0f; // player's position on Y
				g_plr.fplr_a = 0.0f; // player's VIEW angle (the dorection of rays to visible walls)
				g_math.map[y][x] = ' ';
			}
			if (g_math.map[y][x] == 'S')
			{
				g_plr.fplr_x = x;//8.0f; // player's position on X
				g_plr.fplr_y = y;//23.0f; // player's position on Y
				g_plr.fplr_a = 3.1f; // player's VIEW angle (the dorection of rays to visible walls)
				g_math.map[y][x] = ' ';
			}
			else if (g_math.map[y][x] >= 'a' && g_math.map[y][x] < 's')
			{
				g_math.ienemies_active = 1;
				g_enemies[g_math.map[y][x] - 'a'].ienemy_y = y;
				g_enemies[g_math.map[y][x] - 'a'].ienemy_x = x;
			}
			x--;
		}
		y--;
	}
}
