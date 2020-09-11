/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:11:22 by statooin          #+#    #+#             */
/*   Updated: 2020/05/23 00:25:38 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char *pstart;
	unsigned char *pfrom;

	if (len != 0 && dst != src)
	{
		pstart = (unsigned char *)dst;
		pfrom = (unsigned char *)src;
		while (len-- > 0)
		{
			if (*pfrom != (unsigned char)c)
				*(pstart++) = *(pfrom++);
			else
			{
				*(pstart++) = *(pfrom++);
				return (pstart);
			}
		}
	}
	return (NULL);
}
