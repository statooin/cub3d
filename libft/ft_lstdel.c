/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:58:51 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 08:58:52 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **start, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *temp;

	current = *start;
	while (current != NULL)
	{
		temp = current->next;
		(*del)(current->content, current->content_size);
		free(current);
		current = NULL;
		if (temp != NULL)
		{
			current = temp;
		}
		else
		{
			*start = NULL;
			return ;
		}
	}
}
