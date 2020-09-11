/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:06:01 by statooin          #+#    #+#             */
/*   Updated: 2020/05/22 09:07:04 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *pstart;
	unsigned char *pfrom;

	if (len != 0 && dst != src)
	{
		pstart = (unsigned char *)dst;
		pfrom = (unsigned char *)src;
		while (len-- > 0)
			*(pstart++) = *(pfrom++);
	}
	return (dst);
}
