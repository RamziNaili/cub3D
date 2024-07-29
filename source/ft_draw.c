/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:59:08 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 11:15:23 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			draw_ceilling(t_player *player, int i)
{
	int x;

	x = 0;
	while (x < player->draw_start)
	{
		my_mlx_pixel_put(player, i, x, player->c);
		x++;
	}
	draw_tex_wall(player, i);
}

void			draw_tex_wall(t_player *player, int i)
{
	int s;

	s = player->draw_start;
	s = s < 0 ? 0 : s;
	player->draw_end = player->draw_end < 0 ? player->resolution[1]
	: player->draw_end;
	while (s < player->draw_end)
	{
		player->tex_y = (int)player->tex_pos &
			(player->tex[player->index_texture].text_h - 1);
		player->tex_pos += player->step;
		player->color = *(unsigned int*)(player->tex[player->index_texture].
				text_data + (4 * player->tex[player->index_texture].text_w *
					player->tex_y) + (4 * player->tex_x));
		my_mlx_pixel_put(player, i, s, player->color);
		s++;
	}
	draw_floor(player, i);
}

void			draw_floor(t_player *player, int i)
{
	int x;

	x = player->draw_end;
	while (x < player->resolution[1])
	{
		my_mlx_pixel_put(player, i, x, player->f);
		x++;
	}
}

void			draw_sprite(t_player *player)
{
	int i;

	i = player->draw_start_y;
	while (i < player->draw_end_y)
	{
		player->color_s = (i * 256) - player->resolution[1]
			* 128 + player->sprite_height * 128;
		player->tex_y = ((player->color_s * player->tex[4].text_h)
				/ player->sprite_height) / 256;
		player->color_s = *(unsigned int*)(player->tex[4].text_data
				+ (4 * player->tex[4].text_w
					* player->tex_y) + (4 * player->tex_x));
		if ((player->color_s & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(player, player->stripe, i, player->color_s);
		i++;
	}
}
