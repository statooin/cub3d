/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 07:50:06 by statooin          #+#    #+#             */
/*   Updated: 2020/05/23 07:52:12 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lsthead;

	if (!lst)
		return (NULL);
	lsthead = lst;
	while (lsthead->next)
		lsthead = lsthead->next;
	return (lsthead);
}
