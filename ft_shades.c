/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shades.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:24:02 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:24:04 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_shades(int *color, float *fdist_to_wall) //make a bit darker
{
	//static int oct_r;
	//static int oct_g;
	//static int oct_b;
	static float	fshade;

	fshade = *fdist_to_wall * 0.2f + 1; //0.05f
	//oct_r = (*color >> 16 & 0xFF) / fshade; // разбиваем по октетам
	//oct_g = (*color >> 8 & 0xFF) / fshade;
	//oct_b = (*color & 0xFF) / fshade;
	//return (oct_r << 16 | oct_g << 8 | oct_b); // собираем число по кусочкам
	return ((int)((*color >> 16 & 0xFF) / fshade) << 16 | (int)((*color >> 8 & 0xFF) / fshade) << 8 | (int)((*color & 0xFF) / fshade)); // собираем число по кусочкам
	//oct_r = oct_r - oct_r * fshade; // apply shading  // !!!!!! re do this! -1 can be :(
	//oct_g = oct_g - oct_g * fshade;
	//oct_b = oct_b - oct_b * fshade;
//	return (oct_r << 16 | oct_g << 8 | oct_b); // собираем число по кусочкам
}
