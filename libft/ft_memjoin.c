/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:37:11 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:37:13 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_memjoin_internal(unsigned char *result,
							size_t judex, const unsigned char *src, size_t size)
{
	size_t index;

	index = 0;
	while (index < size)
	{
		result[judex] = src[index];
		index++;
		judex++;
	}
	return (judex);
}

void			*ft_memjoin(const void *str1, size_t size1,
							const void *str2, size_t size2)
{
	size_t				judex;
	const unsigned char	*src1;
	const unsigned char	*src2;
	unsigned char		*result;

	judex = 0;
	src1 = (unsigned char *)str1;
	src2 = (unsigned char *)str2;
	result = (unsigned char *)malloc(sizeof(unsigned char) * (size1 + size2));
	if (result == NULL)
		return (NULL);
	judex = ft_memjoin_internal(result, judex, src1, size1);
	ft_memjoin_internal(result, judex, src2, size2);
	return ((void *)result);
}
