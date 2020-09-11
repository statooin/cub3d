/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:30:16 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/09 17:20:35 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_cub.h"

void	ft_init_structs(t_check *checks, t_param *param)
{
	param->iscreen_width = 0;
	param->iscreen_height = 0;
	param->col_ceiling = 0;
	param->col_floor = 0;
	checks->found_no = 0;
	checks->found_so = 0;
	checks->found_we = 0;
	checks->found_ea = 0;
	checks->found_s = 0;
	checks->path_no = 0;
	checks->path_so = 0;
	checks->path_we = 0;
	checks->path_ea = 0;
	checks->path_s = 0;
	checks->found_f = 0;
	checks->found_c = 0;
	checks->map_lines = 0;
	checks->count_lines = 0;
}
