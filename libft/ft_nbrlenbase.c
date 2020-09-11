/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:17:03 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:17:06 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlenbase(long long number, int base)
{
	size_t len;

	len = 1;
	if (number < 0)
		len++;
	if (base == 1)
	{
		if (number < 0)
			number = number * -1;
		return ((size_t)number + len);
	}
	while (number / base != 0)
	{
		len++;
		number /= base;
	}
	return (len);
}
