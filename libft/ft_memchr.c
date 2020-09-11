/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:17:11 by statooin          #+#    #+#             */
/*   Updated: 2020/05/22 12:33:04 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int val, size_t len)
{
	unsigned char	*psrc;

	psrc = (unsigned char*)src;
	while (len--)
		if (*psrc != (unsigned char)val)
			psrc++;
		else
			return (psrc);
	return (0);
}
