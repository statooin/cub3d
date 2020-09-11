/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:03:05 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:03:06 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_shields(void)
{
	g_plr.iplr_shield = 27;

	g_tex.tex_shield = malloc(sizeof(t_img_n_tex) * 28);

	g_tex.tex_shield[27].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_00.xpm", &g_tex.tex_shield[27].width, &g_tex.tex_shield[27].height);
	g_tex.tex_shield[27].data = (int *)mlx_get_data_addr(g_tex.tex_shield[27].ptr, &g_tex.tex_shield[27].bpp, &g_tex.tex_shield[27].size_line, &g_tex.tex_shield[27].endian);
	g_tex.tex_shield[27].scale = 1;
	g_tex.tex_shield[27].step = 1 / g_tex.tex_shield[27].scale;
	g_tex.tex_shield[27].opacity = 0.8;
	g_tex.tex_shield[27].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[26].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_01.xpm", &g_tex.tex_shield[26].width, &g_tex.tex_shield[26].height);
	g_tex.tex_shield[26].data = (int *)mlx_get_data_addr(g_tex.tex_shield[26].ptr, &g_tex.tex_shield[26].bpp, &g_tex.tex_shield[26].size_line, &g_tex.tex_shield[26].endian);
	g_tex.tex_shield[26].scale = 1;
	g_tex.tex_shield[26].step = 1 / g_tex.tex_shield[26].scale;
	g_tex.tex_shield[26].opacity = 0.8;
	g_tex.tex_shield[26].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[25].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_02.xpm", &g_tex.tex_shield[25].width, &g_tex.tex_shield[25].height);
	g_tex.tex_shield[25].data = (int *)mlx_get_data_addr(g_tex.tex_shield[25].ptr, &g_tex.tex_shield[25].bpp, &g_tex.tex_shield[25].size_line, &g_tex.tex_shield[25].endian);
	g_tex.tex_shield[25].scale = 1;
	g_tex.tex_shield[25].step = 1 / g_tex.tex_shield[25].scale;
	g_tex.tex_shield[25].opacity = 0.8;
	g_tex.tex_shield[25].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[24].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_03.xpm", &g_tex.tex_shield[24].width, &g_tex.tex_shield[24].height);
	g_tex.tex_shield[24].data = (int *)mlx_get_data_addr(g_tex.tex_shield[24].ptr, &g_tex.tex_shield[24].bpp, &g_tex.tex_shield[24].size_line, &g_tex.tex_shield[24].endian);
	g_tex.tex_shield[24].scale = 1;
	g_tex.tex_shield[24].step = 1 / g_tex.tex_shield[24].scale;
	g_tex.tex_shield[24].opacity = 0.8;
	g_tex.tex_shield[24].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[23].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_04.xpm", &g_tex.tex_shield[23].width, &g_tex.tex_shield[23].height);
	g_tex.tex_shield[23].data = (int *)mlx_get_data_addr(g_tex.tex_shield[23].ptr, &g_tex.tex_shield[23].bpp, &g_tex.tex_shield[23].size_line, &g_tex.tex_shield[23].endian);
	g_tex.tex_shield[23].scale = 1;
	g_tex.tex_shield[23].step = 1 / g_tex.tex_shield[23].scale;
	g_tex.tex_shield[23].opacity = 0.8;
	g_tex.tex_shield[23].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[22].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_05.xpm", &g_tex.tex_shield[22].width, &g_tex.tex_shield[22].height);
	g_tex.tex_shield[22].data = (int *)mlx_get_data_addr(g_tex.tex_shield[22].ptr, &g_tex.tex_shield[22].bpp, &g_tex.tex_shield[22].size_line, &g_tex.tex_shield[22].endian);
	g_tex.tex_shield[22].scale = 1;
	g_tex.tex_shield[22].step = 1 / g_tex.tex_shield[22].scale;
	g_tex.tex_shield[22].opacity = 0.8;
	g_tex.tex_shield[22].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[21].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_06.xpm", &g_tex.tex_shield[21].width, &g_tex.tex_shield[21].height);
	g_tex.tex_shield[21].data = (int *)mlx_get_data_addr(g_tex.tex_shield[21].ptr, &g_tex.tex_shield[21].bpp, &g_tex.tex_shield[21].size_line, &g_tex.tex_shield[21].endian);
	g_tex.tex_shield[21].scale = 1;
	g_tex.tex_shield[21].step = 1 / g_tex.tex_shield[21].scale;
	g_tex.tex_shield[21].opacity = 0.8;
	g_tex.tex_shield[21].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[20].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_07.xpm", &g_tex.tex_shield[20].width, &g_tex.tex_shield[20].height);
	g_tex.tex_shield[20].data = (int *)mlx_get_data_addr(g_tex.tex_shield[20].ptr, &g_tex.tex_shield[20].bpp, &g_tex.tex_shield[20].size_line, &g_tex.tex_shield[20].endian);
	g_tex.tex_shield[20].scale = 1;
	g_tex.tex_shield[20].step = 1 / g_tex.tex_shield[20].scale;
	g_tex.tex_shield[20].opacity = 0.8;
	g_tex.tex_shield[20].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[19].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_08.xpm", &g_tex.tex_shield[19].width, &g_tex.tex_shield[19].height);
	g_tex.tex_shield[19].data = (int *)mlx_get_data_addr(g_tex.tex_shield[19].ptr, &g_tex.tex_shield[19].bpp, &g_tex.tex_shield[19].size_line, &g_tex.tex_shield[19].endian);
	g_tex.tex_shield[19].scale = 1;
	g_tex.tex_shield[19].step = 1 / g_tex.tex_shield[19].scale;
	g_tex.tex_shield[19].opacity = 0.8;
	g_tex.tex_shield[19].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[18].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_09.xpm", &g_tex.tex_shield[18].width, &g_tex.tex_shield[18].height);
	g_tex.tex_shield[18].data = (int *)mlx_get_data_addr(g_tex.tex_shield[18].ptr, &g_tex.tex_shield[18].bpp, &g_tex.tex_shield[18].size_line, &g_tex.tex_shield[18].endian);
	g_tex.tex_shield[18].scale = 1;
	g_tex.tex_shield[18].step = 1 / g_tex.tex_shield[18].scale;
	g_tex.tex_shield[18].opacity = 0.8;
	g_tex.tex_shield[18].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[17].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_10.xpm", &g_tex.tex_shield[17].width, &g_tex.tex_shield[17].height);
	g_tex.tex_shield[17].data = (int *)mlx_get_data_addr(g_tex.tex_shield[17].ptr, &g_tex.tex_shield[17].bpp, &g_tex.tex_shield[17].size_line, &g_tex.tex_shield[17].endian);
	g_tex.tex_shield[17].scale = 1;
	g_tex.tex_shield[17].step = 1 / g_tex.tex_shield[17].scale;
	g_tex.tex_shield[17].opacity = 0.8;
	g_tex.tex_shield[17].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[16].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_11.xpm", &g_tex.tex_shield[16].width, &g_tex.tex_shield[16].height);
	g_tex.tex_shield[16].data = (int *)mlx_get_data_addr(g_tex.tex_shield[16].ptr, &g_tex.tex_shield[16].bpp, &g_tex.tex_shield[16].size_line, &g_tex.tex_shield[16].endian);
	g_tex.tex_shield[16].scale = 1;
	g_tex.tex_shield[16].step = 1 / g_tex.tex_shield[16].scale;
	g_tex.tex_shield[16].opacity = 0.8;
	g_tex.tex_shield[16].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[15].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_12.xpm", &g_tex.tex_shield[15].width, &g_tex.tex_shield[15].height);
	g_tex.tex_shield[15].data = (int *)mlx_get_data_addr(g_tex.tex_shield[15].ptr, &g_tex.tex_shield[15].bpp, &g_tex.tex_shield[15].size_line, &g_tex.tex_shield[15].endian);
	g_tex.tex_shield[15].scale = 1;
	g_tex.tex_shield[15].step = 1 / g_tex.tex_shield[15].scale;
	g_tex.tex_shield[15].opacity = 0.8;
	g_tex.tex_shield[15].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[14].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_13.xpm", &g_tex.tex_shield[14].width, &g_tex.tex_shield[14].height);
	g_tex.tex_shield[14].data = (int *)mlx_get_data_addr(g_tex.tex_shield[14].ptr, &g_tex.tex_shield[14].bpp, &g_tex.tex_shield[14].size_line, &g_tex.tex_shield[14].endian);
	g_tex.tex_shield[14].scale = 1;
	g_tex.tex_shield[14].step = 1 / g_tex.tex_shield[14].scale;
	g_tex.tex_shield[14].opacity = 0.8;
	g_tex.tex_shield[14].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[13].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_14.xpm", &g_tex.tex_shield[13].width, &g_tex.tex_shield[13].height);
	g_tex.tex_shield[13].data = (int *)mlx_get_data_addr(g_tex.tex_shield[13].ptr, &g_tex.tex_shield[13].bpp, &g_tex.tex_shield[13].size_line, &g_tex.tex_shield[13].endian);
	g_tex.tex_shield[13].scale = 1;
	g_tex.tex_shield[13].step = 1 / g_tex.tex_shield[13].scale;
	g_tex.tex_shield[13].opacity = 0.8;
	g_tex.tex_shield[13].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[12].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_15.xpm", &g_tex.tex_shield[12].width, &g_tex.tex_shield[12].height);
	g_tex.tex_shield[12].data = (int *)mlx_get_data_addr(g_tex.tex_shield[12].ptr, &g_tex.tex_shield[12].bpp, &g_tex.tex_shield[12].size_line, &g_tex.tex_shield[12].endian);
	g_tex.tex_shield[12].scale = 1;
	g_tex.tex_shield[12].step = 1 / g_tex.tex_shield[12].scale;
	g_tex.tex_shield[12].opacity = 0.8;
	g_tex.tex_shield[12].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[11].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_16.xpm", &g_tex.tex_shield[11].width, &g_tex.tex_shield[11].height);
	g_tex.tex_shield[11].data = (int *)mlx_get_data_addr(g_tex.tex_shield[11].ptr, &g_tex.tex_shield[11].bpp, &g_tex.tex_shield[11].size_line, &g_tex.tex_shield[11].endian);
	g_tex.tex_shield[11].scale = 1;
	g_tex.tex_shield[11].step = 1 / g_tex.tex_shield[11].scale;
	g_tex.tex_shield[11].opacity = 0.8;
	g_tex.tex_shield[11].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[10].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_17.xpm", &g_tex.tex_shield[10].width, &g_tex.tex_shield[10].height);
	g_tex.tex_shield[10].data = (int *)mlx_get_data_addr(g_tex.tex_shield[10].ptr, &g_tex.tex_shield[10].bpp, &g_tex.tex_shield[10].size_line, &g_tex.tex_shield[10].endian);
	g_tex.tex_shield[10].scale = 1;
	g_tex.tex_shield[10].step = 1 / g_tex.tex_shield[10].scale;
	g_tex.tex_shield[10].opacity = 0.8;
	g_tex.tex_shield[10].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[9].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_18.xpm", &g_tex.tex_shield[9].width, &g_tex.tex_shield[9].height);
	g_tex.tex_shield[9].data = (int *)mlx_get_data_addr(g_tex.tex_shield[9].ptr, &g_tex.tex_shield[9].bpp, &g_tex.tex_shield[9].size_line, &g_tex.tex_shield[9].endian);
	g_tex.tex_shield[9].scale = 1;
	g_tex.tex_shield[9].step = 1 / g_tex.tex_shield[9].scale;
	g_tex.tex_shield[9].opacity = 0.8;
	g_tex.tex_shield[9].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[8].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_19.xpm", &g_tex.tex_shield[8].width, &g_tex.tex_shield[8].height);
	g_tex.tex_shield[8].data = (int *)mlx_get_data_addr(g_tex.tex_shield[8].ptr, &g_tex.tex_shield[8].bpp, &g_tex.tex_shield[8].size_line, &g_tex.tex_shield[8].endian);
	g_tex.tex_shield[8].scale = 1;
	g_tex.tex_shield[8].step = 1 / g_tex.tex_shield[8].scale;
	g_tex.tex_shield[8].opacity = 0.8;
	g_tex.tex_shield[8].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[7].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_20.xpm", &g_tex.tex_shield[7].width, &g_tex.tex_shield[7].height);
	g_tex.tex_shield[7].data = (int *)mlx_get_data_addr(g_tex.tex_shield[7].ptr, &g_tex.tex_shield[7].bpp, &g_tex.tex_shield[7].size_line, &g_tex.tex_shield[7].endian);
	g_tex.tex_shield[7].scale = 1;
	g_tex.tex_shield[7].step = 1 / g_tex.tex_shield[7].scale;
	g_tex.tex_shield[7].opacity = 0.8;
	g_tex.tex_shield[7].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[6].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_21.xpm", &g_tex.tex_shield[6].width, &g_tex.tex_shield[6].height);
	g_tex.tex_shield[6].data = (int *)mlx_get_data_addr(g_tex.tex_shield[6].ptr, &g_tex.tex_shield[6].bpp, &g_tex.tex_shield[6].size_line, &g_tex.tex_shield[6].endian);
	g_tex.tex_shield[6].scale = 1;
	g_tex.tex_shield[6].step = 1 / g_tex.tex_shield[6].scale;
	g_tex.tex_shield[6].opacity = 0.8;
	g_tex.tex_shield[6].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[5].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_22.xpm", &g_tex.tex_shield[5].width, &g_tex.tex_shield[5].height);
	g_tex.tex_shield[5].data = (int *)mlx_get_data_addr(g_tex.tex_shield[5].ptr, &g_tex.tex_shield[5].bpp, &g_tex.tex_shield[5].size_line, &g_tex.tex_shield[5].endian);
	g_tex.tex_shield[5].scale = 1;
	g_tex.tex_shield[5].step = 1 / g_tex.tex_shield[5].scale;
	g_tex.tex_shield[5].opacity = 0.8;
	g_tex.tex_shield[5].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[4].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_23.xpm", &g_tex.tex_shield[4].width, &g_tex.tex_shield[4].height);
	g_tex.tex_shield[4].data = (int *)mlx_get_data_addr(g_tex.tex_shield[4].ptr, &g_tex.tex_shield[4].bpp, &g_tex.tex_shield[4].size_line, &g_tex.tex_shield[4].endian);
	g_tex.tex_shield[4].scale = 1;
	g_tex.tex_shield[4].step = 1 / g_tex.tex_shield[4].scale;
	g_tex.tex_shield[4].opacity = 0.8;
	g_tex.tex_shield[4].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[3].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_24.xpm", &g_tex.tex_shield[3].width, &g_tex.tex_shield[3].height);
	g_tex.tex_shield[3].data = (int *)mlx_get_data_addr(g_tex.tex_shield[3].ptr, &g_tex.tex_shield[3].bpp, &g_tex.tex_shield[3].size_line, &g_tex.tex_shield[3].endian);
	g_tex.tex_shield[3].scale = 1;
	g_tex.tex_shield[3].step = 1 / g_tex.tex_shield[3].scale;
	g_tex.tex_shield[3].opacity = 0.8;
	g_tex.tex_shield[3].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[2].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_25.xpm", &g_tex.tex_shield[2].width, &g_tex.tex_shield[2].height);
	g_tex.tex_shield[2].data = (int *)mlx_get_data_addr(g_tex.tex_shield[2].ptr, &g_tex.tex_shield[2].bpp, &g_tex.tex_shield[2].size_line, &g_tex.tex_shield[2].endian);
	g_tex.tex_shield[2].scale = 1;
	g_tex.tex_shield[2].step = 1 / g_tex.tex_shield[2].scale;
	g_tex.tex_shield[2].opacity = 0.8;
	g_tex.tex_shield[2].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[1].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_26.xpm", &g_tex.tex_shield[1].width, &g_tex.tex_shield[1].height);
	g_tex.tex_shield[1].data = (int *)mlx_get_data_addr(g_tex.tex_shield[1].ptr, &g_tex.tex_shield[1].bpp, &g_tex.tex_shield[1].size_line, &g_tex.tex_shield[1].endian);
	g_tex.tex_shield[1].scale = 1;
	g_tex.tex_shield[1].step = 1 / g_tex.tex_shield[1].scale;
	g_tex.tex_shield[1].opacity = 0.8;
	g_tex.tex_shield[1].opacity_1 = 1 - 0.8;

	g_tex.tex_shield[0].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/shields/shield_27.xpm", &g_tex.tex_shield[0].width, &g_tex.tex_shield[0].height);
	g_tex.tex_shield[0].data = (int *)mlx_get_data_addr(g_tex.tex_shield[0].ptr, &g_tex.tex_shield[9].bpp, &g_tex.tex_shield[0].size_line, &g_tex.tex_shield[0].endian);
	g_tex.tex_shield[0].scale = 1;
	g_tex.tex_shield[0].step = 1 / g_tex.tex_shield[0].scale;
	g_tex.tex_shield[0].opacity = 0.8;
	g_tex.tex_shield[0].opacity_1 = 1 - 0.8;
}
