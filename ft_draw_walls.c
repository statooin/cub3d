/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:14:03 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/10 18:58:39 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_walls(void)
{
	static float	fray_ang;
	t_objects		obj[20];
	static float	fdist_to_wall;
	static int		itest_x;
	static int		itest_y;
	static int		ibiggest;
	static int		i;
	static int		itest_x_old;
	static int		itest_y_old;

	g_math.iray_x = 0;
	fray_ang = g_plr.fplr_a + g_consts.ffov05;
	while (g_math.iray_x < g_game.iscr_width)
	{
		g_math.ibottom_sky[g_math.iray_x] = g_game.iscr_height;

		i = 0;
		ibiggest = 0;
		fdist_to_wall = 0;
		g_consts.fsinf_ang_step = - sinf(fray_ang) * g_consts.fstep_check; //!!pre calc this in array!!
		g_consts.fcosf_ang_step = - cosf(fray_ang) * g_consts.fstep_check;
		g_math.ftest_x = g_plr.fplr_x;
		g_math.ftest_y = g_plr.fplr_y;
		itest_x = (int)(g_math.ftest_x);
		itest_y = (int)(g_math.ftest_y);

		while (g_math.map[itest_y][itest_x] != '#') // finding the most far wall '#'
		{
			while (itest_x_old == (int)(g_math.ftest_x) && itest_y_old == (int)(g_math.ftest_y)) //next cell
			{
				fdist_to_wall += g_consts.fstep_check; //!!!!! make adaptive per distance from 0.01 to 0.06
				g_math.ftest_x = g_math.ftest_x + g_consts.fsinf_ang_step; // this is step inside cell
				g_math.ftest_y = g_math.ftest_y + g_consts.fcosf_ang_step;
			}
			itest_x = (int)(g_math.ftest_x);
			itest_y = (int)(g_math.ftest_y);
			itest_x_old = itest_x;
			itest_y_old = itest_y;
			if (g_math.map[itest_y][itest_x] != ' ')
			{
				if (g_math.map[itest_y][itest_x] >= 'a')
				{
					while (itest_x_old == (int)(g_math.ftest_x) && itest_y_old == (int)(g_math.ftest_y)) //next cell
					{
						if (g_math.enemy[g_math.map[itest_y][itest_x] - 'a'][(int)(30 * (g_math.ftest_y - (int)g_math.ftest_y))][(int)(30 * (g_math.ftest_x - (int)g_math.ftest_x))] == '+')
						{
							obj[i].ctype = g_math.map[itest_y][itest_x]; // number type of enemy
							obj[i].fdist = fdist_to_wall;
							obj[i].itest_x = itest_x;
							obj[i].ftest_x = g_math.ftest_x;
							obj[i].ftest_y = g_math.ftest_y;
							i++;
							break;
						}
						fdist_to_wall += g_consts.fstep_check; //!!!!! make adaptive per distance from 0.01 to 0.06
						g_math.ftest_x = g_math.ftest_x + g_consts.fsinf_ang_step; // this is step inside cell
						g_math.ftest_y = g_math.ftest_y + g_consts.fcosf_ang_step;
					}
					while (itest_x_old == (int)(g_math.ftest_x) && itest_y_old == (int)(g_math.ftest_y)) //next cell
					{
						fdist_to_wall += g_consts.fstep_check; //!!!!! make adaptive per distance from 0.01 to 0.06
						g_math.ftest_x = g_math.ftest_x + g_consts.fsinf_ang_step; // this is step inside cell
						g_math.ftest_y = g_math.ftest_y + g_consts.fcosf_ang_step;
					}
				}
				else if (g_math.map[itest_y][itest_x] >= '1' && g_tex.tex_wall[g_math.map[itest_y][itest_x] - '0'].iprior >= ibiggest)
				{
					ibiggest = g_tex.tex_wall[g_math.map[itest_y][itest_x] - '0'].iprior;
					obj[i].ctype = g_math.map[itest_y][itest_x]; // number type of wall
					obj[i].fdist = fdist_to_wall;
					obj[i].itest_x = itest_x;
					obj[i].ftest_x = g_math.ftest_x;
					obj[i].ftest_y = g_math.ftest_y;
					i++;

					//and find next side of wall - and exit this cell
					while (itest_x_old == (int)(g_math.ftest_x) && itest_y_old == (int)(g_math.ftest_y)) //next cell
					{
						fdist_to_wall += g_consts.fstep_check;
						g_math.ftest_x = g_math.ftest_x + g_consts.fsinf_ang_step; // this is step inside cell
						g_math.ftest_y = g_math.ftest_y + g_consts.fcosf_ang_step;
					} // if this is ending side of wall
					itest_x = (int)(g_math.ftest_x);
					itest_y = (int)(g_math.ftest_y);

					if (g_math.map[itest_y][itest_x] < '1' || g_math.map[itest_y][itest_x] >= 'a')
					{
						obj[i].ctype = obj[i - 1].ctype; // number type of enemy
						obj[i].fdist = fdist_to_wall;// - g_consts.fstep_check;
						obj[i].itest_x = obj[i - 1].itest_x;
						obj[i].ftest_x = g_math.ftest_x - g_consts.fsinf_ang_step;
						obj[i].ftest_y = g_math.ftest_y - g_consts.fcosf_ang_step;
						i++;
					}
					else if (g_tex.tex_wall[g_math.map[itest_y][itest_x] - '0'].iprior < ibiggest)
					{
						obj[i].ctype = obj[i - 1].ctype; // number type of enemy
						obj[i].fdist = fdist_to_wall;// - g_consts.fstep_check;
						obj[i].itest_x = obj[i - 1].itest_x;
						obj[i].ftest_x = g_math.ftest_x - g_consts.fsinf_ang_step;
						obj[i].ftest_y = g_math.ftest_y - g_consts.fcosf_ang_step;
						i++;
					}

					if (ibiggest >= 8 || i > 6) // the highest wall
						break;
				}
			}
		}
		i--;
		ft_draw_wall_stripes_all(&fray_ang, obj, &i);
		g_math.iray_x++;
		fray_ang = fray_ang - g_consts.fray_ang_step;
	}
}
