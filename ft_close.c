/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:58:30 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 18:58:56 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(void)
{
	if (g_game.win_buf0.ptr)
		mlx_destroy_image(g_game.mlx, g_game.win_buf0.ptr);
	if (g_game.win_buf1.ptr)
		mlx_destroy_image(g_game.mlx, g_game.win_buf1.ptr);
	if (g_game.mlx && g_game.mlx_win)
		mlx_destroy_window(g_game.mlx, g_game.mlx_win);
	system("killall mpg123");
	//kill(0, SIGTERM);
	//kill(1, SIGTERM);
	exit(0);
}
