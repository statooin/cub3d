/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:36:36 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:36:37 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **start)
{
	t_list	*current;
	size_t	index;

	index = 1;
	current = *start;
	while (current->next != NULL)
	{
		current = current->next;
		index++;
	}
	return (index);
}
