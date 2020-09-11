/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:34:04 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 18:40:08 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_search_s(t_check *checks, char *line)
{
	int	i;

	i = 0;
	ft_skip_spaces(line, &i);
	i++;
	ft_skip_spaces(line, &i);
	if (line[i] == '.')
		checks->path_s = ft_strdup(&line[i]);
	else
		return (-1);
	checks->found_s = 1;
	printf("%s|\n", checks->path_s);
	return (0);
}
