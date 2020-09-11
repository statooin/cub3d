/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:59:44 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 08:59:48 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenc(const char *string, int delim, size_t size)
{
	size_t len;

	len = 0;
	while (string[len] != (char)delim && len < size)
		len++;
	return (len);
}
