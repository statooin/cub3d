/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:13:13 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:13:17 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(char character)
{
	if (character == '\n' || character == '\t' || character == ' ' ||
		character == '\v' || character == '\f' || character == '\r')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
