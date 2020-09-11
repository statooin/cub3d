/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 06:00:56 by statooin          #+#    #+#             */
/*   Updated: 2020/05/24 06:01:16 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_ar2d(char **str)
{
	while (*str)
		free(*str++);
	free(str);
	return (NULL);
}

static int	ft_wordln(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_cwr(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	char	**str;

	if (!s || !(str = (char**)malloc(sizeof(char*) * (ft_cwr(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_cwr(s, c))
	{
		l = 0;
		if (!(str[i] = (char*)malloc(sizeof(char) * (ft_wordln(&s[j], c) + 1))))
		{
			ft_free_ar2d(str);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][l++] = s[j++];
		str[i][l] = '\0';
	}
	str[i] = 0;
	return (str);
}
