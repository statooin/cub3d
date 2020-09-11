/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:26:18 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:42:44 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "src/src_gnl/read_cub.h"

void	ft_init_walls(void)
{
	g_tex.tex_wall = malloc(sizeof(t_img_n_tex) * 10);

	g_tex.tex_wall[5].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_1_L.xpm", &g_tex.tex_wall[5].width, &g_tex.tex_wall[5].height);
	g_tex.tex_wall[5].data = (int *)mlx_get_data_addr(g_tex.tex_wall[5].ptr, &g_tex.tex_wall[5].bpp, &g_tex.tex_wall[5].size_line, &g_tex.tex_wall[5].endian);
	g_tex.tex_wall[5].scale = 1;
	g_tex.tex_wall[5].height = g_tex.tex_wall[5].height - 1;
	g_tex.tex_wall[5].height_start = g_tex.tex_wall[5].height * 3 / 4; // 1/4 lower players head - 3/4 upper
	g_tex.tex_wall[5].iprior = 1;

	g_tex.tex_wall[6].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_2_L.xpm", &g_tex.tex_wall[6].width, &g_tex.tex_wall[6].height);
	g_tex.tex_wall[6].data = (int *)mlx_get_data_addr(g_tex.tex_wall[6].ptr, &g_tex.tex_wall[6].bpp, &g_tex.tex_wall[6].size_line, &g_tex.tex_wall[6].endian);
	g_tex.tex_wall[6].scale = 1;
	g_tex.tex_wall[6].height = g_tex.tex_wall[6].height - 1;
	g_tex.tex_wall[6].height_start = g_tex.tex_wall[6].height * 3 / 4; // 1/4 lower players head - 3/4 upper
	g_tex.tex_wall[6].iprior = 3;

	g_tex.tex_wall[7].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_3_L.xpm", &g_tex.tex_wall[7].width, &g_tex.tex_wall[7].height);
	g_tex.tex_wall[7].data = (int *)mlx_get_data_addr(g_tex.tex_wall[7].ptr, &g_tex.tex_wall[7].bpp, &g_tex.tex_wall[7].size_line, &g_tex.tex_wall[7].endian);
	g_tex.tex_wall[7].scale = 1;
	g_tex.tex_wall[7].height = g_tex.tex_wall[7].height - 1;
	g_tex.tex_wall[7].height_start = g_tex.tex_wall[7].height * 3 / 4; // 1/4 lower players head - 3/4 upper
	g_tex.tex_wall[7].iprior = 3;

	g_tex.tex_wall[8].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_4_L.xpm", &g_tex.tex_wall[8].width, &g_tex.tex_wall[8].height);
	g_tex.tex_wall[8].data = (int *)mlx_get_data_addr(g_tex.tex_wall[8].ptr, &g_tex.tex_wall[8].bpp, &g_tex.tex_wall[8].size_line, &g_tex.tex_wall[8].endian);
	g_tex.tex_wall[8].scale = 1;
	g_tex.tex_wall[8].height = g_tex.tex_wall[8].height - 1;
	g_tex.tex_wall[8].height_start = g_tex.tex_wall[8].height * 3 / 4; // 1/4 lower players head - 3/4 upper
	g_tex.tex_wall[8].iprior = 3;

	g_tex.tex_wall[1].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_1.xpm", &g_tex.tex_wall[1].width, &g_tex.tex_wall[1].height);
	g_tex.tex_wall[1].data = (int *)mlx_get_data_addr(g_tex.tex_wall[1].ptr, &g_tex.tex_wall[1].bpp, &g_tex.tex_wall[1].size_line, &g_tex.tex_wall[1].endian);
	g_tex.tex_wall[1].scale = 1;
	g_tex.tex_wall[1].height = g_tex.tex_wall[1].height - 1;
	g_tex.tex_wall[1].height_start = g_tex.tex_wall[1].height * 3 / 4; // 1/4 lower players head - 3/4 upper
	g_tex.tex_wall[1].iprior = 5;

	g_tex.tex_wall[2].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_2.xpm", &g_tex.tex_wall[2].width, &g_tex.tex_wall[2].height);
	g_tex.tex_wall[2].data = (int *)mlx_get_data_addr(g_tex.tex_wall[2].ptr, &g_tex.tex_wall[2].bpp, &g_tex.tex_wall[2].size_line, &g_tex.tex_wall[2].endian);
	g_tex.tex_wall[2].scale = 1;
	g_tex.tex_wall[2].height = g_tex.tex_wall[2].height - 1;
	g_tex.tex_wall[2].height_start = g_tex.tex_wall[2].height * 3 / 4; // 1/4 lower players head - 3/4 upper
	g_tex.tex_wall[2].iprior = 6;

	g_tex.tex_wall[3].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_3.xpm", &g_tex.tex_wall[3].width, &g_tex.tex_wall[3].height);
	g_tex.tex_wall[3].data = (int *)mlx_get_data_addr(g_tex.tex_wall[3].ptr, &g_tex.tex_wall[3].bpp, &g_tex.tex_wall[3].size_line, &g_tex.tex_wall[3].endian);
	g_tex.tex_wall[3].scale = 1;
	g_tex.tex_wall[3].height = g_tex.tex_wall[3].height - 1;
	g_tex.tex_wall[3].height_start = g_tex.tex_wall[3].height * 3 / 4; // 1/4 lower players head - 3/4 upper
	g_tex.tex_wall[3].iprior = 8;

	g_tex.tex_wall[4].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_4.xpm", &g_tex.tex_wall[4].width, &g_tex.tex_wall[4].height);
	g_tex.tex_wall[4].data = (int *)mlx_get_data_addr(g_tex.tex_wall[4].ptr, &g_tex.tex_wall[4].bpp, &g_tex.tex_wall[4].size_line, &g_tex.tex_wall[4].endian);
	g_tex.tex_wall[4].scale = 1;
	g_tex.tex_wall[4].height = g_tex.tex_wall[4].height - 1;
	g_tex.tex_wall[4].height_start = g_tex.tex_wall[4].height * 3 / 4; // 1/4 lower players head - 3/4 upper
	g_tex.tex_wall[4].iprior = 8;
}

int	main(void)
{
	int	i_load_x;

	ft_cub_validation();


	//g_game.iscr_width = ; //1280 1024	1280	1366	1600	1920;
//	g_game.iscr_height = ;//720 576	720	768	900	1080
	g_game.iscr_height_m1 = g_game.iscr_height - 1;
	g_game.iscr_width05 = g_game.iscr_width / 2;
	g_game.iscr_height05 = g_game.iscr_height / 2;

	g_game.mlx = mlx_init();
	g_game.mlx_win = mlx_new_window(g_game.mlx, g_game.iscr_width, g_game.iscr_height, "Amada system - Anjea's moon");

	g_game.win_buf0.ptr = mlx_new_image(g_game.mlx, g_game.iscr_width, g_game.iscr_height);
	g_game.win_buf0.addr = mlx_get_data_addr(g_game.win_buf0.ptr, &g_game.win_buf0.bpp, &g_game.win_buf0.size_line, &g_game.win_buf0.endian);
	g_game.win_buf0.data = (int *)mlx_get_data_addr(g_game.win_buf0.ptr, &g_game.win_buf0.bpp, &g_game.win_buf0.size_line, &g_game.win_buf0.endian);
	g_game.win_buf0.bpp_8 = g_game.win_buf0.bpp / 8;

	g_game.win_buf1.ptr = mlx_new_image(g_game.mlx, g_game.iscr_width, g_game.iscr_height);
	g_game.win_buf1.addr = mlx_get_data_addr(g_game.win_buf1.ptr, &g_game.win_buf1.bpp, &g_game.win_buf1.size_line, &g_game.win_buf1.endian);
	g_game.win_buf1.data = (int *)mlx_get_data_addr(g_game.win_buf1.ptr, &g_game.win_buf1.bpp, &g_game.win_buf1.size_line, &g_game.win_buf1.endian);
	g_game.win_buf1.bpp_8 = g_game.win_buf1.bpp / 8;

	g_game.win_buf.ptr = mlx_new_image(g_game.mlx, g_game.iscr_width, g_game.iscr_height);
	g_game.win_buf.addr = mlx_get_data_addr(g_game.win_buf.ptr, &g_game.win_buf.bpp, &g_game.win_buf.size_line, &g_game.win_buf.endian);
	g_game.win_buf.data = (int *)mlx_get_data_addr(g_game.win_buf.ptr, &g_game.win_buf.bpp, &g_game.win_buf.size_line, &g_game.win_buf.endian);

	g_game.win_buf.ptr = g_game.win_buf0.ptr;
	g_game.win_buf.addr = g_game.win_buf0.addr;
	g_game.win_buf.data = g_game.win_buf0.data;
	g_game.win_buf.bpp_8 = g_game.win_buf.bpp / 8;


	int	pid;
	pid = fork();
	if (pid == 0)
	{
		system("mpg123 -q -f 25000 sound/double_star.mp3");
		exit(0);
	}
	pid += 2;
	printf ("pid = %d\n", pid);

	//ui loading
	g_tex.tex_ui_01.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/loading.xpm", &g_tex.tex_ui_01.width, &g_tex.tex_ui_01.height);
	g_tex.tex_ui_01.data = (int *)mlx_get_data_addr(g_tex.tex_ui_01.ptr, &g_tex.tex_ui_01.bpp, &g_tex.tex_ui_01.size_line, &g_tex.tex_ui_01.endian);
	g_tex.tex_ui_01.scale = 0.21;
	g_tex.tex_ui_01.step = 1 / g_tex.tex_ui_01.scale;

	ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, &g_tex.tex_ui_01, 30, g_game.iscr_height - 30); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);


	 g_math.map = malloc(sizeof(char*) * 27);
	 g_math.map[0] = ft_strdup("############################################");
	 g_math.map[1] = ft_strdup("#341234234123411123411234312341234123412341#");
	 g_math.map[2] = ft_strdup("#26  1  2345      123423 347              2#");
	 g_math.map[3] = ft_strdup("#1        7   13    12                    2#");
	 g_math.map[4] = ft_strdup("#4    56       24       4    56       24   #");
	 g_math.map[5] = ft_strdup("#347  8    3    1234   347  8    3    1234##");
	 g_math.map[6] = ft_strdup("#2       1243      23 22       1243      23#");
	 g_math.map[7] = ft_strdup("#1     1234#2341             1234#2341    2#");
	 g_math.map[8] = ft_strdup("#23  623#######123  21234  623#######123  2#");
	 g_math.map[9] = ft_strdup("##42  74##1234###4  33##42  74##1234###2 51#");
	g_math.map[10] = ft_strdup("#321   1234 1234#12  4#321   1234 1234#1234#");
	g_math.map[11] = ft_strdup("#26   43      12##33 14#26  43      12######");
	g_math.map[12] = ft_strdup("#3   12   5    23##432##3   12   5   23#####");
	g_math.map[13] = ft_strdup("#4        6     34#####4        6     34####");
	g_math.map[14] = ft_strdup("#11    7     3   45####11    7     3   45###");
	g_math.map[15] = ft_strdup("##21   5     21   1#####21   5     21   1###");
	g_math.map[16] = ft_strdup("###23             2######23             2###");
	g_math.map[17] = ft_strdup("####21    431     3#######21    431     3###");
	g_math.map[18] = ft_strdup("####17   73#25   12#######17   73#25   12###");
	g_math.map[19] = ft_strdup("##436     123   24#######36     123   24####");
	g_math.map[20] = ft_strdup("#43            12######43            12#####");
	g_math.map[21] = ft_strdup("#1  1      7   3#######1  1      7   3######");
	g_math.map[22] = ft_strdup("#2            12#######2            12######");
	g_math.map[23] = ft_strdup("#321   n     12########321         12#######");
	g_math.map[24] = ft_strdup("###21      123###########21      123########");
	g_math.map[25] = ft_strdup("###1111234114############1111234114#########");
	g_math.map[26] = ft_strdup("############################################");

	g_math.map_floor = malloc(sizeof(char*) * 27);
	g_math.map_floor[0] = ft_strdup("                                            ");
	g_math.map_floor[1] = ft_strdup("                                            ");
	g_math.map_floor[2] = ft_strdup("   12 12   1212122      2   12121212121212  ");
	g_math.map_floor[3] = ft_strdup("  12121212 122  1212  12121212121212121212  ");
	g_math.map_floor[4] = ft_strdup("  12122 1212122  1212122 12122 1212122  122 ");
	g_math.map_floor[5] = ft_strdup("    12 1212 1212    122   12 1212 1212      ");
	g_math.map_floor[6] = ft_strdup("  1212122    121212  2  1212122    121212   ");
	g_math.map_floor[7] = ft_strdup("  12122         1212121212122         1212  ");
	g_math.map_floor[8] = ft_strdup("   12             12     12             12  ");
	g_math.map_floor[9] = ft_strdup("    12            12      12            12  ");
	g_math.map_floor[10] = ft_strdup("    122    2       12     122    2          ");
	g_math.map_floor[11] = ft_strdup("   122  121212      2     12  121212        ");
	g_math.map_floor[12] = ft_strdup("  122  12121212          122  1212122       ");
	g_math.map_floor[13] = ft_strdup("  12121212 12122        12121212 12122      ");
	g_math.map_floor[14] = ft_strdup("   1212 12122 122 2      1212 12122 122 2   ");
	g_math.map_floor[15] = ft_strdup("    121212122  122        121212122  122    ");
	g_math.map_floor[16] = ft_strdup("     1212121212122         1212121212122    ");
	g_math.map_floor[17] = ft_strdup("      1212   12122          1212   12122    ");
	g_math.map_floor[18] = ft_strdup("      122    1212           122    1212     ");
	g_math.map_floor[19] = ft_strdup("     12122   122           12122   122      ");
	g_math.map_floor[20] = ft_strdup("   121212121212          121212121212       ");
	g_math.map_floor[21] = ft_strdup("  12 121212 122         12 121212 122       ");
	g_math.map_floor[22] = ft_strdup("  121212121212          121212121212        ");
	g_math.map_floor[23] = ft_strdup("    121212122             121212122         ");
	g_math.map_floor[24] = ft_strdup("     121212                121212           ");
	g_math.map_floor[25] = ft_strdup("                                            ");
	g_math.map_floor[26] = ft_strdup("                                            ");

	g_plr.fplr_z0 = -0.6f; //player's "height"
	g_plr.fplr_zhead = 1.0f; // !! ?? how to crouch ctrl
	g_consts.ffov = 3.14159 / 3.2; // /8 !! need fix with / 3.0  // field of view 15.0-20.0 this id sniper zoom!! )))
	g_consts.ffov_vert = g_consts.ffov;
	g_consts.ffloor_ang0 = PI / 2.0f - g_consts.ffov_vert / 2.0f;
	g_consts.ffov05 = g_consts.ffov / 2.0f;
	g_plr.fplr_v = 0.04f;
	g_consts.fray_ang_step = 1.0f / (float)g_game.iscr_width * g_consts.ffov;
	g_consts.fray_ang_step2 = g_consts.fray_ang_step * 2;
	g_consts.ffloor_ang_step = 1.0f / (float)(g_game.iscr_height) * g_consts.ffov_vert;
	g_consts.ffloor_ang_step2 = g_consts.ffloor_ang_step * 2;
	g_consts.fstep_check = 0.01f; // !!! 0.03f 0.01f
	g_math.isky_x = - g_tex.tex_sky.width / 2;
	g_plr.uikeys_prsd = PRSD_NONE;
	g_plr.iplr_z = 0;//player.g_plr.fplr_z0;


	/*LETA_start HP
	  g_tex.tex_hp = malloc(sizeof(t_img_n_tex) * 5);
	  g_tex.tex_hp[1].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/healthbar3.xpm", &g_tex.tex_hp[1].width, &g_tex.tex_hp[1].height);
	  g_tex.tex_hp[1].data = (int *)mlx_get_data_addr(g_tex.tex_hp[1].ptr, &g_tex.tex_hp[1].bpp, &g_tex.tex_hp[1].size_line, &g_tex.tex_hp[1].endian);
	  g_tex.tex_hp[1].scale = 1;
	  g_tex.tex_hp[2].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/healthbar2.xpm", &g_tex.tex_hp[2].width, &g_tex.tex_hp[2].height);
	  g_tex.tex_hp[2].data = (int *)mlx_get_data_addr(g_tex.tex_hp[2].ptr, &g_tex.tex_hp[2].bpp, &g_tex.tex_hp[2].size_line, &g_tex.tex_hp[2].endian);
	  g_tex.tex_hp[2].scale = 1;
	  g_tex.tex_hp[3].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/healthbar1.xpm", &g_tex.tex_hp[3].width, &g_tex.tex_hp[3].height);
	  g_tex.tex_hp[3].data = (int *)mlx_get_data_addr(g_tex.tex_hp[3].ptr, &g_tex.tex_hp[3].bpp, &g_tex.tex_hp[3].size_line, &g_tex.tex_hp[3].endian);
	  g_tex.tex_hp[3].scale = 1;
	  g_tex.tex_hp[4].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/healthbar0.xpm", &g_tex.tex_hp[4].width, &g_tex.tex_hp[4].height);
	  g_tex.tex_hp[4].data = (int *)mlx_get_data_addr(g_tex.tex_hp[4].ptr, &g_tex.tex_hp[4].bpp, &g_tex.tex_hp[4].size_line, &g_tex.tex_hp[4].endian);
	  g_tex.tex_hp[4].scale = 1;
	  LETA_end HP*/

	ft_init_shields();
	ft_init_armor();
	ft_init_walls();

	if (g_game.iscr_width == 1920)
		g_tex.tex_vign.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/vignette19201080.xpm", &g_tex.tex_vign.width, &g_tex.tex_vign.height);
	else
		g_tex.tex_vign.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/vignette_1280_720.xpm", &g_tex.tex_vign.width, &g_tex.tex_vign.height);
	g_tex.tex_vign.data = (int *)mlx_get_data_addr(g_tex.tex_vign.ptr, &g_tex.tex_vign.bpp, &g_tex.tex_vign.size_line, &g_tex.tex_vign.endian);
	g_tex.tex_vign.scale = 1;//(float)g_game.iscr_height / g_tex.tex_vign.height; // !! wrong
	g_tex.tex_vign.step = 1 / g_tex.tex_vign.scale;
	g_tex.tex_vign.opacity = 0.8;
	g_tex.tex_vign.opacity_1 = 1 - 0.8;

	ft_init_vignette(&g_game, &g_tex.tex_vign);

	g_tex.tex_muz_00.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/gun/muzzle_flash_00.xpm", &g_tex.tex_muz_00.width, &g_tex.tex_muz_00.height);
	g_tex.tex_muz_00.data = (int *)mlx_get_data_addr(g_tex.tex_muz_00.ptr, &g_tex.tex_muz_00.bpp, &g_tex.tex_muz_00.size_line, &g_tex.tex_muz_00.endian);
	g_tex.tex_muz_00.scale = 1;
	g_tex.tex_muz_00.step = 1 / g_tex.tex_muz_00.scale;
	g_tex.tex_muz_00.opacity = 0.7;
	g_tex.tex_muz_00.opacity_1 = 1 - 0.7;


	g_tex.tex_txt_01.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/text/txt_start.xpm", &g_tex.tex_txt_01.width, &g_tex.tex_txt_01.height);
	g_tex.tex_txt_01.data = (int *)mlx_get_data_addr(g_tex.tex_txt_01.ptr, &g_tex.tex_txt_01.bpp, &g_tex.tex_txt_01.size_line, &g_tex.tex_txt_01.endian);
	g_tex.tex_txt_01.scale = 0.8;
	g_tex.tex_txt_01.step = 1 / g_tex.tex_txt_01.scale;
	ft_put_scaled_img_to_win(&g_game.win_buf, &g_game, &g_tex.tex_txt_01, g_game.iscr_width05 + 30, 200); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);
// delete txt here!!!

	ft_init_enemies();
	ft_put_objects(26, ft_strlen(g_math.map[0]) - 1);

	g_tex.tex_ui_02.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/loading_bar.xpm", &g_tex.tex_ui_02.width, &g_tex.tex_ui_02.height);
	g_tex.tex_ui_02.data = (int *)mlx_get_data_addr(g_tex.tex_ui_02.ptr, &g_tex.tex_ui_02.bpp, &g_tex.tex_ui_02.size_line, &g_tex.tex_ui_02.endian);
	g_tex.tex_ui_02.scale = 0.21;
	g_tex.tex_ui_02.step = 1 / g_tex.tex_ui_02.scale;

	i_load_x = 93;
	ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, &g_tex.tex_ui_02, i_load_x, g_game.iscr_height - 27); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);

	g_math.ibottom_sky = malloc(sizeof(int) * g_game.iscr_width);

	g_tex.tex_sky.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/sky1.xpm", &g_tex.tex_sky.width, &g_tex.tex_sky.height);
	g_tex.tex_sky.data = (int *)mlx_get_data_addr(g_tex.tex_sky.ptr, &g_tex.tex_sky.bpp, &g_tex.tex_sky.size_line, &g_tex.tex_sky.endian);
	g_tex.tex_sky.scale = 1;
	g_tex.tex_sky.step = 1 / g_tex.tex_sky.scale;

	i_load_x += 9;
	ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, &g_tex.tex_ui_02, i_load_x, g_game.iscr_height - 27); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);

	g_tex.tex_c_line.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/crossline.xpm", &g_tex.tex_c_line.width, &g_tex.tex_c_line.height);
	g_tex.tex_c_line.data = (int *)mlx_get_data_addr(g_tex.tex_c_line.ptr, &g_tex.tex_c_line.bpp, &g_tex.tex_c_line.size_line, &g_tex.tex_c_line.endian);
	g_tex.tex_c_line.scale = 0.35; //!re do this! whithout scale!!
	g_tex.tex_c_line.step = 1 / g_tex.tex_c_line.scale;
	g_tex.tex_c_line.opacity = 0.7;
	g_tex.tex_c_line.opacity_1 = 1 - 0.7;

	g_tex.tex_c_line_h.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/crossline_h.xpm", &g_tex.tex_c_line_h.width, &g_tex.tex_c_line_h.height);
	g_tex.tex_c_line_h.data = (int *)mlx_get_data_addr(g_tex.tex_c_line_h.ptr, &g_tex.tex_c_line_h.bpp, &g_tex.tex_c_line_h.size_line, &g_tex.tex_c_line_h.endian);
	g_tex.tex_c_line_h.scale = 0.35;
	g_tex.tex_c_line_h.step = 1 / g_tex.tex_c_line_h.scale;
	g_tex.tex_c_line_h.opacity = 0.7;
	g_tex.tex_c_line_h.opacity_1 = 1 - 0.7;


	g_tex.tex_floor = malloc(sizeof(t_img_n_tex) * 10);

	g_tex.tex_floor[0].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/wall_s.xpm", &g_tex.tex_floor[0].width, &g_tex.tex_floor[0].height);
	g_tex.tex_floor[0].data = (int *)mlx_get_data_addr(g_tex.tex_floor[0].ptr, &g_tex.tex_floor[0].bpp, &g_tex.tex_floor[0].size_line, &g_tex.tex_floor[0].endian);
	g_tex.tex_floor[0].scale = 1;

	g_tex.tex_floor[1].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/floor_rock_2.xpm", &g_tex.tex_floor[1].width, &g_tex.tex_floor[1].height);
	g_tex.tex_floor[1].data = (int *)mlx_get_data_addr(g_tex.tex_floor[1].ptr, &g_tex.tex_floor[1].bpp, &g_tex.tex_floor[1].size_line, &g_tex.tex_floor[1].endian);
	g_tex.tex_floor[1].scale = 1;

	g_tex.tex_floor[2].ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/floor_rock_1.xpm", &g_tex.tex_floor[2].width, &g_tex.tex_floor[2].height);
	g_tex.tex_floor[2].data = (int *)mlx_get_data_addr(g_tex.tex_floor[2].ptr, &g_tex.tex_floor[2].bpp, &g_tex.tex_floor[2].size_line, &g_tex.tex_floor[2].endian);
	g_tex.tex_floor[2].scale = 1;


	i_load_x += 9;
	ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, &g_tex.tex_ui_02, i_load_x, g_game.iscr_height - 27); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);


	/* // 2d x y array for x y textures - not plain ones
	   tex_floor2 = malloc(sizeof(int**) * 10);
	   int	i = 0;
	   while (i <= 2)
	   {
	   tex_floor2[i] = malloc(sizeof(int*) * tex_floor[i].height);
	   y = 0;
	   while (y < tex_floor[i].height)
	   {
	   tex_floor2[i][y] = malloc(sizeof(int) * tex_floor[i].width);
	   x = 0;
	   while (x < tex_floor[i].width)
	   {
	   tex_floor2[i][y][x] = tex_floor[i].data[y * tex_floor[i].width + x];
	   x++;
	   }
	   y++;
	   }
	   i++;
	   }
	   mlx_destroy_image(g_game.mlx, tex_floor[0].ptr);
	   mlx_destroy_image(g_game.mlx, tex_floor[1].ptr);
	   mlx_destroy_image(g_game.mlx, tex_floor[2].ptr);
	 */



	ft_init_floors_dist();


	i_load_x += 9;
	ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, &g_tex.tex_ui_02, i_load_x, g_game.iscr_height - 27); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);

	g_game.dpy = XOpenDisplay(0);
	g_game.root_window = XRootWindow(g_game.dpy, 0);
	XSelectInput(g_game.dpy, g_game.root_window, KeyReleaseMask);

	kill(pid, SIGINT); ///!!! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	pid = fork();
	if (pid == 0)
	{
		system("mpg123 -q -f 22000 --loop -1 sound/surf_amb.mp3");
		exit(0);
	}
	pid += 2;
	printf ("pid = %d\n", pid);

	mlx_hook(g_game.mlx_win, 2, 1L << 0, ft_key_press, &g_game.mlx_win);
	mlx_hook(g_game.mlx_win, 3, 1L << 1, ft_key_release, &g_game.mlx_win);
	mlx_hook(g_game.mlx_win, 4, 1L << 2, ft_mouse_click, &g_game.mlx_win);
	mlx_hook(g_game.mlx_win, 6, 1L << 6, ft_mouse_move, &g_game.mlx_win);
	mlx_loop_hook(g_game.mlx, ft_draw_world, &g_game.mlx_win);
	mlx_hook(g_game.mlx_win, 17, 1L << 17, ft_close, &g_game.mlx_win);
	mlx_loop(g_game.mlx);

	/*
	   mlx_hook(t_game->win, 2, 1L << 0, key_press, g_game);
	   mlx_hook(t_game->win, 3, 1L << 1, key_release, g_game);
	   mlx_hook(t_game->win, 17, 1L << 17, close_game, g_game);
	   mlx_loop_hook(g_game.mlx, game_loop, g_game);
	 */

	return (1);
}
