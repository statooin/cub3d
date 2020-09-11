/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:56:52 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:59:38 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_floor_color(int *ihit_floor, float *ffloor_tilex, \
	float *ffloor_tiley, int *idraw_y)
{
	static int	t_w;
	static int	t_h;

	t_w = (int)(*ffloor_tilex * g_tex.tex_floor[*ihit_floor].width) \
		% g_tex.tex_floor[*ihit_floor].width;
	t_h = (int)(*ffloor_tiley * g_tex.tex_floor[*ihit_floor].height) \
		% g_tex.tex_floor[*ihit_floor].height;
	return (ft_shades(&g_tex.tex_floor[*ihit_floor].data[t_h * \
		g_tex.tex_floor[*ihit_floor].width + t_w], \
		&g_math.fdist_to_all_tiles[*idraw_y][g_math.iray_x]));
}
