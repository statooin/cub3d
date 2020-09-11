/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 00:21:28 by statooin          #+#    #+#             */
/*   Updated: 2020/05/23 00:23:20 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *dst, int val, size_t len)
{
	unsigned char	*pstart;

	pstart = (unsigned char*)dst;
	while (len-- > 0)
		*(pstart++) = (unsigned char)val;
	return ((char*)dst);
}
