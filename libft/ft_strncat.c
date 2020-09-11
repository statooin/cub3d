/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:49:19 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 08:49:27 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *string1, const char *string2, size_t len)
{
	size_t index;
	size_t xedni;

	index = 0;
	xedni = 0;
	while (string1[index] != '\0')
	{
		index++;
	}
	while (string2[xedni] != '\0')
	{
		if (xedni == len)
		{
			string1[index] = '\0';
			return (string1);
		}
		string1[index] = string2[xedni];
		index++;
		xedni++;
	}
	string1[index] = '\0';
	return (string1);
}
