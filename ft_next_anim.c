/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:14:12 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:14:13 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_next_anim(void)
{
	if (g_enemies[g_math.ienemy_n].en_anim_i < 15)
		g_enemies[g_math.ienemy_n].en_anim_i++;
	else
		g_enemies[g_math.ienemy_n].en_anim_i = 0;
}
