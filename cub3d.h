/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:00:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/14 15:25:42 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>
# include <termios.h>
# include <locale.h>
# include <time.h>
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <signal.h>
# include "src/src_gnl/read_cub.h"

# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_A		97
# define KEY_D		100
# define KEY_W		119
# define KEY_S		115
# define KEY_SPACE	32
# define KEY_ESC	65307
# define KEY_SHIFT	65505
# define KEY_CTRL	65507
# define KEY_I		105
# define KEY_M		109
# define KEY_Q		113
# define KEY_E		101
# define KEY_R		114
# define KEY_H		104

# define PI 3.14159

# define SHOWN_NONE		0b0000000000000000
# define SHOWN_MAP		0b0000000000000001
# define SHOWN_WEAP		0b0000000000000010
# define SHOWN_HAND		0b0000000000000100

# define PRSD_NONE		0b0000000000000000
# define PRSD_LEFT		0b0000000000000001
# define PRSD_RIGHT		0b0000000000000010
# define PRSD_UP_W		0b0000000000000100
# define PRSD_DOWN_S		0b0000000000001000
# define PRSD_A		0b0000000000010000
# define PRSD_D		0b0000000000100000
# define PRSD_H		0b0000000001000000
# define PRSD_ESC		0b0000000010000000
# define PRSD_SHIFT		0b0000000100000000
# define PRSD_CTRL		0b0000001000000000
# define PRSD_I		0b0000010000000000
# define PRSD_M		0b0000100000000000
# define PRSD_LC		0b0001000000000000
# define PRSD_E		0b0010000000000000

typedef struct			s_img_n_tex
{
	int					size_line;
	int					bpp; //bits_per_pixel
	int					bpp_8; //bits_per_pixel / 8
	int					width;
	int					height;
	int					height_start;
	XShmSegmentInfo		shm;
	int					*data;
	float				scale;
	float				step;
	float				opacity;
	float				opacity_1;
	int					iprior;
	void				*ptr;
	char				*addr;
	int					endian;
}						t_img_n_tex;

typedef struct			s_game
{
	t_img_n_tex			win_buf;
	t_img_n_tex			win_buf0;
	t_img_n_tex			win_buf1;
	int					iscr_width;
	int					iscr_height;
	int					iceilling_col;
	int					ifloor_col;
	int					iscr_width_m1;
	int					iscr_height_m1;
	int					iscr_width05;
	int					iscr_height05;
	void				*mlx;
	void				*mlx_win;
	void				*win;
	Display				*dpy;
	Window				root_window;
}						t_game;

typedef struct			s_snd
{
	char				*cstp_surf_mu;
	char				*crun_surf_mu;
	char				*cmus_mu;
	char				*camp_surf_pid;
	char				*cstp_surf_un;
	char				*crun_surf_un;
	char				*cmus_un;
	char				*cstp_surf_pid;
	char				*crun_surf_pid;
	char				*cmus_pid;
	char				*ccmd;
	int					isteps;
	int					irun;
}						t_snd;

typedef struct			s_player
{
	float				fplr_x; // player's position on X
	float				fplr_y; // player's position on Y
	float				fplr_z0; //player's "height"
	int					iplr_z; // player's position on Z (can change in jump)
	float				fplr_zhead; // player's position on Z (for floor)
	float				fplr_a; // player's VIEW angle (the dorection of rays to visible walls)
	float				fplr_v; //player's step speed
	int					iplr_shield;
	int					iplr_armor;
	clock_t				cl_regen;
	unsigned int		uikeys_prsd;
	int					hp_count; // = 1
	int					iplay_cut_scene;
	//int					iplay_ui;
}						t_player;
//int iKeyOff; // duration of jump
//int iInJump = 0; // check if in jump
//	float				fplr_jumpv; //player's speed in jump
//	float				fPlayerVA; // player's direction of speed in jump

typedef struct			s_const
{
	float				ffov; // field of view 15.0-20.0 this id sniper zoom!! )))
	float				ffov05;
	float				ffov_width;
	float				ffov_vert;
	float				ffloor_ang0;
	float				fsinf_ang_step;
	float				fcosf_ang_step;
	float				fray_ang_step;
	float				ffloor_ang_step;
	float				fray_ang_step2;
	float				ffloor_ang_step2;
	float				fstep_check;
}						t_const;

typedef struct			s_ui_anim
{
	unsigned int		uishown;
	clock_t	clstart;
	int	istart_x;
	int	istart_y;
	int	istop_x;
	int	istop_y;
	int	istop_msec;
	float	fstart_scale;
	float	fstop_scale;
	float	fstart_opac;
	float	fstop_opac;
	int	ianim;
	t_img_n_tex			*tex_anim;
}						t_ui_anim;

typedef struct			s_math
{
	int					imap_h;
	int					imap_w;
	char				**map;
	int					*ibottom_sky;
	char				**map_floor;
	char				***enemy;
	float				**fvignette;
	float				ftest_x;
	float				ftest_y;
	float				**fdist_to_all_tiles;
	int					ishot;
	float					isky_x; // coordinates of sprites
	int					iray_x; // ray in the window, that makes the picture
	int					ienemy_n;
	int					ienemies_active;
}						t_math;

typedef struct			s_objects
{
	char				ctype;
	int					ipriority;
	float				fdist;
	int				itest_x;
	float				ftest_x;
	float				ftest_y;
}						t_objects;

typedef struct			s_tex
{
	t_img_n_tex			tex_ui_01;
	t_img_n_tex			tex_ui_02;
	t_img_n_tex			tex_txt_01;
	t_img_n_tex			tex_vign;
	t_img_n_tex			tex_sky;
	t_img_n_tex			*tex_wall;
	t_img_n_tex			*tex_hp;
	t_img_n_tex			*tex_floor;
	t_img_n_tex			**en_anim;
	t_img_n_tex			*tex_shield;
	t_img_n_tex			tex_c_line;
	t_img_n_tex			tex_c_line_h;
	t_img_n_tex			tex_muz_00;
	t_img_n_tex			*tex_armor;
	t_img_n_tex			tex_map_ui;
}						t_tex;
//int	***tex_floor2;

typedef struct	s_enemy
{
	float	fenemy_width;
	float	fenemy_stepw;
	float	fenemy_texh_step;
	float	fe_count_w;
	float	fenemy_h;
	int		ienemy_width; // take from struct
	float	ienemy_top; // take from struct
	float	fenemy_bottom; // take from struct
	float	fenemy_tall; // take from struct
	int		en_anim_i;
	int		ienemy_y;
	int		ienemy_x;
	int		ifirst_rayx;
	int		iaimed;
	clock_t	cl_move;
	clock_t	cl_shoot;
}				t_enemy;

t_enemy	*g_enemies;
t_game	g_game;
t_player	g_plr;
t_const	g_consts;
t_math	g_math;
t_tex	g_tex;
t_snd	g_snd;
t_ui_anim	g_ui_anim;

clock_t fps; //delete this - for fps
clock_t clstart;

int		ft_close();
void	ft_draw_crosshair();
void	ft_draw_enemy(float *fdist_to_wall);
void	ft_draw_floor();
void	ft_draw_hp();
void	ft_draw_simple_color_floor();
void	ft_draw_simple_color_sky();
void	ft_draw_skybox();
void	ft_draw_vignette();//t_img_n_tex *win_buf, t_game *g_game);
void	ft_draw_wall_stripe(float *fray_ang, int *itest_x, int *ihit_wall, float *fdist_to_wall, float *ftest_x, float *ftest_y);
void	ft_draw_wall_stripes_all(float *fray_ang, t_objects *obj, int *i);
void	ft_draw_walls();
int		ft_draw_weapon();
int		ft_draw_world();
void	ft_enemy_act();
int		ft_enemy_aim();
void	ft_enemy_move();
void	ft_enemy_shoot();
int		ft_floor_color(int *ihit_floor, float *ffloor_tilex,
	float *ffloor_tiley, int *idraw_y);
void	ft_fps(int itime);
void	ft_holster_weapon();
void	ft_init_armor();
void	ft_init_enemies();
int		ft_init_floors_dist();
void	ft_init_shields();
void	ft_init_shields();
int		ft_init_vignette(t_game *g_game, t_img_n_tex *tex_vign);
void	ft_key_actions();
void	ft_key_e();
int		ft_key_press(int ikey);
int		ft_key_release(int ikey);
void	ft_left_enemies_prescan();
void	ft_mlx_pixel_put(t_img_n_tex *data, int *x, int *y, int *color);
float	ft_most_far_wall(float *fray_ang, int *ipriority);
int		ft_mouse_click(int ikey);
int		ft_mouse_move(int x, int y);
int		ft_move_enemy_down();
int		ft_move_enemy_left();
int		ft_move_enemy_right();
int		ft_move_enemy_up();
void	ft_next_anim();
void	ft_pause(int trigger);
void	ft_player_shot();
void	ft_put_img_lt_to_win(t_img_n_tex *win_buf, t_game *g_game,
	t_img_n_tex *tex_01, int img_x_start, int img_y_start);
void	ft_put_objects(int y, int x0);
void	ft_put_scaled_img_lt_to_win(t_img_n_tex *win_buf, t_game *g_game,
	t_img_n_tex *tex_01, int img_x_start, int img_y_start);
void	ft_put_scaled_opac_img_lt_to_win(t_img_n_tex *win_buf,
	t_game *g_game, t_img_n_tex *tex_01, int img_x_start, int img_y_start);
void	ft_put_scaled_img_to_win(t_img_n_tex *win_buf, t_game *g_game,
	t_img_n_tex *tex_01, int img_x_center, int img_y_center);
void	ft_put_scaled_opac_img_to_win(t_img_n_tex *win_buf, t_game *g_game,
	t_img_n_tex *tex_01, int img_x_center, int img_y_center);
void	ft_reset_enemies();
void	ft_savebmp();
int		ft_shades(int *color, float *fdist_to_wall);
void	ft_shields();

#endif
