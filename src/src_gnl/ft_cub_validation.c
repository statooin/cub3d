/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:36:25 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 17:33:16 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

int	ft_cub_validation(void)
//int	ft_cub_validation(t_game *g_game)
{
	t_check	checks;
	t_param	param;

	ft_init_structs(&checks, &param);
	ft_what_type(&checks, &param);
	return (0);
}
