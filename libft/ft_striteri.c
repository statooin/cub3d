/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:22:22 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:22:33 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *string, void (*function)(unsigned int, char *))
{
	unsigned int index;

	index = 0;
	while (string[index] != '\0')
	{
		((*function)(index, &string[index]));
		index++;
	}
}
