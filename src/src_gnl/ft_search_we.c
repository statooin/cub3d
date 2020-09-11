/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_we.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:34:31 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/08 20:34:33 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_search_we(t_check *checks, char *line)
{
	int	i;

	i = 0;
	ft_skip_spaces(line, &i);
	i = i + 2;
	ft_skip_spaces(line, &i);
	if (line[i] == '.')
		checks->path_we = ft_strdup(&line[i]);
	else
		return (-1);
	printf("%s|\n", checks->path_we);
	checks->found_we = 1;
	return (0);
}
