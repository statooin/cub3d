/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pause.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:14:36 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/07 20:18:00 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pause(int trigger)
{
	int		msec; /* 15ms */
	clock_t	before;

	msec = 0;
	before = clock();
	do // FORMIDDEN FUNCTION!!!!
	{
		/*
		 * Do something to busy the CPU just here while you drink a coffee
		 * Be sure this code will not take more than `trigger` ms
		 */
		clock_t difference = clock() - before;
		msec = difference * 1000 / CLOCKS_PER_SEC;
	}
	while (msec < trigger);
}
