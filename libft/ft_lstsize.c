/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 07:39:30 by statooin          #+#    #+#             */
/*   Updated: 2020/05/25 05:06:05 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*lsthead;

	if (!lst)
		return (0);
	lsthead = lst;
	count = 0;
	while (lsthead)
	{
		lsthead = lsthead->next;
		count++;
	}
	return (count);
}
