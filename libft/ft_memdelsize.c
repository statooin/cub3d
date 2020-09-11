/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdelsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:37:00 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:37:02 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdelsize(void *pointer, size_t size)
{
	size_t			index;
	unsigned char	*input;

	index = 0;
	input = pointer;
	while (index < size)
	{
		input[index] = 0;
		index++;
	}
	free(pointer);
	pointer = NULL;
}
