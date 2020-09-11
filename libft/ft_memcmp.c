/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 10:44:49 by statooin          #+#    #+#             */
/*   Updated: 2020/05/22 12:34:29 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	const unsigned char *psrc1;
	const unsigned char *psrc2;

	psrc1 = src1;
	psrc2 = src2;
	while (n--)
		if (*psrc1 != *psrc2)
			return (*psrc1 - *psrc2);
		else
		{
			psrc1++;
			psrc2++;
		}
	return (0);
}
