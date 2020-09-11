/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces_n_comma.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:34:51 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/08 20:34:55 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

void	ft_skip_spaces_n_comma(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\n' || line[*i] == '\f' ||
	line[*i] == '\r' || line[*i] == '\t' || line[*i] == '\v')
		*i = *i + 1;
	if (line[*i] == ',')
		*i = *i + 1;
	while (line[*i] == ' ' || line[*i] == '\n' || line[*i] == '\f' ||
	line[*i] == '\r' || line[*i] == '\t' || line[*i] == '\v')
		*i = *i + 1;
}
