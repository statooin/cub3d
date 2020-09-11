/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 00:45:30 by statooin          #+#    #+#             */
/*   Updated: 2020/05/23 06:33:53 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*str;

	if (s1 || s2)
	{
		len1 = (s1) ? ft_strlen(s1) : 0;
		len2 = (s2) ? ft_strlen(s2) : 0;
		if (!(str = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
			return (NULL);
		i = -1;
		if (s1)
			while (s1[++i])
				str[i] = s1[i];
		i = -1;
		if (s2)
			while (s2[++i])
				str[len1++] = s2[i];
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
