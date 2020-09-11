/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:34:49 by statooin          #+#    #+#             */
/*   Updated: 2020/05/22 14:47:00 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	lenf;

	if (!(*find))
		return ((char *)str);
	lenf = ft_strlen(find);
	while (*str && len-- >= lenf)
	{
		if (*str == *find && ft_memcmp(str, find, lenf) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
