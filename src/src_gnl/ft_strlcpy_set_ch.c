/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_set_ch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:35:01 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/08 20:35:12 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

size_t	ft_strlcpy_set_ch(char *dst, const char *src, size_t size, char x)
{
	size_t	i;
	size_t	size2;

	size2 = size;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (!src[i])
		dst[i] = '\0';
	while ((src[i] != '\0') && (size2 > 0))
	{
		dst[i] = src[i];
		i++;
		dst[i] = x;
		size2--;
	}
	while (size2 > 0)
	{
		dst[i] = x;
		i++;
		size2--;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
