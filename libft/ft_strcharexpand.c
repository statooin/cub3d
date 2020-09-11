/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharexpand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:13:50 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:14:04 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcharexpand(char **source, const char addition)
{
	void *temp;

	temp = *source;
	if (*source == NULL)
	{
		*source = ft_strnew(1);
		if (*source != NULL)
		{
			*source[0] = addition;
		}
	}
	else
	{
		*source = ft_strcharjoin(*source, addition);
		free(temp);
	}
}
