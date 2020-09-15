/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forbid_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:17:57 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/15 16:41:24 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_forbid_symbols(char **map, t_check *checks)
{
	int	x;
	int	y;

	x = 0;
	while (x < checks->count_lines)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] != '2' && map[x][y] != '0' && \
			map[x][y] != '1' && map[x][y] != 'N' &&
			map[x][y] != 'S' && map[x][y] != 'W' && \
			map[x][y] != 'E' && map[x][y] != ' ')
			{
				printf ("wrong symbols inside the map\n");
				return (-1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
