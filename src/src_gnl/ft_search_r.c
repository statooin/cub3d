/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:33:48 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 17:54:26 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_search_r(t_check *checks, t_param *param, char *line)
{
	int	i;

	i = 0;
	ft_skip_spaces(line, &i);
	i++;
	ft_skip_spaces(line, &i);
	if (line[i] >= '0' && line[i] <= '9')
		param->iscreen_width = atoi(&line[i]);
	else
		return (-1);
	i += ft_nbrlen(param->iscreen_width, 10);
	ft_skip_spaces(line, &i);
	if (line[i] >= '0' && line[i] <= '9')
		param->iscreen_height = atoi(&line[i]);
	else
		return (-1);
	checks->found_r = 1;
	g_game.iscr_width = param->iscreen_width;
	g_game.iscr_height = param->iscreen_height;
	printf("%d\n", param->iscreen_width);
	printf("%d\n", param->iscreen_height);
	return (0);
}
