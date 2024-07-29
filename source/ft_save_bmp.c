/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:51:06 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 09:31:23 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_file_header(t_player *player, int fd)
{
	int		size;
	int		pixel_data;

	pixel_data = 54;
	size = pixel_data + player->resolution[0] *\
	player->resolution[1] * 4;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &pixel_data, 4);
}

void	ft_img(t_player *player, int fd)
{
	int		size;
	int		plane;
	int		img_len;

	size = 40;
	plane = 1;
	img_len = player->resolution[0] * player->resolution[1];
	write(fd, &size, 4);
	write(fd, &player->resolution[0], 4);
	write(fd, &player->resolution[1], 4);
	write(fd, &plane, 2);
	write(fd, &player->bits_per_pixel, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &img_len, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	ft_print_bmp(t_player *player, int fd)
{
	int		r;
	int		g;
	int		b;
	int		x;
	int		y;

	y = player->resolution[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < player->resolution[0])
		{
			r = player->addr[y * player->line_length +\
			x * player->bits_per_pixel / 8];
			g = player->addr[y * player->line_length +\
			x * player->bits_per_pixel / 8 + 1];
			b = player->addr[y * player->line_length +\
			x++ * player->bits_per_pixel / 8 + 2];
			write(fd, &r, 1);
			write(fd, &g, 1);
			write(fd, &b, 1);
			write(fd, "\0", 1);
		}
		y--;
	}
}

void	ft_create_bmp(t_player *player)
{
	int		fd;

	if ((fd = open("save.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
	{
		display_err(22);
	}
	ft_file_header(player, fd);
	ft_img(player, fd);
	ft_print_bmp(player, fd);
	close(fd);
	ft_exit(player);
}
