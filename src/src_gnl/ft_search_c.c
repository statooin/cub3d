/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:32:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 19:07:20 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_search_c(t_check *checks, t_param *param, char *line)
{
	int	i;
	int	oct1;
	int	oct2;
	int	oct3;

	oct1 = 0;
	oct2 = 0;
	oct3 = 0;
	i = 0;
	ft_skip_spaces(line, &i);
	i++;
	ft_skip_spaces(line, &i);
	if (line[i] >= '0' && line[i] <= '9')
		oct1 = atoi(&line[i]);
	else
		return (-1);
	if (oct1 < 0 || oct1 > 255)
		return (-1);
	i = i + ft_nbrlen(oct1, 10);
	ft_skip_spaces_n_comma(line, &i);
	if (line[i] >= '0' && line[i] <= '9')
		oct2 = atoi(&line[i]);
	else
		return (-1);
	if (oct2 < 0 || oct2 > 255)
		return (-1);
	i = i + ft_nbrlen(oct2, 10);
	ft_skip_spaces_n_comma(line, &i);
	if (line[i] >= '0' && line[i] <= '9')
		oct3 = atoi(&line[i]);
	else
		return (-1);
	if (oct3 < 0 || oct3 > 255)
		return (-1);
	i = i + ft_nbrlen(oct3, 10);
	ft_skip_spaces(line, &i);
	if (line[i] != '\0')
		return (-1);
	param->col_ceiling = oct1 * 0x10000 + oct2 * 0x100 + oct3;
	g_game.iceilling_col = param->col_ceiling;
	printf("%d|\n", param->col_ceiling);
	checks->found_c = 1;
	return (0);
}
