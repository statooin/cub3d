/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forbid_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:17:57 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 14:19:21 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_forbid_symbols(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			y++;
			if (map[x][y] != '2' && map[x][y] != '0' && \
			map[x][y] != '1' && map[x][y] != 'N' &&
			map[x][y] != 'S' && map[x][y] != 'W' && \
			map[x][y] != 'E' && map[x][y] != ' '
			&& map[x][y] != '\0')
			{
				printf ("wrong symbols inside the map\n");
				return (-1);
			}
		}
		x++;
	}
	return (0);
}
