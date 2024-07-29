/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:03:03 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 09:44:00 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	side_texture(t_player *player)
{
	if (player->side == 1)
	{
		if (player->ray_dir_y < 0)
		{
			player->index_texture = 3;
		}
		else
			player->index_texture = 2;
	}
	else
	{
		if (player->ray_dir_x < 0)
			player->index_texture = 1;
		else
			player->index_texture = 0;
	}
	player->tex_x = (int)(player->wall_x *
			(double)(player->tex[player->index_texture].text_w));
	if (player->side == 0 && player->ray_dir_x > 0)
		player->tex_x = player->tex[player->index_texture].text_w
			- player->tex_x - 1;
	if (player->side == 1 && player->ray_dir_y < 0)
		player->tex_x = player->tex[player->index_texture].text_w
			- player->tex_x - 1;
}

void	texture_help(t_player *player)
{
	if (player->tex[2].text == NULL)
		display_err(17);
	player->tex[2].text_data = mlx_get_data_addr(player->tex[2].text,
			&player->tex[2].text_sb, &player->tex[2].text_sl,
			&player->tex[2].text_ed);
	player->tex[3].text = mlx_xpm_file_to_image(player->mlx, player->west,
			&player->tex[3].text_w, &player->tex[3].text_h);
	if (player->tex[3].text == NULL)
		display_err(16);
	player->tex[3].text_data = mlx_get_data_addr(player->tex[3].text,
			&player->tex[3].text_sb, &player->tex[3].text_sl,
			&player->tex[3].text_ed);
	player->tex[4].text = mlx_xpm_file_to_image(player->mlx, player->sprite,
			&player->tex[4].text_w, &player->tex[4].text_h);
	if (player->tex[4].text == NULL)
		display_err(16);
	player->tex[4].text_data = mlx_get_data_addr(player->tex[4].text,
			&player->tex[4].text_sb, &player->tex[4].text_sl,
			&player->tex[4].text_ed);
}

void	texture_init(t_player *player)
{
	player->tex[0].text = mlx_xpm_file_to_image(player->mlx, player->south,
			&player->tex[0].text_w, &player->tex[0].text_h);
	if (player->tex[0].text == NULL)
		display_err(16);
	player->tex[0].text_data = mlx_get_data_addr(player->tex[0].text,
			&player->tex[0].text_sb, &player->tex[0].text_sl,
			&player->tex[0].text_ed);
	player->tex[1].text = mlx_xpm_file_to_image(player->mlx, player->north,
			&player->tex[1].text_w, &player->tex[1].text_h);
	if (player->tex[1].text == NULL)
		display_err(16);
	player->tex[1].text_data = mlx_get_data_addr(player->tex[1].text,
			&player->tex[1].text_sb, &player->tex[1].text_sl,
			&player->tex[1].text_ed);
	player->tex[2].text = mlx_xpm_file_to_image(player->mlx, player->east,
			&player->tex[2].text_w, &player->tex[2].text_h);
	texture_help(player);
}
