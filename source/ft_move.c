/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:55:30 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/23 15:18:25 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	front_back(t_player *player, int i)
{
	if (player->tab_key[i] == 119)
	{
		if (player->map[(int)(player->pos_x + player->dir_x
					* player->move_speed)][(int)(player->pos_y)] == 48)
			player->pos_x += player->dir_x * player->move_speed;
		if (player->map[(int)(player->pos_x)][(int)(player->pos_y
					+ player->dir_y * player->move_speed)] == 48)
			player->pos_y += player->dir_y * player->move_speed;
	}
	if (player->tab_key[i] == 115)
	{
		if (player->map[(int)(player->pos_x - player->dir_x
					* player->move_speed)][(int)(player->pos_y)] == 48)
			player->pos_x -= player->dir_x * player->move_speed;
		if (player->map[(int)(player->pos_x)][(int)(player->pos_y
					- player->dir_y * player->move_speed)] == 48)
			player->pos_y -= player->dir_y * player->move_speed;
	}
}

void	colision_front(t_player *player)
{
	if (player->map[(int)(player->pos_x + player->plane_x *
				player->move_speed)][(int)(player->pos_y)] == 48)
		player->pos_x += player->plane_x * player->move_speed;
	if (player->map[(int)(player->pos_x)][(int)(player->pos_y +
				player->plane_y * player->move_speed)] == 48)
		player->pos_y += player->plane_y * player->move_speed;
}

void	colision_side(t_player *player)
{
	if (player->map[(int)(player->pos_x - player->plane_x *
				player->move_speed)][(int)(player->pos_y)] == 48)
		player->pos_x -= player->plane_x * player->move_speed;
	if (player->map[(int)(player->pos_x)][(int)(player->pos_y -
				player->plane_y * player->move_speed)] == 48)
		player->pos_y -= player->plane_y * player->move_speed;
}

int		move(t_player *player)
{
	int i;

	i = -1;
	while (++i < 10)
	{
		if (player->tab_key[i] == 65307)
			ft_exit(player);
		front_back(player, i);
		if (player->tab_key[i] == 100)
		{
			colision_front(player);
		}
		if (player->tab_key[i] == 97)
		{
			colision_side(player);
		}
		camera_right(player, i);
		camera_left(player, i);
	}
	return (1);
}
