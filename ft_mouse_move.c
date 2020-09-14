/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:10:20 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:10:49 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse_move(int x, int y)
{
	static int	old_x;
	//static int	old_y;
	int	x_step;

	if (g_plr.iplay_cut_scene != 0)
		return (1);

	if (x < 100)  // need fix g_math here - need to know windows coords
	{
		old_x = g_game.iscr_width - 150;
		x = old_x;
		XWarpPointer(g_game.dpy, None, g_game.root_window, 0, 0, 0, 0, old_x, y);
		XFlush(g_game.dpy);
		/*
		//Window child;
		int winPos[2];
		Window root;
		Window child;
		root =  XRootWindow(g_game.dpy, 0);
		XTranslateCoordinates(g_game.dpy, g_game.root_window, root, 0, 0, &winPos[0], &winPos[1], &child);
		printf("%d %d\n", winPos[0], winPos[1]);
		 */
	}
	else if (x > g_game.iscr_width - 100)
	{
		old_x = 150;
		x = old_x;
		XWarpPointer(g_game.dpy, None, g_game.root_window, 0, 0, 0, 0, old_x, y);
		XFlush(g_game.dpy);
	}
	x_step = old_x - x;
	if (x_step > -150 && x_step < 150)
	{
		g_plr.fplr_a += 0.0012f * x_step;
		g_math.isky_x += 0.0012f * x_step * 650; // need check g_math
		//g_math.isky_x = g_plr.fplr_a * 800; // need check g_math
		if (g_math.isky_x > 0)
			g_math.isky_x = - g_tex.tex_sky.width / 2;
		else if (g_math.isky_x < - g_tex.tex_sky.width / 2)
			g_math.isky_x = 0;
	}
	old_x = x;
	//if (y < g_game.iscr_height05)// && g_plr.iplr_z < 200.0)
	g_plr.iplr_z = (int)((float)(g_game.iscr_height05 - y) / 1.5f);
	//if (ikey || old_y) //delete this - and how left click ???
	//	old_y = y;
	//ft_key(mlx_win);
	//if (g_plr.iplr_z < 200.0)
	//	g_plr.iplr_z += 2.0f;
	/*
	   int* getWindowPos(Display *g_game.dpy, Window *curWin)
	   {
	   int winPos[2];
	   unsigned int width, height, bwidth, depth;
	//Window root;
	Window child;
	root =  XRootWindow(GLWin.g_game.dpy, 0);
	//XGetGeometry(g_game.dpy, *curWin, &root, &winPos[0], &winPos[1], &width, &height, &bwidth, &depth);
	XTranslateCoordinates(g_game.dpy, *curWin, root, 0, 0, &winPos[0], &winPos[1], &child);
	printf("%d %d\n", &winPos[0], &winPos[1]);
	return winPos;
	}
	 */
	return (1);
}
