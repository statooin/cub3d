/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_armor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:59:26 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/15 17:06:18 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_armor(void)
{
	int		i;
	char	*ctex_name;

	i = 0;
	g_plr.iplr_armor = 18;
	g_tex.tex_armor = malloc(sizeof(t_img_n_tex) * 19);
	ctex_name = ft_strdup("");
	while (i <= 18)
	{
		ft_strjoin_f("textures/ui/armor/armor_", ft_itoa(i), &ctex_name);
		ft_strjoin_f(ctex_name, ".xpm", &ctex_name);
		g_tex.tex_armor[i].ptr = mlx_xpm_file_to_image(g_game.mlx, \
			ctex_name, &g_tex.tex_armor[i].width, \
			&g_tex.tex_armor[i].height);
		g_tex.tex_armor[i].data = \
			(int *)mlx_get_data_addr(g_tex.tex_armor[i].ptr, \
			&g_tex.tex_armor[i].bpp, &g_tex.tex_armor[i].size_line, \
			&g_tex.tex_armor[i].endian);
		g_tex.tex_armor[i].scale = 1;
		g_tex.tex_armor[i].step = 1 / g_tex.tex_armor[i].scale;
		g_tex.tex_armor[i].opacity = 0.8;
		g_tex.tex_armor[i].opacity_1 = 1 - 0.8;
		i++;
	}
}
