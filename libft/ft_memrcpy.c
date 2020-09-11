/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:37:22 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:37:24 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*output;
	unsigned const char	*input;

	output = dst;
	input = src;
	while (len > 0)
	{
		output[len - 1] = input[len - 1];
		len--;
	}
	return (dst);
}
