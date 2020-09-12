/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:04:33 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:42:44 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_move(void)
{
	//static int	pid;

	if ((g_plr.uikeys_prsd & PRSD_A) != 0)
	{
		g_plr.fplr_y += cosf(g_plr.fplr_a - 1.7f) * g_plr.fplr_v / 1.5f;
		g_plr.fplr_x += sinf(g_plr.fplr_a - 1.7f) * g_plr.fplr_v / 1.5f;
		if (g_math.map[(int)g_plr.fplr_y][(int)g_plr.fplr_x] != '0' && g_math.map[(int)g_plr.fplr_y][(int)g_plr.fplr_x] != ' ')
		{
			g_plr.fplr_y -= cosf(g_plr.fplr_a - 1.7f) * g_plr.fplr_v * 2;
			g_plr.fplr_x -= sinf(g_plr.fplr_a - 1.7f) * g_plr.fplr_v * 2;
		}
	}
	else if ((g_plr.uikeys_prsd & PRSD_D) != 0)
	{
		g_plr.fplr_y -= cosf(g_plr.fplr_a - 1.7f) * g_plr.fplr_v / 1.5f;
		g_plr.fplr_x -= sinf(g_plr.fplr_a - 1.7f) * g_plr.fplr_v / 1.5f;
		if (g_math.map[(int)g_plr.fplr_y][(int)g_plr.fplr_x] != '0' && g_math.map[(int)g_plr.fplr_y][(int)g_plr.fplr_x] != ' ')
		{
			g_plr.fplr_y += cosf(g_plr.fplr_a - 1.7f) * g_plr.fplr_v * 2;
			g_plr.fplr_x += sinf(g_plr.fplr_a - 1.7f) * g_plr.fplr_v * 2;
		}
	}

	if ((g_plr.uikeys_prsd & PRSD_UP_W) != 0)
	{
		g_plr.fplr_y -= cosf(g_plr.fplr_a) * g_plr.fplr_v;
		g_plr.fplr_x -= sinf(g_plr.fplr_a) * g_plr.fplr_v;
		if (g_math.map[(int)g_plr.fplr_y][(int)g_plr.fplr_x] != '0' && g_math.map[(int)g_plr.fplr_y][(int)g_plr.fplr_x] != ' ')
		{
			g_plr.fplr_y += cosf(g_plr.fplr_a) * g_plr.fplr_v * 2;
			g_plr.fplr_x += sinf(g_plr.fplr_a) * g_plr.fplr_v * 2;
		}
	}
	else if ((g_plr.uikeys_prsd & PRSD_DOWN_S) != 0)
	{
		g_plr.fplr_y += cosf(g_plr.fplr_a) * g_plr.fplr_v;
		g_plr.fplr_x += sinf(g_plr.fplr_a) * g_plr.fplr_v;
		if (g_math.map[(int)g_plr.fplr_y][(int)g_plr.fplr_x] != '0' && g_math.map[(int)g_plr.fplr_y][(int)g_plr.fplr_x] != ' ')
		{
			g_plr.fplr_y -= cosf(g_plr.fplr_a) * g_plr.fplr_v * 2;
			g_plr.fplr_x -= sinf(g_plr.fplr_a) * g_plr.fplr_v * 2;
		}
	}

if (g_game.isteps == 0)
{
	g_game.isteps = 1;
	g_game.ccmd = ft_strdup("");
	ft_strjoin_f("bash unmute_pid.sh ", g_game.cm_steps, &g_game.ccmd);
	printf ("%s\n", g_game.ccmd);
	system(g_game.ccmd);
}

}

void	ft_key_actions(void)
{
	if ((g_plr.uikeys_prsd & PRSD_DOWN_S) != 0 || (g_plr.uikeys_prsd & PRSD_UP_W) != 0 || (g_plr.uikeys_prsd & PRSD_D) != 0 || (g_plr.uikeys_prsd & PRSD_A) != 0)
		ft_key_move();
	else if (g_game.isteps == 1)
	{
		g_game.isteps = 0;
		g_game.ccmd = ft_strdup("");
		ft_strjoin_f("bash mute_pid.sh ", g_game.cm_steps, &g_game.ccmd);
		printf ("%s\n", g_game.ccmd);
		system(g_game.ccmd);
	}

	if ((g_plr.uikeys_prsd & PRSD_LEFT) != 0)
	{
		g_plr.fplr_a += 0.08f;
		g_math.isky_x = g_math.isky_x + 0.08f * 200; //!!
		if (g_math.isky_x > 0)
			g_math.isky_x = - g_tex.tex_sky.width / 2;
		else if (g_math.isky_x < - g_tex.tex_sky.width / 2)
			g_math.isky_x = 0;
	}
	else if ((g_plr.uikeys_prsd & PRSD_RIGHT) != 0)
	{
		g_plr.fplr_a -= 0.08f;
		g_math.isky_x = g_math.isky_x - 0.08f * 200; //!!
		if (g_math.isky_x > 0)
			g_math.isky_x = - g_tex.tex_sky.width / 2;
		else if (g_math.isky_x < - g_tex.tex_sky.width / 2)
			g_math.isky_x = 0;
	}

	if ((g_plr.uikeys_prsd & PRSD_E) != 0)
		ft_key_e();
	if ((g_plr.uikeys_prsd & PRSD_SHIFT) != 0)
		g_plr.fplr_v = 0.10f;
	else if ((g_plr.uikeys_prsd & PRSD_SHIFT) == 0)
		g_plr.fplr_v = 0.04f;

}
