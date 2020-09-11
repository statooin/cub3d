/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 08:48:19 by statooin          #+#    #+#             */
/*   Updated: 2020/05/23 08:52:13 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*lsthead;

	if (!lst || !f)
		return (NULL);
	lsthead = lst;
	if (!(new_elem = ft_lstnew(f(lsthead->content))))
		return (NULL);
	new_lst = new_elem;
	lsthead = lsthead->next;
	while (lsthead)
	{
		if (!(new_elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lsthead = lsthead->next;
		ft_lstadd_back(&new_lst, new_elem);
	}
	return (new_lst);
}
