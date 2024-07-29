/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:06:53 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/23 14:31:40 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		pressed_key(int keycode, t_player *player)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (keycode == player->tab_key[i])
			return (1);
		i++;
	}
	i = 0;
	while (player->tab_key[i] != -1 && i < 10)
	{
		i++;
	}
	player->tab_key[i] = keycode;
	return (1);
}

void	help_n_release(t_player *player, int keycode)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (player->tab_key[i] == keycode)
		{
			player->tab_key[i] = -1;
			break ;
		}
		i++;
	}
}

int		released_key(int keycode, t_player *player)
{
	int		i;
	int		y;
	int		tmp;

	i = 0;
	help_n_release(player, keycode);
	while (i < 10)
	{
		y = 9;
		while (y > 0)
		{
			if (player->tab_key[y] != -1 && player->tab_key[y - 1] == -1)
			{
				tmp = player->tab_key[y];
				player->tab_key[y] = player->tab_key[y - 1];
				player->tab_key[y] = tmp;
			}
			y--;
		}
		i++;
	}
	return (1);
}
