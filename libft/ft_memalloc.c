/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:26:39 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:26:42 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *string;

	string = (unsigned char *)malloc(size);
	if (!string)
		return (NULL);
	while (size > 0)
	{
		size--;
		string[size] = '\0';
	}
	return ((void *)string);
}
