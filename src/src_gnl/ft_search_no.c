/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:33:36 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 14:25:48 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_search_no(t_check *checks, char *line)
{
	int	i;

	i = 0;
	ft_skip_spaces(line, &i);
	i = i + 2;
	ft_skip_spaces(line, &i);
	if (line[i] == '.')
		checks->path_no = ft_strdup(&line[i]);
	else
		return (-1);
	printf("%s|\n", checks->path_no);
	checks->found_no = 1;
	return (0);
}
