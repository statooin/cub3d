/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:35:31 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 18:17:46 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_what_type(t_check *checks, t_param *param)
{
	int		i;
	int		fd;
	char	*line;

	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		checks->count_lines++;
		ft_skip_spaces(line, &i);
		if (line[i] == 'R')
			ft_search_r(checks, param, line);
		else if (line[i] == 'N' && line[i + 1] == 'O' && checks->found_no != 1)
			ft_search_no(checks, line);
		else if (line[i] == 'W' && line[i + 1] == 'E' && checks->found_we != 1)
			ft_search_we(checks, line);
		else if (line[i] == 'E' && line[i + 1] == 'A' && checks->found_ea != 1)
			ft_search_ea(checks, line);
		else if (line[i] == 'S' && line[i + 1] == 'O' && checks->found_ea != 1)
			ft_search_so(checks, line);
		else if (line[i] == 'S' && checks->found_s != 1)
			ft_search_s(checks, line);
		else if (line[i] == 'F' && checks->found_f != 1)
			ft_search_f(checks, param, line);
		else if (line[i] == 'C' && checks->found_c != 1)
			ft_search_c(checks, param, line);
		else if (line[i] == '\0')
			continue;
		else if (line[i] == '1')
		{
			printf("|go to map|\n");
			break ;
		}
		else if (line[i] <= '~' && line[i] >= '!')
		{
			printf("|-1|\n");
			return (-1);
		}
	}
	close(fd);
	ft_search_map(checks);
	return (0);
}
