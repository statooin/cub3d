/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:36:10 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 10:36:13 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **start, t_list *new)
{
	t_list	*current;

	current = *start;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}
