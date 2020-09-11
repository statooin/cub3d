/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:05:47 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:06:01 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_e(void) // es to 0s on the g_math.map -- SET A NEW TASK
{
	g_plr.hp_count = 1;
	if (g_math.map[(int)(g_plr.fplr_y + cosf(g_plr.fplr_a) * \
	0.6f)][(int)(g_plr.fplr_x + sinf(g_plr.fplr_a) * 0.6f)] == 'e')
	{
		g_math.map[(int)(g_plr.fplr_y + cosf(g_plr.fplr_a) * \
		0.6f)][(int)(g_plr.fplr_x + sinf(g_plr.fplr_a) * 0.6f)] = '0';
		g_plr.hp_count = g_plr.hp_count + 1;
		ft_draw_hp();
	}
}
