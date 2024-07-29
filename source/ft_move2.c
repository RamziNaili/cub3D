/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:03:48 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 09:45:48 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	camera_right(t_player *player, int i)
{
	if (player->tab_key[i] == 65363)
	{
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-player->rot_speed)
			- player->dir_y * sin(-player->rot_speed);
		player->dir_y = player->old_dir_x * sin(-player->rot_speed)
			+ player->dir_y * cos(-player->rot_speed);
		player->old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-player->rot_speed)
			- player->plane_y * sin(-player->rot_speed);
		player->plane_y = player->old_plane_x * sin(-player->rot_speed)
			+ player->plane_y * cos(-player->rot_speed);
	}
}

void	camera_left(t_player *player, int i)
{
	if (player->tab_key[i] == 65361)
	{
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(player->rot_speed)
			- player->dir_y * sin(player->rot_speed);
		player->dir_y = player->old_dir_x * sin(player->rot_speed)
			+ player->dir_y * cos(player->rot_speed);
		player->old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(player->rot_speed)
			- player->plane_y * sin(player->rot_speed);
		player->plane_y = player->old_plane_x * sin(player->rot_speed)
			+ player->plane_y * cos(player->rot_speed);
	}
}
