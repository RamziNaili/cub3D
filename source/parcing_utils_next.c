/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 09:57:30 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 11:17:19 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_print_map(t_player *parse)
{
	int i;

	i = 0;
	while (parse->map[i] != NULL)
	{
		ft_putstr(parse->map[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void	ft_init_struct(t_player *parse)
{
	parse->resolution[0] = 0;
	parse->resolution[1] = 0;
	parse->sprite = NULL;
	parse->north = NULL;
	parse->south = NULL;
	parse->west = NULL;
	parse->east = NULL;
	parse->map = NULL;
	parse->tmp = NULL;
	parse->f = -1;
	parse->c = -1;
	parse->if_map = 0;
	parse->end_map = 0;
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		is_space(char c)
{
	if (c == 32 || c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	test_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		display_err(23);
	if (g < 0 || g > 255)
		display_err(23);
	if (b < 0 || b > 255)
		display_err(23);
}
