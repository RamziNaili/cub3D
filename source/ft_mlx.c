/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:53:01 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 09:21:25 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_player *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_exit(t_player *player)
{
	if (player->bmp != 1)
		mlx_destroy_window(player->mlx, player->win);
	mlx_destroy_image(player->mlx, player->img);
	mlx_destroy_image(player->mlx, player->tex[0].text);
	mlx_destroy_image(player->mlx, player->tex[1].text);
	mlx_destroy_image(player->mlx, player->tex[2].text);
	mlx_destroy_image(player->mlx, player->tex[3].text);
	mlx_destroy_image(player->mlx, player->tex[4].text);
	mlx_loop_end(player->mlx);
	mlx_destroy_display(player->mlx);
	free(player->mlx);
	free(player->map);
	free(player->z_buffer);
	free(player->sprites);
	free(player->tab_sprite);
	free(player->sprite_distance);
	exit(1);
}

void	raycasting(t_player *player)
{
	init_var(player);
	texture_init(player);
	if (player->bmp == 1)
		main_loop(player);
	mlx_loop_hook(player->mlx, &main_loop, player);
	if (player->bmp != 1)
	{
		mlx_hook(player->win, 2, 1L << 0, pressed_key, player);
		mlx_hook(player->win, 3, 1L << 1, released_key, player);
		mlx_hook(player->win, 33, 1L << 17, ft_exit, player);
	}
	mlx_loop(player->mlx);
}

int		main_loop(t_player *player)
{
	int i;

	i = -1;
	while (++i < player->resolution[0])
	{
		init_var_dda(player, i);
		init_var_dda_2(player);
		dda_algo(player);
		draw_calcul(player);
		side_texture(player);
		player->step = 1.0 * player->tex[player->index_texture].text_h
			/ player->line_height;
		player->tex_pos = (player->draw_start - player->resolution[1] / 2 +
				player->line_height / 2) * player->step;
		draw_ceilling(player, i);
		player->z_buffer[i] = player->perp_wall_dist;
	}
	s_sprite(player);
	if (player->bmp == 1)
		ft_create_bmp(player);
	move(player);
	if (player->bmp != 1)
		mlx_put_image_to_window(player->mlx, player->win, player->img, 0, 0);
	return (0);
}
