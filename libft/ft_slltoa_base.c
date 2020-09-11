/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:23:58 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:24:02 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert(signed long long n,\
					const unsigned int base,\
					char *str,\
					size_t i)
{
	int			res;
	char		*bstr;

	bstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (base == 1 && ((ssize_t)(i * -1) >= n))
	{
		str[i] = '1';
		i++;
		if ((ssize_t)(i * -1) == n)
			return (str);
	}
	if (n != 0)
	{
		res = n % base;
		res = res < 0 ? res * -1 : res;
		str[i] = bstr[res];
		i++;
		ft_convert(n / base, base, str, i);
	}
	return (str);
}

char			*ft_slltoa_base(signed long long nb, const unsigned int base)
{
	int			nb_len;
	char		*str;

	if (base == 0)
	{
		return (NULL);
	}
	if (nb == 0)
		return (ft_strdup("0"));
	nb_len = ft_nbrlenbase(nb, base);
	str = (char *)ft_strnew(sizeof(char) * nb_len + 1);
	if (str != NULL)
	{
		if (nb < 0)
		{
			str[0] = '-';
		}
		else
			nb = nb * -1;
		str = ft_convert(nb, base, str, (str[0] == '-' ? 1 : 0));
		str[nb_len] = '\0';
		str = ft_strrev(str, (str[0] == '-' ? 1 : 0));
	}
	return (str);
}
