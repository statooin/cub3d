/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:51:28 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 08:51:33 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_word(const char *string, const char *word)
{
	size_t index;

	index = 0;
	while (word[index] != '\0')
	{
		if (word[index] != string[index])
		{
			return (0);
		}
		index++;
	}
	return (1);
}

char		*ft_strstr(const char *string, const char *word)
{
	size_t index;

	index = 0;
	if (word[0] == '\0')
	{
		return ((char *)string);
	}
	while (string[index] != '\0')
	{
		if (string[index] == word[0])
		{
			if (check_word(&string[index], word) == 1)
			{
				return ((char *)&string[index]);
			}
		}
		index++;
	}
	return (NULL);
}
