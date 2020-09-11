/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_so.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:34:19 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/08 20:34:20 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_search_so(t_check *checks, char *line)
{
	int	i;

	i = 0;
	ft_skip_spaces(line, &i);
	i = i + 2;
	ft_skip_spaces(line, &i);
	if (line[i] == '.')
		checks->path_so = ft_strdup(&line[i]);
	else
		return (-1);
	printf("%s|\n", checks->path_so);
	checks->found_so = 1;
	return (0);
}
