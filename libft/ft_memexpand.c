/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memexpand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:00:46 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:00:50 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memexpand(void **src, size_t *size1, const void *add, size_t size2)
{
	void *temp;

	temp = *src;
	if (*src == NULL)
	{
		*src = ft_memdup(add, size2);
	}
	else
	{
		*src = ft_memjoin(*src, *size1, add, size2);
		free(temp);
	}
	*size1 += size2;
}
