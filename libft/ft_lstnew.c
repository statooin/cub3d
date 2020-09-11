/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 06:59:41 by statooin          #+#    #+#             */
/*   Updated: 2020/05/23 06:59:55 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lsthead;

	if (!(lsthead = malloc(sizeof(t_list))))
		return (NULL);
	lsthead->content = content;
	lsthead->next = NULL;
	return (lsthead);
}
