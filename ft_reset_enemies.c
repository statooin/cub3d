/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_enemies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:23:36 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:23:37 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_reset_enemies(void)
{
	//static int	i;

	//i = 0;
	//while (i < 3)
	if (g_enemies[0].ihealth <= 0 && g_enemies[1].ihealth <= 0 && g_enemies[2].ihealth <= 0)
		g_math.ienemies_active = 0;
	g_enemies[0].ifirst_rayx = -401;
	g_enemies[1].ifirst_rayx = -401;
	g_enemies[2].ifirst_rayx = -401;
}
