/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:17:49 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 09:17:54 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *string1, char const *string2)
{
	int index;

	index = 0;
	while (string1[index] != '\0' && string2[index] != '\0')
	{
		if (string1[index] != string2[index])
			return (0);
		index++;
	}
	if (string1[index] != string2[index])
		return (0);
	return (1);
}
