/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:18:06 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:18:12 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *source, size_t len)
{
	size_t				index;
	unsigned char		*ret;
	const unsigned char	*input;

	index = 0;
	input = (const unsigned char *)source;
	ret = (void *)ft_memalloc(sizeof(unsigned char) * len);
	if (ret == NULL)
	{
		return (NULL);
	}
	while (index < len)
	{
		ret[index] = input[index];
		index++;
	}
	return ((void *)ret);
}
