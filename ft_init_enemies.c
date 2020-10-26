/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:00:08 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:00:15 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_init_enemies(void)
{
	//	int	i;

	g_enemies = malloc(sizeof(t_enemy) * 20);

	g_enemies[0].ienemy_width = 1.8f; // / (8 / 3.2);
	g_enemies[0].ienemy_top = 0.15f;//0.3f;
	g_enemies[0].fenemy_bottom = 1.0f - g_enemies[0].ienemy_top;
	g_enemies[0].fenemy_tall = 0.95f; //  * (8 / 3.2)
	g_enemies[0].en_anim_i = 16;
	g_enemies[0].ifirst_rayx = -401;
	g_enemies[0].cl_move = 0.1f;
	g_enemies[0].cl_shoot = 0.2f;
	g_enemies[0].ihealth = 100;

	g_enemies[1].ienemy_width = 2; // / (8 / 3.2);
	g_enemies[1].ienemy_top = 0.2f;
	g_enemies[1].fenemy_bottom = 1.0f - g_enemies[1].ienemy_top;
	g_enemies[1].fenemy_tall = 1.2f; //  * (8 / 3.2)
	g_enemies[1].en_anim_i = 0;
	g_enemies[1].ifirst_rayx = -401;
	g_enemies[1].cl_move = 0.2f;
	g_enemies[1].cl_shoot = 0.15f;
	g_enemies[1].ihealth = 0;

	g_enemies[2].ienemy_width = 2; // / (8 / 3.2);
	g_enemies[2].ienemy_top = 0.2f;
	g_enemies[2].fenemy_bottom = 1.0f - g_enemies[2].ienemy_top;
	g_enemies[2].fenemy_tall = 1.2f; //  * (8 / 3.2)
	g_enemies[2].en_anim_i = 0;
	g_enemies[2].ifirst_rayx = -401;
	g_enemies[2].cl_move = 0.15f;
	g_enemies[2].cl_shoot = 0.1f;
	g_enemies[2].ihealth = 0;
	//write(1, "1", 1);

	g_tex.en_anim = malloc(sizeof(t_img_n_tex*) * 2);
	g_tex.en_anim[0] = malloc(sizeof(t_img_n_tex) * 17);

	g_tex.en_anim[0][0].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_01.xpm", &g_tex.en_anim[0][0].width, &g_tex.en_anim[0][0].height);
	g_tex.en_anim[0][0].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][0].ptr, &g_tex.en_anim[0][0].bpp, &g_tex.en_anim[0][0].size_line, &g_tex.en_anim[0][0].endian);
	g_tex.en_anim[0][0].scale = 1;

	g_tex.en_anim[0][1].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_01_02.xpm", &g_tex.en_anim[0][1].width, &g_tex.en_anim[0][1].height);
	g_tex.en_anim[0][1].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][1].ptr, &g_tex.en_anim[0][1].bpp, &g_tex.en_anim[0][1].size_line, &g_tex.en_anim[0][1].endian);
	g_tex.en_anim[0][1].scale = 1;

	g_tex.en_anim[0][2].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_01_03.xpm", &g_tex.en_anim[0][2].width, &g_tex.en_anim[0][2].height);
	g_tex.en_anim[0][2].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][2].ptr, &g_tex.en_anim[0][2].bpp, &g_tex.en_anim[0][2].size_line, &g_tex.en_anim[0][2].endian);
	g_tex.en_anim[0][2].scale = 1;

	g_tex.en_anim[0][3].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_01_04.xpm", &g_tex.en_anim[0][3].width, &g_tex.en_anim[0][3].height);
	g_tex.en_anim[0][3].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][3].ptr, &g_tex.en_anim[0][3].bpp, &g_tex.en_anim[0][3].size_line, &g_tex.en_anim[0][3].endian);
	g_tex.en_anim[0][3].scale = 1;

	g_tex.en_anim[0][4].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_02.xpm", &g_tex.en_anim[0][4].width, &g_tex.en_anim[0][4].height);
	g_tex.en_anim[0][4].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][4].ptr, &g_tex.en_anim[0][4].bpp, &g_tex.en_anim[0][4].size_line, &g_tex.en_anim[0][4].endian);
	g_tex.en_anim[0][4].scale = 1;

	g_tex.en_anim[0][5].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_01_04.xpm", &g_tex.en_anim[0][5].width, &g_tex.en_anim[0][5].height);
	g_tex.en_anim[0][5].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][5].ptr, &g_tex.en_anim[0][5].bpp, &g_tex.en_anim[0][5].size_line, &g_tex.en_anim[0][5].endian);
	g_tex.en_anim[0][5].scale = 1;

	g_tex.en_anim[0][6].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_01_03.xpm", &g_tex.en_anim[0][6].width, &g_tex.en_anim[0][6].height);
	g_tex.en_anim[0][6].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][6].ptr, &g_tex.en_anim[0][6].bpp, &g_tex.en_anim[0][6].size_line, &g_tex.en_anim[0][6].endian);
	g_tex.en_anim[0][6].scale = 1;

	g_tex.en_anim[0][7].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_01_02.xpm", &g_tex.en_anim[0][7].width, &g_tex.en_anim[0][7].height);
	g_tex.en_anim[0][7].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][7].ptr, &g_tex.en_anim[0][7].bpp, &g_tex.en_anim[0][7].size_line, &g_tex.en_anim[0][7].endian);
	g_tex.en_anim[0][7].scale = 1;

	g_tex.en_anim[0][8].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_03.xpm", &g_tex.en_anim[0][8].width, &g_tex.en_anim[0][8].height);
	g_tex.en_anim[0][8].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][8].ptr, &g_tex.en_anim[0][8].bpp, &g_tex.en_anim[0][8].size_line, &g_tex.en_anim[0][8].endian);
	g_tex.en_anim[0][8].scale = 1;

	g_tex.en_anim[0][9].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_03_01.xpm", &g_tex.en_anim[0][9].width, &g_tex.en_anim[0][9].height);
	g_tex.en_anim[0][9].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][9].ptr, &g_tex.en_anim[0][9].bpp, &g_tex.en_anim[0][9].size_line, &g_tex.en_anim[0][9].endian);
	g_tex.en_anim[0][9].scale = 1;

	g_tex.en_anim[0][10].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_03_02.xpm", &g_tex.en_anim[0][10].width, &g_tex.en_anim[0][10].height);
	g_tex.en_anim[0][10].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][10].ptr, &g_tex.en_anim[0][10].bpp, &g_tex.en_anim[0][10].size_line, &g_tex.en_anim[0][10].endian);
	g_tex.en_anim[0][10].scale = 1;

	g_tex.en_anim[0][11].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_03_03.xpm", &g_tex.en_anim[0][11].width, &g_tex.en_anim[0][11].height);
	g_tex.en_anim[0][11].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][11].ptr, &g_tex.en_anim[0][11].bpp, &g_tex.en_anim[0][11].size_line, &g_tex.en_anim[0][11].endian);
	g_tex.en_anim[0][11].scale = 1;

	g_tex.en_anim[0][12].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_04.xpm", &g_tex.en_anim[0][12].width, &g_tex.en_anim[0][12].height);
	g_tex.en_anim[0][12].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][12].ptr, &g_tex.en_anim[0][12].bpp, &g_tex.en_anim[0][12].size_line, &g_tex.en_anim[0][12].endian);
	g_tex.en_anim[0][12].scale = 1;

	g_tex.en_anim[0][13].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_03_03.xpm", &g_tex.en_anim[0][13].width, &g_tex.en_anim[0][13].height);
	g_tex.en_anim[0][13].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][13].ptr, &g_tex.en_anim[0][13].bpp, &g_tex.en_anim[0][13].size_line, &g_tex.en_anim[0][13].endian);
	g_tex.en_anim[0][13].scale = 1;

	g_tex.en_anim[0][14].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_03_02.xpm", &g_tex.en_anim[0][14].width, &g_tex.en_anim[0][14].height);
	g_tex.en_anim[0][14].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][14].ptr, &g_tex.en_anim[0][14].bpp, &g_tex.en_anim[0][14].size_line, &g_tex.en_anim[0][14].endian);
	g_tex.en_anim[0][14].scale = 1;

	g_tex.en_anim[0][15].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/enemies/aim_m_03_01.xpm", &g_tex.en_anim[0][15].width, &g_tex.en_anim[0][15].height);
	g_tex.en_anim[0][15].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][15].ptr, &g_tex.en_anim[0][15].bpp, &g_tex.en_anim[0][15].size_line, &g_tex.en_anim[0][15].endian);
	g_tex.en_anim[0][15].scale = 1;

	g_tex.en_anim[0][16].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/items/shep.xpm", &g_tex.en_anim[0][16].width, &g_tex.en_anim[0][16].height);
	g_tex.en_anim[0][16].data = (int *)mlx_get_data_addr(g_tex.en_anim[0][16].ptr, &g_tex.en_anim[0][16].bpp, &g_tex.en_anim[0][16].size_line, &g_tex.en_anim[0][16].endian);
	g_tex.en_anim[0][16].scale = 1;

	g_math.enemy = malloc(sizeof(char**) * 10);
	g_math.enemy[0] = malloc(sizeof(char*) * 31);
	g_math.enemy[0][0] = ft_strdup("-----------------------------");
	g_math.enemy[0][1] = ft_strdup("-----+++---------------------");
	g_math.enemy[0][2] = ft_strdup("----+++++--------------------");
	g_math.enemy[0][3] = ft_strdup("---+++++++-------------------");
	g_math.enemy[0][4] = ft_strdup("--+++++++++------------------");
	g_math.enemy[0][5] = ft_strdup("--+++++++++------------------");
	g_math.enemy[0][6] = ft_strdup("--+++++++++------------------");
	g_math.enemy[0][7] = ft_strdup("---+++++++-------------------");
	g_math.enemy[0][8] = ft_strdup("----+++++--------------------");
	g_math.enemy[0][9] = ft_strdup("-----+++---------------------");

	g_math.enemy[0][10] = ft_strdup("-----------------------------");
	g_math.enemy[0][11] = ft_strdup("-----------------------------");
	g_math.enemy[0][12] = ft_strdup("-----------------------------");
	g_math.enemy[0][13] = ft_strdup("-----------------------------");
	g_math.enemy[0][14] = ft_strdup("-----------------------------");
	g_math.enemy[0][15] = ft_strdup("-----------------------------");
	g_math.enemy[0][16] = ft_strdup("-----------------------------");
	g_math.enemy[0][17] = ft_strdup("-----------------------------");
	g_math.enemy[0][18] = ft_strdup("-----------------------------");
	g_math.enemy[0][19] = ft_strdup("-----------------------------");

	g_math.enemy[0][20] = ft_strdup("-----------------------------");
	g_math.enemy[0][21] = ft_strdup("-----------------------------");
	g_math.enemy[0][22] = ft_strdup("-----------------------------");
	g_math.enemy[0][23] = ft_strdup("-----------------------------");
	g_math.enemy[0][24] = ft_strdup("-----------------------------");
	g_math.enemy[0][25] = ft_strdup("-----------------------------");
	g_math.enemy[0][26] = ft_strdup("-----------------------------");
	g_math.enemy[0][27] = ft_strdup("-----------------------------");
	g_math.enemy[0][28] = ft_strdup("-----------------------------");
	g_math.enemy[0][29] = ft_strdup("-----------------------------");
	g_math.enemy[0][30] = ft_strdup("-----------------------------");

	g_math.enemy[1] = malloc(sizeof(char*) * 31);
	g_math.enemy[1][0] = ft_strdup("-----------------------------");
	g_math.enemy[1][1] = ft_strdup("-----+++---------------------");
	g_math.enemy[1][2] = ft_strdup("----+++++--------------------");
	g_math.enemy[1][3] = ft_strdup("---+++++++-------------------");
	g_math.enemy[1][4] = ft_strdup("--+++++++++------------------");
	g_math.enemy[1][5] = ft_strdup("--+++++++++------------------");
	g_math.enemy[1][6] = ft_strdup("--+++++++++------------------");
	g_math.enemy[1][7] = ft_strdup("---+++++++-------------------");
	g_math.enemy[1][8] = ft_strdup("----+++++--------------------");
	g_math.enemy[1][9] = ft_strdup("-----+++---------------------");

	g_math.enemy[1][10] = ft_strdup("-----------------------------");
	g_math.enemy[1][11] = ft_strdup("-----------------------------");
	g_math.enemy[1][12] = ft_strdup("-----------------------------");
	g_math.enemy[1][13] = ft_strdup("-----------------------------");
	g_math.enemy[1][14] = ft_strdup("-----------------------------");
	g_math.enemy[1][15] = ft_strdup("-----------------------------");
	g_math.enemy[1][16] = ft_strdup("-----------------------------");
	g_math.enemy[1][17] = ft_strdup("-----------------------------");
	g_math.enemy[1][18] = ft_strdup("-----------------------------");
	g_math.enemy[1][19] = ft_strdup("-----------------------------");

	g_math.enemy[1][20] = ft_strdup("-----------------------------");
	g_math.enemy[1][21] = ft_strdup("-----------------------------");
	g_math.enemy[1][22] = ft_strdup("-----------------------------");
	g_math.enemy[1][23] = ft_strdup("-----------------------------");
	g_math.enemy[1][24] = ft_strdup("-----------------------------");
	g_math.enemy[1][25] = ft_strdup("-----------------------------");
	g_math.enemy[1][26] = ft_strdup("-----------------------------");
	g_math.enemy[1][27] = ft_strdup("-----------------------------");
	g_math.enemy[1][28] = ft_strdup("-----------------------------");
	g_math.enemy[1][29] = ft_strdup("-----------------------------");
	g_math.enemy[1][30] = ft_strdup("-----------------------------");

	g_math.enemy[2] = malloc(sizeof(char*) * 31);
	g_math.enemy[2][0] = ft_strdup("-----------------------------");
	g_math.enemy[2][1] = ft_strdup("-----+++---------------------");
	g_math.enemy[2][2] = ft_strdup("----+++++--------------------");
	g_math.enemy[2][3] = ft_strdup("---+++++++-------------------");
	g_math.enemy[2][4] = ft_strdup("--+++++++++------------------");
	g_math.enemy[2][5] = ft_strdup("--+++++++++------------------");
	g_math.enemy[2][6] = ft_strdup("--+++++++++------------------");
	g_math.enemy[2][7] = ft_strdup("---+++++++-------------------");
	g_math.enemy[2][8] = ft_strdup("----+++++--------------------");
	g_math.enemy[2][9] = ft_strdup("-----+++---------------------");

	g_math.enemy[2][10] = ft_strdup("-----------------------------");
	g_math.enemy[2][11] = ft_strdup("-----------------------------");
	g_math.enemy[2][12] = ft_strdup("-----------------------------");
	g_math.enemy[2][13] = ft_strdup("-----------------------------");
	g_math.enemy[2][14] = ft_strdup("-----------------------------");
	g_math.enemy[2][15] = ft_strdup("-----------------------------");
	g_math.enemy[2][16] = ft_strdup("-----------------------------");
	g_math.enemy[2][17] = ft_strdup("-----------------------------");
	g_math.enemy[2][18] = ft_strdup("-----------------------------");
	g_math.enemy[2][19] = ft_strdup("-----------------------------");

	g_math.enemy[2][20] = ft_strdup("-----------------------------");
	g_math.enemy[2][21] = ft_strdup("-----------------------------");
	g_math.enemy[2][22] = ft_strdup("-----------------------------");
	g_math.enemy[2][23] = ft_strdup("-----------------------------");
	g_math.enemy[2][24] = ft_strdup("-----------------------------");
	g_math.enemy[2][25] = ft_strdup("-----------------------------");
	g_math.enemy[2][26] = ft_strdup("-----------------------------");
	g_math.enemy[2][27] = ft_strdup("-----------------------------");
	g_math.enemy[2][28] = ft_strdup("-----------------------------");
	g_math.enemy[2][29] = ft_strdup("-----------------------------");
	g_math.enemy[2][30] = ft_strdup("-----------------------------");
	//write(1, "5", 1);
}
