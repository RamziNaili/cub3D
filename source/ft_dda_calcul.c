/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:56:27 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/23 13:23:40 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			init_var_dda(t_player *player, int i)
{
	player->camera_x = 2 * i / (double)player->resolution[0] - 1;
	player->ray_dir_x = player->dir_x + player->plane_x * player->camera_x;
	player->ray_dir_y = player->dir_y + player->plane_y * player->camera_x;
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
	if (player->ray_dir_y == 0)
		player->delta_dist_x = 0;
	else if (player->ray_dir_x == 0)
		player->delta_dist_x = 1;
	else
		player->delta_dist_x = fabs(1 / player->ray_dir_x);
	if (player->ray_dir_x == 0)
		player->delta_dist_y = 0;
	else if (player->ray_dir_y == 0)
		player->delta_dist_y = 1;
	else
		player->delta_dist_y = fabs(1 / player->ray_dir_y);
	player->hit = 0;
}

void			init_var_dda_2(t_player *player)
{
	if (player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->pos_x - player->map_x)
			* player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->pos_x)
			* player->delta_dist_x;
	}
	if (player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->pos_y - player->map_y)
			* player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->pos_y)
			* player->delta_dist_y;
	}
}

void			dda_algo(t_player *player)
{
	while (player->hit == 0)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (player->map[player->map_x][player->map_y] == 49)
			player->hit = 1;
	}
}

void			draw_calcul(t_player *player)
{
	if (player->side == 0)
		player->perp_wall_dist = (player->map_x - player->pos_x +
				(1 - player->step_x) / 2) / player->ray_dir_x;
	else
		player->perp_wall_dist = (player->map_y - player->pos_y +
				(1 - player->step_y) / 2) / player->ray_dir_y;
	player->line_height = (player->resolution[1] / player->perp_wall_dist);
	player->draw_start = -player->line_height / 2 + player->resolution[1] / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->line_height / 2 + player->resolution[1] / 2;
	if (player->draw_end >= player->resolution[1])
		player->draw_end = player->resolution[1] - 1;
	if (player->side == 0)
		player->wall_x = player->pos_y + player->perp_wall_dist
			* player->ray_dir_y;
	else
		player->wall_x = player->pos_x + player->perp_wall_dist
			* player->ray_dir_x;
	player->wall_x -= floor((player->wall_x));
}
