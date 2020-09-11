/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_borders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:31:26 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 14:24:00 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_map_borders(char **map, t_check *checks)
{
	int		x;
	int		y;
	char	*line1; //previous line
	char	*line2;//line under check
	char	*line3;//next line

	x = 1;
	while (x < (checks->map_lines - 1))
	{
		y = 1;
		line1 = ft_strdup(map[x - 1]);
		line2 = ft_strdup(map[x]);
		line3 = ft_strdup(map[x + 1]);
		while (map[x][y] != '\0')
		{
			if (line2[y] == '0')
				if (line1[y] == ' ' || line1[y - 1] == ' ' || line1[y + 1] == \
				' ' || line3[y] == ' ' || line3[y - 1] == ' ' || line3[y + 1] \
				== ' ' || line2[y - 1] == ' ' || line2[y + 1] == ' ' || y == -1)
				{
					printf("\n\nabsent boarders\n");
					return (-1);
				}
			y++;
		}
		ft_strchr(map[x], 0);
		x++;
		printf("last line|%s|\n", line1);
		printf("THE  line|%s|\n", line2);
		printf("next line|%s|\n", line3);
	}
	return (0);
}
