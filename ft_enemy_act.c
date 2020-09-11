/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_act.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:47:56 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 19:48:47 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_enemy_act(void)
{
	g_math.ienemy_n = 0;
	while (g_math.ienemy_n < 3)
	{
		if ((clock() - g_enemies[g_math.ienemy_n].cl_move) \
		* 1000 / CLOCKS_PER_SEC > 100)
		{
			g_enemies[g_math.ienemy_n].cl_move = clock();
			ft_enemy_aim();
			ft_enemy_move();
		}
		g_math.ienemy_n++;
	}
}
