/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_all_found.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:29:54 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 14:11:13 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_check_if_all_found(t_check *cheks)
{
	if (cheks->found_r != 1 || cheks->found_no != 1 || cheks->found_so != 1 || \
	cheks->found_we != 1 || cheks->found_ea != 1 || cheks->found_s != 1 || \
	cheks->found_f != 1 || cheks->found_c != 1)
		return (-1);
	else
		return (0);
}
