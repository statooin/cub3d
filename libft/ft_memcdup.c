/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:06:36 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:08:12 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcdup(const void *source, int delim, size_t size)
{
	return (ft_memdup(source, ft_strlenc((char *)source, delim, size)));
}
