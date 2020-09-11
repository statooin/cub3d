/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:16:30 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:16:46 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ret;
	size_t	index;

	index = ft_strlen(src) + 1;
	if (len >= index)
	{
		ret = ft_memcpy(dst, src, index);
		while (index < len)
		{
			ret[index] = '\0';
			index++;
		}
		return (ret);
	}
	return (ft_memcpy(dst, src, len));
}
