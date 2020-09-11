/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:30:57 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/08 20:30:59 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_map(char *line, t_check *checks)
{
	char	**map;
	int		fd;
	int		i;

	if (checks->map_lines == 0)
		return (1);
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
		printf ("%s\n", line);
		i++;
	}
	close(fd);
	return (0);
}
