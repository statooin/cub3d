/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:07:01 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:42:44 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_release(int ikey)
{
	if (ikey == KEY_LEFT)
		g_plr.uikeys_prsd -= PRSD_LEFT;
	if (ikey == KEY_RIGHT)
		g_plr.uikeys_prsd -= PRSD_RIGHT;
	if (ikey == KEY_E)
		g_plr.uikeys_prsd -= PRSD_E;
	if (ikey == KEY_W || ikey == KEY_UP)
		g_plr.uikeys_prsd -= PRSD_UP_W;
	if (ikey == KEY_S || ikey == KEY_DOWN)
		g_plr.uikeys_prsd -= PRSD_DOWN_S;
	if (ikey == KEY_A)
		g_plr.uikeys_prsd -= PRSD_A;
	if (ikey == KEY_D)
		g_plr.uikeys_prsd -= PRSD_D;
	return (1);
}
