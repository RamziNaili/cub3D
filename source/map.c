/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:50:06 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 10:45:04 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_max(t_player *parse)
{
	int		i;
	int		max;

	i = 0;
	max = ft_strlen(parse->map[i]);
	while (parse->map[i])
	{
		if (ft_strlen(parse->map[i]) > max)
			max = ft_strlen(parse->map[i]);
		i++;
	}
	parse->map_p.max_y = i;
	parse->map_p.max_x = max;
}

void	check_around(t_player *parse, int x, int y)
{
	char c;

	c = parse->map[x - 1][y];
	if (c == ' ')
		display_err(23);
	c = parse->map[x + 1][y];
	if (c == ' ')
		display_err(23);
	c = parse->map[x][y - 1];
	if (c == ' ')
		display_err(23);
	c = parse->map[x][y + 1];
	if (c == ' ')
		display_err(23);
}

void	check_side(t_player *parse)
{
	int		i;
	char	c;

	i = 1;
	while (i < parse->map_p.max_y - 2)
	{
		c = parse->map[i][0];
		if (c != '1' && is_space(c) != 1)
		{
			display_err(23);
		}
		c = parse->map[i][ft_strlen(parse->map[i]) - 1];
		if (c != '1' && is_space(c) != 1)
		{
			display_err(23);
		}
		i++;
	}
}

void	check_map(t_player *parse)
{
	int		i;
	char	c;

	i = 0;
	if (parse->map_p.p == 'a')
		display_err(16);
	while (parse->map[0][i])
	{
		c = parse->map[0][i];
		if (c != '1' && c != ' ')
			display_err(2);
		i++;
	}
	i = 0;
	while (parse->map[parse->map_p.max_y - 1][i])
	{
		c = parse->map[parse->map_p.max_y - 1][i];
		if (c != '1' && c != ' ')
			display_err(2);
		i++;
	}
	check_side(parse);
}

void	ft_map_pos(t_player *parse)
{
	int		i;
	int		y;
	char	c;

	i = 1;
	check_size(parse);
	while (parse->map[i + 1])
	{
		y = 1;
		while (parse->map[i][y + 1])
		{
			c = parse->map[i][y];
			if (c != '0' && c != '1' && c != '2' && c != ' '
					&& c != 'N' && c != 'S' && c != 'W' && c != 'E')
				display_err(2);
			if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
				check_around(parse, i, y);
			y++;
		}
		i++;
	}
	ft_sprite(parse);
	ft_max(parse);
	player(parse);
	check_map(parse);
}
