/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_aim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:49:11 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 19:50:35 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_enemy_aim(void)
{
	static float	fstep_x;
	static float	fstep_y;
	static float	fshot_x;
	static float	fshot_y;

	g_math.ienemy_n = 0;
	while (g_math.ienemy_n < 3)
	{
		if ((clock() - g_enemies[g_math.ienemy_n].cl_shoot) * 1000 / CLOCKS_PER_SEC > 300)
		{
			g_enemies[g_math.ienemy_n].cl_shoot = clock();
			fshot_x = (float)g_enemies[g_math.ienemy_n].ienemy_x;
			fshot_y = (float)g_enemies[g_math.ienemy_n].ienemy_y;
			fstep_y = (g_plr.fplr_y - (float)g_enemies[g_math.ienemy_n].ienemy_y + 0.5) / 30;
			fstep_x = (g_plr.fplr_x - (float)g_enemies[g_math.ienemy_n].ienemy_x + 0.5) / 30;
			while ((int)fshot_x != (int)g_plr.fplr_x && (int)fshot_y != (int)g_plr.fplr_y)
			{
				if (g_math.map[(int)fshot_y][(int)fshot_x] > ' ' && g_math.map[(int)fshot_y][(int)fshot_x] < 'a')
				{
					return (0);
				}
				fshot_x += fstep_y;
				fshot_y += fstep_x;
			}
			//if (iGot == 1)
			//{
			if (g_enemies[g_math.ienemy_n].iaimed < 2)
				g_enemies[g_math.ienemy_n].iaimed++;
			else if (g_enemies[g_math.ienemy_n].iaimed == 2)
			{
				ft_enemy_shoot();
				g_enemies[g_math.ienemy_n].iaimed = 0;
			}
			//write(1, "got", 3);
			//}
		}
		g_math.ienemy_n++;
	}
	return (1);
}
