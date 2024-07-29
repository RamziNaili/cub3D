/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:33:02 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 08:05:10 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	normed_if_player(t_player *parse, char c, int i, int y)
{
	parse->map_p.p = c;
	parse->map_p.x = i;
	parse->map_p.y = y;
	parse->map[i][y] = 48;
}

void	player(t_player *parse)
{
	int		i;
	int		y;
	int		p;
	char	c;

	i = -1;
	p = 0;
	parse->map_p.p = 'a';
	while (parse->map[++i])
	{
		y = -1;
		while (parse->map[i][++y])
		{
			c = parse->map[i][y];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				if (p == 1)
					display_err(1);
				normed_if_player(parse, c, i, y);
				p = 1;
			}
		}
	}
}

void	check_size(t_player *parse)
{
	int i;

	i = 0;
	while (parse->map[i])
		i++;
	if (i < 3)
		display_err(23);
}

void	normed_sprite(t_player *parse)
{
	int i;
	int t;
	int y;

	i = -1;
	t = 0;
	while (parse->map[++i])
	{
		y = -1;
		while (parse->map[i][++y])
		{
			if (parse->map[i][y] == '2')
			{
				parse->sprites[t].x = (double)i + 0.5;
				parse->sprites[t].y = (double)y + 0.5;
				t++;
			}
		}
	}
}

void	ft_sprite(t_player *parse)
{
	int i;
	int y;

	i = -1;
	parse->num_sprite = 0;
	while (parse->map[++i])
	{
		y = 0;
		while (parse->map[i][y])
		{
			if (parse->map[i][y] == '2')
				parse->num_sprite++;
			y++;
		}
	}
	if (!(parse->sprite_distance = malloc(sizeof(double) * parse->num_sprite)))
		ft_exit(parse);
	if (!(parse->sprites = malloc(sizeof(t_sprites) * (parse->num_sprite))))
		ft_exit(parse);
	normed_sprite(parse);
}
