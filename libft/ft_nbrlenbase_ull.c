/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbase_ull.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:25:23 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:25:29 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlenbase_ull(unsigned long long number, int base)
{
	size_t len;

	len = 1;
	if (base == 1)
		return ((size_t)number + len);
	while (number / base != 0)
	{
		len++;
		number /= base;
	}
	return (len);
}
