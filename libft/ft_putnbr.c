/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:37:50 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:37:53 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int number)
{
	char digit;

	digit = 'a';
	if (number == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (number < 0)
		{
			write(1, "-", 1);
			number *= -1;
		}
		if (number / 10 > 0)
		{
			ft_putnbr(number / 10);
			digit = ((number % 10) + 48);
			write(1, &digit, 1);
		}
		else
		{
			digit = number + 48;
			write(1, &digit, 1);
		}
	}
}
