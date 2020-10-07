/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:03:05 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/15 17:51:30 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_shields(void)
{
	int		i;
	char	*ctex_name;

	i = 0;
	g_plr.iplr_shield = 27;
	g_tex.tex_shield = malloc(sizeof(t_img_n_tex) * 28);
	ctex_name = NULL;
	while (i <= 27)
	{
		ft_strjoin_f("textures/ui/shields/shield_", ft_itoa(i), &ctex_name);
		ft_strjoin_f(ctex_name, ".xpm", &ctex_name);
		g_tex.tex_shield[i].ptr = mlx_xpm_file_to_image(g_game.mlx, \
			ctex_name, &g_tex.tex_shield[i].width, \
			&g_tex.tex_shield[i].height);
		g_tex.tex_shield[i].data = \
			(int *)mlx_get_data_addr(g_tex.tex_shield[i].ptr, \
			&g_tex.tex_shield[i].bpp, &g_tex.tex_shield[i].size_line, \
			&g_tex.tex_shield[i].endian);
		g_tex.tex_shield[i].scale = 1;
		g_tex.tex_shield[i].step = 1 / g_tex.tex_shield[i].scale;
		g_tex.tex_shield[i].opacity = 0.8;
		g_tex.tex_shield[i].opacity_1 = 1 - 0.8;
		i++;
	}
}
