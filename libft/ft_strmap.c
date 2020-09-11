/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:52:06 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 08:52:10 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *string, char (*function)(char))
{
	int		index;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * ft_strlen(string) + 1);
	if (!ret)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
	{
		ret[index] = (*function)(string[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
