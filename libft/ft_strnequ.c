/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:21:56 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:22:01 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *str1, char const *str2, size_t len)
{
	size_t index;

	index = 0;
	if (len == 0)
		return (1);
	else
	{
		while (str1[index] != '\0' && str2[index] != '\0' && index < (len - 1))
		{
			if (str1[index] != str2[index])
			{
				return (0);
			}
			index++;
		}
		if (str1[index] != str2[index])
		{
			return (0);
		}
		return (1);
	}
}
