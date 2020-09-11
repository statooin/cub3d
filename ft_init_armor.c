/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_armor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:59:26 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 20:26:15 by bjebedia         ###   ########.fr       */
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
//	g_tex.tex_armor[i].ptr = mlx_xpm_file_to_image(g_game.mlx, ctex_name, &g_tex.tex_armor[i].width, &g_tex.tex_armor[i].height);
//	g_tex.tex_armor[18].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_18.xpm", &g_tex.tex_armor[18].width, &g_tex.tex_armor[18].height);
//	g_tex.tex_armor[17].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_17.xpm", &g_tex.tex_armor[17].width, &g_tex.tex_armor[17].height);
	while (i <= 18)
	{
		ft_strjoin_f("textures/ui/armor/armor_", ft_itoa(i), &ctex_name);
		ft_strjoin_f(ctex_name, ".xpm", &ctex_name);
		g_tex.tex_armor[i].ptr = mlx_xpm_file_to_image(g_game.mlx, ctex_name, &g_tex.tex_armor[i].width, &g_tex.tex_armor[i].height);
		g_tex.tex_armor[i].data = (int *)mlx_get_data_addr(g_tex.tex_armor[i].ptr, &g_tex.tex_armor[i].bpp, &g_tex.tex_armor[i].size_line, &g_tex.tex_armor[i].endian);
		g_tex.tex_armor[i].scale = 1;
		g_tex.tex_armor[i].step = 1 / g_tex.tex_armor[i].scale;
		g_tex.tex_armor[i].opacity = 0.8;
		g_tex.tex_armor[i].opacity_1 = 1 - 0.8;
		i++;
	}
/*
	g_tex.tex_armor[18].data = (int *)mlx_get_data_addr(g_tex.tex_armor[18].ptr, &g_tex.tex_armor[18].bpp, &g_tex.tex_armor[18].size_line, &g_tex.tex_armor[18].endian);
	g_tex.tex_armor[18].scale = 1;
	g_tex.tex_armor[18].step = 1 / g_tex.tex_armor[18].scale;
	g_tex.tex_armor[18].opacity = 0.8;
	g_tex.tex_armor[18].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[17].data = (int *)mlx_get_data_addr(g_tex.tex_armor[17].ptr, &g_tex.tex_armor[17].bpp, &g_tex.tex_armor[17].size_line, &g_tex.tex_armor[17].endian);
	g_tex.tex_armor[17].scale = 1;
	g_tex.tex_armor[17].step = 1 / g_tex.tex_armor[17].scale;
	g_tex.tex_armor[17].opacity = 0.8;
	g_tex.tex_armor[17].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[16].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_16.xpm", &g_tex.tex_armor[16].width, &g_tex.tex_armor[16].height);
	g_tex.tex_armor[16].data = (int *)mlx_get_data_addr(g_tex.tex_armor[16].ptr, &g_tex.tex_armor[16].bpp, &g_tex.tex_armor[16].size_line, &g_tex.tex_armor[16].endian);
	g_tex.tex_armor[16].scale = 1;
	g_tex.tex_armor[16].step = 1 / g_tex.tex_armor[16].scale;
	g_tex.tex_armor[16].opacity = 0.8;
	g_tex.tex_armor[16].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[15].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_15.xpm", &g_tex.tex_armor[15].width, &g_tex.tex_armor[15].height);
	g_tex.tex_armor[15].data = (int *)mlx_get_data_addr(g_tex.tex_armor[15].ptr, &g_tex.tex_armor[15].bpp, &g_tex.tex_armor[15].size_line, &g_tex.tex_armor[15].endian);
	g_tex.tex_armor[15].scale = 1;
	g_tex.tex_armor[15].step = 1 / g_tex.tex_armor[15].scale;
	g_tex.tex_armor[15].opacity = 0.8;
	g_tex.tex_armor[15].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[14].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_14.xpm", &g_tex.tex_armor[14].width, &g_tex.tex_armor[14].height);
	g_tex.tex_armor[14].data = (int *)mlx_get_data_addr(g_tex.tex_armor[14].ptr, &g_tex.tex_armor[14].bpp, &g_tex.tex_armor[14].size_line, &g_tex.tex_armor[14].endian);
	g_tex.tex_armor[14].scale = 1;
	g_tex.tex_armor[14].step = 1 / g_tex.tex_armor[14].scale;
	g_tex.tex_armor[14].opacity = 0.8;
	g_tex.tex_armor[14].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[13].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_13.xpm", &g_tex.tex_armor[13].width, &g_tex.tex_armor[13].height);
	g_tex.tex_armor[13].data = (int *)mlx_get_data_addr(g_tex.tex_armor[13].ptr, &g_tex.tex_armor[13].bpp, &g_tex.tex_armor[13].size_line, &g_tex.tex_armor[13].endian);
	g_tex.tex_armor[13].scale = 1;
	g_tex.tex_armor[13].step = 1 / g_tex.tex_armor[13].scale;
	g_tex.tex_armor[13].opacity = 0.8;
	g_tex.tex_armor[13].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[12].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_12.xpm", &g_tex.tex_armor[12].width, &g_tex.tex_armor[12].height);
	g_tex.tex_armor[12].data = (int *)mlx_get_data_addr(g_tex.tex_armor[12].ptr, &g_tex.tex_armor[12].bpp, &g_tex.tex_armor[12].size_line, &g_tex.tex_armor[12].endian);
	g_tex.tex_armor[12].scale = 1;
	g_tex.tex_armor[12].step = 1 / g_tex.tex_armor[12].scale;
	g_tex.tex_armor[12].opacity = 0.8;
	g_tex.tex_armor[12].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[11].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_11.xpm", &g_tex.tex_armor[11].width, &g_tex.tex_armor[11].height);
	g_tex.tex_armor[11].data = (int *)mlx_get_data_addr(g_tex.tex_armor[11].ptr, &g_tex.tex_armor[11].bpp, &g_tex.tex_armor[11].size_line, &g_tex.tex_armor[11].endian);
	g_tex.tex_armor[11].scale = 1;
	g_tex.tex_armor[11].step = 1 / g_tex.tex_armor[11].scale;
	g_tex.tex_armor[11].opacity = 0.8;
	g_tex.tex_armor[11].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[10].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_10.xpm", &g_tex.tex_armor[10].width, &g_tex.tex_armor[10].height);
	g_tex.tex_armor[10].data = (int *)mlx_get_data_addr(g_tex.tex_armor[10].ptr, &g_tex.tex_armor[10].bpp, &g_tex.tex_armor[10].size_line, &g_tex.tex_armor[10].endian);
	g_tex.tex_armor[10].scale = 1;
	g_tex.tex_armor[10].step = 1 / g_tex.tex_armor[10].scale;
	g_tex.tex_armor[10].opacity = 0.8;
	g_tex.tex_armor[10].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[9].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_09.xpm", &g_tex.tex_armor[9].width, &g_tex.tex_armor[9].height);
	g_tex.tex_armor[9].data = (int *)mlx_get_data_addr(g_tex.tex_armor[9].ptr, &g_tex.tex_armor[9].bpp, &g_tex.tex_armor[9].size_line, &g_tex.tex_armor[9].endian);
	g_tex.tex_armor[9].scale = 1;
	g_tex.tex_armor[9].step = 1 / g_tex.tex_armor[9].scale;
	g_tex.tex_armor[9].opacity = 0.8;
	g_tex.tex_armor[9].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[8].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_08.xpm", &g_tex.tex_armor[8].width, &g_tex.tex_armor[8].height);
	g_tex.tex_armor[8].data = (int *)mlx_get_data_addr(g_tex.tex_armor[8].ptr, &g_tex.tex_armor[8].bpp, &g_tex.tex_armor[8].size_line, &g_tex.tex_armor[8].endian);
	g_tex.tex_armor[8].scale = 1;
	g_tex.tex_armor[8].step = 1 / g_tex.tex_armor[8].scale;
	g_tex.tex_armor[8].opacity = 0.8;
	g_tex.tex_armor[8].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[7].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_07.xpm", &g_tex.tex_armor[7].width, &g_tex.tex_armor[7].height);
	g_tex.tex_armor[7].data = (int *)mlx_get_data_addr(g_tex.tex_armor[7].ptr, &g_tex.tex_armor[7].bpp, &g_tex.tex_armor[7].size_line, &g_tex.tex_armor[7].endian);
	g_tex.tex_armor[7].scale = 1;
	g_tex.tex_armor[7].step = 1 / g_tex.tex_armor[7].scale;
	g_tex.tex_armor[7].opacity = 0.8;
	g_tex.tex_armor[7].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[6].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_06.xpm", &g_tex.tex_armor[6].width, &g_tex.tex_armor[6].height);
	g_tex.tex_armor[6].data = (int *)mlx_get_data_addr(g_tex.tex_armor[6].ptr, &g_tex.tex_armor[6].bpp, &g_tex.tex_armor[6].size_line, &g_tex.tex_armor[6].endian);
	g_tex.tex_armor[6].scale = 1;
	g_tex.tex_armor[6].step = 1 / g_tex.tex_armor[6].scale;
	g_tex.tex_armor[6].opacity = 0.8;
	g_tex.tex_armor[6].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[5].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_05.xpm", &g_tex.tex_armor[5].width, &g_tex.tex_armor[5].height);
	g_tex.tex_armor[5].data = (int *)mlx_get_data_addr(g_tex.tex_armor[5].ptr, &g_tex.tex_armor[5].bpp, &g_tex.tex_armor[5].size_line, &g_tex.tex_armor[5].endian);
	g_tex.tex_armor[5].scale = 1;
	g_tex.tex_armor[5].step = 1 / g_tex.tex_armor[5].scale;
	g_tex.tex_armor[5].opacity = 0.8;
	g_tex.tex_armor[5].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[4].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_04.xpm", &g_tex.tex_armor[4].width, &g_tex.tex_armor[4].height);
	g_tex.tex_armor[4].data = (int *)mlx_get_data_addr(g_tex.tex_armor[4].ptr, &g_tex.tex_armor[4].bpp, &g_tex.tex_armor[4].size_line, &g_tex.tex_armor[4].endian);
	g_tex.tex_armor[4].scale = 1;
	g_tex.tex_armor[4].step = 1 / g_tex.tex_armor[4].scale;
	g_tex.tex_armor[4].opacity = 0.8;
	g_tex.tex_armor[4].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[3].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_03.xpm", &g_tex.tex_armor[3].width, &g_tex.tex_armor[3].height);
	g_tex.tex_armor[3].data = (int *)mlx_get_data_addr(g_tex.tex_armor[3].ptr, &g_tex.tex_armor[3].bpp, &g_tex.tex_armor[3].size_line, &g_tex.tex_armor[3].endian);
	g_tex.tex_armor[3].scale = 1;
	g_tex.tex_armor[3].step = 1 / g_tex.tex_armor[3].scale;
	g_tex.tex_armor[3].opacity = 0.8;
	g_tex.tex_armor[3].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[2].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_02.xpm", &g_tex.tex_armor[2].width, &g_tex.tex_armor[2].height);
	g_tex.tex_armor[2].data = (int *)mlx_get_data_addr(g_tex.tex_armor[2].ptr, &g_tex.tex_armor[2].bpp, &g_tex.tex_armor[2].size_line, &g_tex.tex_armor[2].endian);
	g_tex.tex_armor[2].scale = 1;
	g_tex.tex_armor[2].step = 1 / g_tex.tex_armor[2].scale;
	g_tex.tex_armor[2].opacity = 0.8;
	g_tex.tex_armor[2].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[1].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_01.xpm", &g_tex.tex_armor[1].width, &g_tex.tex_armor[1].height);
	g_tex.tex_armor[1].data = (int *)mlx_get_data_addr(g_tex.tex_armor[1].ptr, &g_tex.tex_armor[1].bpp, &g_tex.tex_armor[1].size_line, &g_tex.tex_armor[1].endian);
	g_tex.tex_armor[1].scale = 1;
	g_tex.tex_armor[1].step = 1 / g_tex.tex_armor[1].scale;
	g_tex.tex_armor[1].opacity = 0.8;
	g_tex.tex_armor[1].opacity_1 = 1 - 0.8;

	g_tex.tex_armor[0].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/armor/armor_00.xpm", &g_tex.tex_armor[0].width, &g_tex.tex_armor[0].height);
	g_tex.tex_armor[0].data = (int *)mlx_get_data_addr(g_tex.tex_armor[0].ptr, &g_tex.tex_armor[9].bpp, &g_tex.tex_armor[0].size_line, &g_tex.tex_armor[0].endian);
	g_tex.tex_armor[0].scale = 1;
	g_tex.tex_armor[0].step = 1 / g_tex.tex_armor[0].scale;
	g_tex.tex_armor[0].opacity = 0.8;
	g_tex.tex_armor[0].opacity_1 = 1 - 0.8;
	*/
}
