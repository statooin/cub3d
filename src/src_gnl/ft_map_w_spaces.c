/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_w_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:31:51 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/08 20:31:53 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_map_w_spaces(int line_len, t_check *checks)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	map = malloc(sizeof(char*) * checks->map_lines + 1);
	i = 0;
	fd = open("map.cub", O_RDONLY);
	while (i < checks->count_lines - 1)
	{
		get_next_line(fd, &line);
		i++;
	}
	i = 0;
	while (i < checks->map_lines)
	{
		get_next_line(fd, &line);
		map[i] = malloc(sizeof(char*) * line_len + 1);
		ft_strlcpy_set_ch(map[i], line, line_len, ' ');
		printf ("map |%s|\n", map[i]);
		i++;
	}
	close(fd);
	ft_forbid_symbols(map);
	ft_map_borders(map, checks);
	return (0);
}
