#include "cub3d.h"

int	ft_move_enemy_up(void)
{
	static int	i;
	static int	y;

	ft_next_anim();
	i = 0;
	while (i < 30)
	{
		if (g_math.enemy[g_math.ienemy_n][0][i] == '+')
		{
			if (g_math.map[g_enemies[g_math.ienemy_n].ienemy_y - 1][g_enemies[g_math.ienemy_n].ienemy_x] == ' ')
			{
				y = 0;
				while (y <= 9)
				{
					g_math.enemy[g_math.ienemy_n][29 - y] = g_math.enemy[g_math.ienemy_n][y];
					g_math.enemy[g_math.ienemy_n][y] = g_math.enemy[g_math.ienemy_n][30];
					y++;
				}
				g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x] = ' ';
				g_enemies[g_math.ienemy_n].ienemy_y--;
				g_math.map[g_enemies[g_math.ienemy_n].ienemy_y][g_enemies[g_math.ienemy_n].ienemy_x] = g_math.ienemy_n + 'a';
			}
			return (1);
		}
		i++;
	}
	y = 0;
	while (y < 30)
	{
		g_math.enemy[g_math.ienemy_n][y] = g_math.enemy[g_math.ienemy_n][y + 1];
		y++;
	}
	g_math.enemy[g_math.ienemy_n][29] = g_math.enemy[g_math.ienemy_n][30];
	return (1);
}
