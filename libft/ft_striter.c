/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:49:39 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 08:50:01 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *string, void (*function)(char *))
{
	unsigned int index;

	index = 0;
	while (string[index] != '\0')
	{
		((*function)(&string[index]));
		index++;
	}
}
