/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:46:50 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/15 14:40:40 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_valid_resolution(int *width, int *height)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	mlx_get_screen_size(g_game.mlx, &w, &h);
	printf("!NEW INFO |%d|%d|\n", w, h);
	if (w < *width)
		*width = w;
	if (h < *height)
		*height = h;
	printf("!NEW INFO |%d|%d|\n", *width, *height);
	return 0;
}
