/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 07:35:00 by statooin          #+#    #+#             */
/*   Updated: 2020/05/23 07:35:17 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_elem;
	t_list	*next_elem;

	if (!lst || !del)
		return ;
	next_elem = *lst;
	while (next_elem)
	{
		cur_elem = next_elem;
		next_elem = cur_elem->next;
		ft_lstdelone(cur_elem, del);
	}
	*lst = NULL;
}
