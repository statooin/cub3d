/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_mapline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:37:33 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 14:12:18 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_longest_mapline(t_check *checks)
{
	char	**map;
	char	*the_line;
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
		map[i] = ft_strdup(line);
		if (i == 0)
			the_line = map[i];
		if (ft_strlen(map[i]) > ft_strlen(the_line))
			the_line = ft_strdup(line);
		i++;
	}
	close(fd);
	return (ft_strlen(the_line));
}
