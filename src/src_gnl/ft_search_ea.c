/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_ea.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:32:27 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/08 20:32:34 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_search_ea(t_check *checks, char *line)
{
	int	i;

	i = 0;
	ft_skip_spaces(line, &i);
	i = i + 2;
	ft_skip_spaces(line, &i);
	if (line[i] == '.')
		checks->path_ea = ft_strdup(&line[i]);
	else
		return (-1);
	printf("%s|\n", checks->path_ea);
	checks->found_ea = 1;
	return (0);
}
