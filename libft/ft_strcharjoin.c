/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:23:46 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:23:49 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcharjoin(char *str, char c)
{
	char		*strnew;
	size_t		i;

	i = 0;
	strnew = ft_strnew(ft_strlen(str) + 2);
	if (strnew == NULL)
		return (NULL);
	while (i < ft_strlen(str))
	{
		strnew[i] = str[i];
		i++;
	}
	strnew[i] = c;
	strnew[i + 1] = '\0';
	return (strnew);
}
