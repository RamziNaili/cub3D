/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:05:56 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 10:55:41 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_pos(t_player *player)
{
	if (player->map_p.p == 'N')
	{
		player->dir_x = -1;
		player->plane_y = 0.66;
	}
	else if (player->map_p.p == 'S')
	{
		player->dir_x = 1;
		player->plane_y = -0.66;
	}
	else if (player->map_p.p == 'E')
	{
		player->dir_y = 1;
		player->plane_x = 0.66;
	}
	else if (player->map_p.p == 'W')
	{
		player->dir_y = -1;
		player->plane_x = -0.66;
	}
}

void	init_tab(t_player *player)
{
	int i;

	i = 0;
	while (i < 10)
	{
		player->tab_key[i] = -1;
		i++;
	}
}

void	init_var(t_player *player)
{
	player->pos_x = player->map_p.x + 0.5;
	player->pos_y = player->map_p.y + 0.5;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	init_pos(player);
	player->move_speed = 0.3;
	player->rot_speed = 0.025;
	player->mlx = mlx_init();
	if (player->bmp != 1)
	{
		test_screen_size(player);
		player->win = mlx_new_window(player->mlx, player->resolution[0],
			player->resolution[1], "Ranaili Cub3d !");
	}
	player->img = mlx_new_image(player->mlx, player->resolution[0],
			player->resolution[1]);
	player->addr = mlx_get_data_addr(player->img, &player->bits_per_pixel,
			&player->line_length, &player->endian);
	init_tab(player);
}
