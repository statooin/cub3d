/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_click.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:09:56 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:42:44 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse_click(int ikey)
{
	if (g_plr.iplay_cut_scene != 0)
		return (1);
	if (ikey == 1)
	{
		if ((g_plr.uikeys_prsd & PRSD_H) == 0)
			g_plr.uikeys_prsd |= PRSD_H;
		else
			g_math.ishot = 3;
	}
	return (1);
}
