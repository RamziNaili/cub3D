/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:51:28 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 10:28:53 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_swap_sprites(t_player *player)
{
	int					i;
	double				dist_temp;
	t_sprites			tmp;

	i = 1;
	if (player->num_sprite == 1)
		return ;
	while (i < player->num_sprite)
	{
		if (player->sprite_distance[i - 1] < player->sprite_distance[i])
		{
			dist_temp = player->sprite_distance[i - 1];
			player->sprite_distance[i - 1] =
				player->sprite_distance[i];
			player->sprite_distance[i] = dist_temp;
			tmp = player->sprites[i - 1];
			player->sprites[i - 1] = player->sprites[i];
			player->sprites[i] = tmp;
			i = 1;
		}
		else
			i++;
	}
}

void		sort_sprites(t_player *player)
{
	int		i;

	i = 0;
	while (i < player->num_sprite)
	{
		player->sprite_distance[i] = ((player->pos_x - player->sprites[i].x) *
				(player->pos_x - player->sprites[i].x) +
				(player->pos_y - player->sprites[i].y) *
				(player->pos_y - player->sprites[i].y));
		i++;
	}
	ft_swap_sprites(player);
}

void		s_sprite(t_player *player)
{
	int i;

	i = -1;
	while (++i < player->num_sprite)
		player->sprite_distance[i] = ((player->pos_x - player->sprites[i].x) *
				(player->pos_x - player->sprites[i].x) + (player->pos_y
					- player->sprites[i].y) * (player->pos_y -
						player->sprites[i].y));
	sort_sprites(player);
	i = -1;
	while (++i < player->num_sprite)
	{
		sprite_calcul(player, i);
		player->stripe = player->draw_start_x - 1;
		while (++player->stripe < player->draw_end_x)
		{
			player->tex_x = (int)(256 * (player->stripe -
						(-player->sprite_width / 2 + player->sprite_screen_x))
					* player->tex[4].text_w / player->sprite_width) / 256;
			if (player->transform_y > 0 && player->stripe > 0 &&
					player->stripe < player->resolution[0]
					&& player->transform_y < player->z_buffer[player->stripe])
				draw_sprite(player);
		}
	}
}

void		sprite_calcul_help(t_player *player)
{
	if (player->draw_start_x < 0)
		player->draw_start_x = 0;
	player->draw_end_x = player->sprite_width / 2 + player->sprite_screen_x;
	if (player->draw_end_x >= player->resolution[0])
		player->draw_end_x = player->resolution[0] - 1;
}

void		sprite_calcul(t_player *player, int i)
{
	player->sprite_x = player->sprites[i].x - player->pos_x;
	player->sprite_y = player->sprites[i].y - player->pos_y;
	player->inv_det = 1.0 / (player->plane_x * player->dir_y
			- player->dir_x * player->plane_y);
	player->transform_x = player->inv_det * (player->dir_y *
			player->sprite_x - player->dir_x * player->sprite_y);
	player->transform_y = player->inv_det * (-player->plane_y *
			player->sprite_x + player->plane_x * player->sprite_y);
	player->sprite_screen_x = (int)((player->resolution[0] / 2) *
			(1 + player->transform_x / player->transform_y));
	player->sprite_height = abs((int)(player->resolution[1]
				/ (player->transform_y)));
	player->draw_start_y = -player->sprite_height / 2
		+ player->resolution[1] / 2;
	if (player->draw_start_y < 0)
		player->draw_start_y = 0;
	player->draw_end_y = player->sprite_height / 2 + player->resolution[1] / 2;
	if (player->draw_end_y >= player->resolution[1])
		player->draw_end_y = player->resolution[1] - 1;
	player->sprite_width = abs((int)(player->resolution[1] /
				(player->transform_y)));
	player->draw_start_x = -player->sprite_width / 2 + player->sprite_screen_x;
	sprite_calcul_help(player);
}
