/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_holster_weapon.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:58:53 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:42:44 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_holster_weapon(void)
{
	static int	pid;

	if ((g_plr.uikeys_prsd & PRSD_H) != 0)
	{
		pid = fork();
		if (pid == 0)
		{
			system("mpg123 -q -f 25000 sound/m8_holster.mp3");
			exit(0);
		}
		g_plr.uikeys_prsd -= PRSD_H;
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			system("mpg123 -q -f 25000 sound/m8_draw.mp3");
			exit(0);
		}
		g_plr.uikeys_prsd |= PRSD_H;
	}

}
