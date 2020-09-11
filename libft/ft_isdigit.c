/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 08:16:57 by statooin          #+#    #+#             */
/*   Updated: 2020/05/22 08:17:16 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int cchar)
{
	return (cchar >= '0' && cchar <= '9' ? 1 : 0);
}