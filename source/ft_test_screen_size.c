/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_screen_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:56:27 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/23 13:23:40 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	test_screen_size(t_player *player)
{
	int x;
	int y;

	mlx_get_screen_size(player->mlx, &x, &y);
	player->resolution[0] = player->resolution[0] > x ?
		x : player->resolution[0];
	player->resolution[1] = player->resolution[1] > y ?
		y : player->resolution[1];
}
