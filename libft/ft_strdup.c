/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:06:44 by statooin          #+#    #+#             */
/*   Updated: 2020/02/06 22:10:24 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t			len;
	char			*dup;
	char			*start;

	len = ft_strlen(str);
	if (!(dup = (char *)malloc(sizeof(char) * len + 1)))
		return ((char *)NULL);
	start = dup;
	while (*str)
		*dup++ = *str++;
	*dup = '\0';
	return (start);
}
