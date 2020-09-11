/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:06:18 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:42:44 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int ikey)
{
	if (ikey == KEY_LEFT)
		g_plr.uikeys_prsd |= PRSD_LEFT;
	if (ikey == KEY_RIGHT)
		g_plr.uikeys_prsd |= PRSD_RIGHT;
	if (ikey == KEY_E)
		g_plr.uikeys_prsd |= PRSD_E;
	if (ikey == KEY_H)
		ft_holster_weapon();
	if (ikey == KEY_W || ikey == KEY_UP)
		g_plr.uikeys_prsd |= PRSD_UP_W;
	if (ikey == KEY_S || ikey == KEY_DOWN)
		g_plr.uikeys_prsd |= PRSD_DOWN_S;
	if (ikey == KEY_A)
		g_plr.uikeys_prsd |= PRSD_A;
	if (ikey == KEY_D)
		g_plr.uikeys_prsd |= PRSD_D;
	if (ikey == KEY_SHIFT)
	{
		if ((g_plr.uikeys_prsd & PRSD_SHIFT) != 0)
			g_plr.uikeys_prsd -= PRSD_SHIFT;
		else
			g_plr.uikeys_prsd |= PRSD_SHIFT;
	}
	if (ikey == KEY_ESC)
		ft_close();
	return (1);
}
