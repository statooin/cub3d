/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 15:10:26 by statooin          #+#    #+#             */
/*   Updated: 2020/05/22 15:23:22 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dst;
	s = src;
	n = siz;
	if (!(src))
		return (0);
	if (n > 0)
		while (--n > 0)
			if ((*d++ = *s++) == '\0')
				break ;
	if (n == 0)
	{
		if (siz > 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
