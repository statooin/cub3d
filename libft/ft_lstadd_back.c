/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 08:26:25 by statooin          #+#    #+#             */
/*   Updated: 2020/05/23 08:26:45 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *cur_lst;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		cur_lst = ft_lstlast(*lst);
		cur_lst->next = new;
	}
}
