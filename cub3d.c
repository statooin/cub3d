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

#include<string.h>

void	ft_mute_unmute_pid(char **cpid, char **cmute, char **cunmute)
{
        char	pidline[1024];
	char	*ctmp;
	FILE	*fp;

	ctmp = ft_strdup(""); ///re do ft_strjoin_f for NULL input - not ft_strdup
	ft_strjoin_f("bash mute_pid_echo.sh ", *cpid, &ctmp);
	printf ("%s\n", ctmp);

        fp = popen(ctmp,"r");
        fgets(pidline,1024,fp);
	printf("----------------------\n\n");
	printf ("%s\n", pidline);
	*cmute = ft_strdup(pidline);
	printf("----------------------\n\n");
	pclose(fp);

	ctmp = ft_strdup(""); ///re do ft_strjoin_f for NULL input - not ft_strdup
	ft_strjoin_f("bash unmute_pid_echo.sh ", *cpid, &ctmp);
	printf ("%s\n", ctmp);

        fp = popen(ctmp,"r");
        fgets(pidline,1024,fp);
	printf("----------------------\n\n");
	printf ("%s\n", pidline);
	*cunmute = ft_strdup(pidline);
	printf("----------------------\n\n");
	pclose(fp);
}

void	ft_pidof_last_mpg123(char **cpid)
{
        char pidline[1024];
        FILE *fp;

	fp = popen("pidof mpg123","r");
        fgets(pidline,1024,fp);
        printf("all pids: %s\n",pidline);
	*cpid = ft_strdup(strtok (pidline," "));
	pclose(fp);
}

/*
void	ft_pidof_first_mpg123(char **pid)
{
        char pidline[1024];
        //char *pid;
        //int i = 0;
        //int pidno[64];
        FILE *fp = popen("pidof mpg123","r");
        fgets(pidline,1024,fp);

        printf("%s",pidline);
        //pid = strtok (pidline," ");
	*pid = ft_strdup(strtok (pidline," "));
       while(pid != NULL)
	{
		pidno[i] = atoi(pid);
		g_snd.cstp_surf = ft_strdup(pid);
		printf("%d\n",pidno[i]);
		pid = strtok (NULL , " ");
		i++;
	}
	printf("%s\n\n", g_snd.cstp_surf);
	pclose(fp);
}
*/

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

void	ft_load_snd_steps()
{
	int	pid;

	printf("----------------------\n");
	pid = fork();
	if (pid == 0)
	{
		system("mpg123 -f 14000 -q --loop -1 sound/step_surf.mp3");
		exit(0);
	}
	printf("loaded step_surf\n");

ft_pause(1100);

	ft_pidof_last_mpg123(&g_snd.cstp_surf_pid);
	printf ("pid: %s\n", g_snd.cstp_surf_pid);
	system("pacmd list-sink-inputs | grep index");
	ft_mute_unmute_pid(&g_snd.cstp_surf_pid, &g_snd.cstp_surf_mu, &g_snd.cstp_surf_un);
	system(g_snd.cstp_surf_mu);
	printf("muted step_surf\n");
	printf("----------------------\n\n");
}

void	ft_load_snd_run()
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		system("mpg123 -f 14000 -q --loop -1 sound/run_surf.mp3");
		exit(0);
	}
	printf("loaded run_surf\n\n");

ft_pause(1100);

	ft_pidof_last_mpg123(&g_snd.crun_surf_pid);
	printf ("pid: %s\n", g_snd.crun_surf_pid);
	system("pacmd list-sink-inputs | grep index");
	ft_mute_unmute_pid(&g_snd.crun_surf_pid, &g_snd.crun_surf_mu, &g_snd.crun_surf_un);
	system(g_snd.crun_surf_mu);
	printf("muted run_surf\n");
	printf("----------------------\n\n");
}

void	ft_load_snd_music()
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		system("mpg123 -q -f 25000 sound/double_star.mp3");
		exit(0);
	}
	printf("loaded music\n\n");

ft_pause(2100);

	ft_pidof_last_mpg123(&g_snd.cmus_pid);
	printf ("pid: %s\n", g_snd.cmus_pid);
	system("pacmd list-sink-inputs | grep index");
	ft_mute_unmute_pid(&g_snd.cmus_pid, &g_snd.cmus_mu, &g_snd.cmus_un);
	system(g_snd.cmus_un);
	printf("unmuted music\n");
	printf("----------------------\n\n");
}

void	ft_load_snd_surf_ambient()
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		system("mpg123 -q -f 22000 --loop -1 sound/surf_amb.mp3");
		exit(0);
	}

ft_pause(1100);

	ft_pidof_last_mpg123(&g_snd.camp_surf_pid);
	printf ("pid: %s\n", g_snd.camp_surf_pid);
	printf("----------------------\n\n");
}

void	ft_load_maps()
{
	int	i;
	//int	j;
	//int	ilen;
	int	icount;
	char  *line;
	int   fd;

	icount = 0;
	fd = open("maps/map.map", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		icount++;
	}
	free(line);
	close(fd);

	g_math.map = malloc(sizeof(char*) * icount);

	i = 0;
	fd = open("maps/map.map", O_RDONLY);
	while (i < icount)
	{
		get_next_line(fd, &g_math.map[i]);
		printf("|%s\n", g_math.map[i]);
		i++;
	}
	close(fd);

	g_math.map_floor = malloc(sizeof(char*) * icount);

	//ilen = ft_strlen(g_math.map[0]);
	i = 0;
	fd = open("maps/floor.map", O_RDONLY);
	while (i < icount)
	{
		get_next_line(fd, &g_math.map_floor[i]);
		//j = -1;
		//while (++j <= ilen)
		//	if (g_math.map[i][j] == '.')
		//		g_math.map[i][j] = ' ';
		printf("|%s|\n", g_math.map_floor[i]);
		i++;
	}
	close(fd);
}

int	main(void)
{
	int	i_load_x;

	ft_cub_validation();

	ft_load_snd_steps();
	ft_load_snd_run();

	//g_game.iscr_width = ; //1280 1024	1280	1366	1600	1920;
//	g_game.iscr_height = ;//720 576	720	768	900	1080
	g_game.iscr_height_m1 = g_game.iscr_height - 1;
	g_game.iscr_width_m1 = g_game.iscr_width - 1;
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


	//ui loading
	g_tex.tex_ui_01.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/loading.xpm", &g_tex.tex_ui_01.width, &g_tex.tex_ui_01.height);
	g_tex.tex_ui_01.data = (int *)mlx_get_data_addr(g_tex.tex_ui_01.ptr, &g_tex.tex_ui_01.bpp, &g_tex.tex_ui_01.size_line, &g_tex.tex_ui_01.endian);
	g_tex.tex_ui_01.scale = 0.21;
	g_tex.tex_ui_01.step = 1 / g_tex.tex_ui_01.scale;

	ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, &g_tex.tex_ui_01, 30, g_game.iscr_height - 30); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);


	ft_load_snd_music();

	ft_load_maps();

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

/*
	ft_init_enemies(); //////!!!!!!!!!!
*/
	ft_put_objects(26, ft_strlen(g_math.map[0]) - 1);


	g_tex.tex_txt_01.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/text/txt_start.xpm", &g_tex.tex_txt_01.width, &g_tex.tex_txt_01.height);
	g_tex.tex_txt_01.data = (int *)mlx_get_data_addr(g_tex.tex_txt_01.ptr, &g_tex.tex_txt_01.bpp, &g_tex.tex_txt_01.size_line, &g_tex.tex_txt_01.endian);
	g_tex.tex_txt_01.scale = 0.8;
	g_tex.tex_txt_01.step = 1 / g_tex.tex_txt_01.scale;
	ft_put_scaled_img_to_win(&g_game.win_buf, &g_game, &g_tex.tex_txt_01, g_game.iscr_width05 + 30, 200); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);
// delete txt here!!!


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

	g_tex.tex_map_ui.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/ui/map_ui.xpm", &g_tex.tex_map_ui.width, &g_tex.tex_map_ui.height);
	g_tex.tex_map_ui.data = (int *)mlx_get_data_addr(g_tex.tex_map_ui.ptr, &g_tex.tex_map_ui.bpp, &g_tex.tex_map_ui.size_line, &g_tex.tex_muz_00.endian);
	g_tex.tex_map_ui.scale = 1;
	g_tex.tex_map_ui.step = 1 / g_tex.tex_map_ui.scale;
	g_tex.tex_map_ui.opacity = 0.7;
	g_tex.tex_map_ui.opacity_1 = 1 - 0.7;

	g_tex.tex_muz_00.ptr = mlx_xpm_file_to_image(g_game.mlx, "textures/gun/muzzle_flash_00.xpm", &g_tex.tex_muz_00.width, &g_tex.tex_muz_00.height);
	g_tex.tex_muz_00.data = (int *)mlx_get_data_addr(g_tex.tex_muz_00.ptr, &g_tex.tex_muz_00.bpp, &g_tex.tex_muz_00.size_line, &g_tex.tex_muz_00.endian);
	g_tex.tex_muz_00.scale = 1;
	g_tex.tex_muz_00.step = 1 / g_tex.tex_muz_00.scale;
	g_tex.tex_muz_00.opacity = 0.7;
	g_tex.tex_muz_00.opacity_1 = 1 - 0.7;

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

	i_load_x += 9;
	ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, &g_tex.tex_ui_02, i_load_x, g_game.iscr_height - 27); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);

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


	ft_init_floors_dist();


	i_load_x += 9;
	ft_put_scaled_img_lt_to_win(&g_game.win_buf, &g_game, &g_tex.tex_ui_02, i_load_x, g_game.iscr_height - 27); //del this
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, g_game.win_buf.ptr, 0, 0);

	g_game.dpy = XOpenDisplay(0);
	g_game.root_window = XRootWindow(g_game.dpy, 0);
	XSelectInput(g_game.dpy, g_game.root_window, KeyReleaseMask);


///////////////////////////////////////////////////
	g_snd.ccmd = ft_strdup("");
	ft_strjoin_f("kill -9 ", g_snd.cmus_pid, &g_snd.ccmd);
	printf ("%s\n", g_snd.ccmd);
	system(g_snd.ccmd);
	//kill((pid_t)ft_atoi(g_snd.cmus_surf), SIGINT); ///!!! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	ft_load_snd_surf_ambient();
	//g_plr.iplr_z = 300;
	//g_plr.fplr_x -= 0.01;
	//g_plr.fplr_a = -2;
	clstart = clock();
	g_plr.iplay_cut_scene = 1;

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
