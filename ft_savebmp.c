/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:29:08 by bjebedia          #+#    #+#             */
/*   Updated: 2020/09/14 17:43:05 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bdata(int fd)
{
	int				j;
	unsigned char	buffer[4];

	j = g_game.iscr_width * g_game.iscr_height;
	while (j >= 0)
	{
		buffer[0] = (unsigned char)(g_game.win_buf0.data[j] & 0xFF);
		buffer[1] = (unsigned char)(g_game.win_buf0.data[j] >> 8 & 0xFF);
		buffer[2] = (unsigned char)(g_game.win_buf0.data[j] >> 16);
		buffer[3] = (unsigned char)(0);
		write(fd, buffer, 4);
		j--;
	}
}

void	ft_binfo(int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = g_game.iscr_width;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = g_game.iscr_height;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = g_game.iscr_height * g_game.iscr_width * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	ft_savebmp(void)
{
	int	fd;

	fd = open("screenshot_cub3d.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_bfile(fd);
	ft_binfo(fd);
	ft_bdata(fd);
	close(fd);
}
