/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall_stripes_all.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:59:32 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:57:49 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_wall_stripes_all(float *fray_ang, t_objects *obj, int *i)
{
	static int	ihit_wall;
	static int	n;

	n = 0;
	while (n <= *i)
	{
		if (obj[n].ctype < 'a')
		{
			ihit_wall = obj[n].ctype - '0';
			ft_draw_wall_stripe(fray_ang, &obj[n].itest_x, &ihit_wall, \
				&obj[n].fdist, &obj[n].ftest_x, &obj[n].ftest_y);
		}
		//else ft_draw_enemy(fdist_to_wall); // !!!!!!!!!!!!!!!!!!!!!!!!
		n++;
	}
}
