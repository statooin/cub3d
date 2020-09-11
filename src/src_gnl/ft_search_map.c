/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:33:22 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 14:25:28 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_search_map(t_check *checks)
{
	int		i;
	int		q;
	int		fd;
	char	*line;

	if (ft_check_if_all_found(checks) == -1)
	{
		printf("not enough args\n");
		return (-1);
	}
	i = 0;
	fd = open("map.cub", O_RDONLY);
	while (i < checks->count_lines - 1)
	{
		get_next_line(fd, &line);
		i++;
	}
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		ft_skip_spaces(line, &i);
		while (line[i] == ' ' || line[i] == '1')
		{
			if (line[i] == '1')
			{
				checks->map_lines++;
				break ;
			}
			i++;
		}
		if (line[i] != '1' && line[i] != '\0')
		{
			printf("garbage in the end\n");
			return (-1);
		}
	}
	printf("\n\nmap_lines = %d\ncount_lines = %d\n", checks->map_lines, checks->count_lines);
	close(fd);
	q = ft_longest_mapline(checks);
	ft_map_w_spaces(q, checks);
	ft_map(line, checks);
	return (0);
}
