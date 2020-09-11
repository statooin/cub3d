/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:50:55 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 08:51:02 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *string1, const char *string2)
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
		string1[index] = string2[xedni];
		index++;
		xedni++;
	}
	string1[index] = '\0';
	return (string1);
}
