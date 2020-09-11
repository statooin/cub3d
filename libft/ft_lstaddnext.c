/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:57:12 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 08:57:15 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddnext(t_list *current, t_list *new)
{
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
	return (new);
}
