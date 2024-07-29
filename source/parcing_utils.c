/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 09:56:58 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 11:16:40 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (-1);
	}
	return (0);
}

int		ft_stock_trgb(char *str)
{
	int		r;
	int		g;
	int		b;
	int		rtn;

	r = ft_atoi(str);
	while (*str != ',')
		str++;
	str++;
	g = ft_atoi(str);
	while (*str != ',')
		str++;
	str++;
	b = ft_atoi(str);
	while (*str > 8 && *str < 14)
		str++;
	while (*str > 47 && *str < 58)
		str++;
	rtn = empty_line(str);
	test_rgb(r, g, b);
	if (rtn == -1)
		display_err(8);
	return (create_trgb(0, r, g, b));
}

int		ft_resolution(char *str, t_player *parse)
{
	int rtn;

	if (parse->resolution[0] != 0 || parse->resolution[1] != 0)
	{
		display_err(11);
		exit(0);
	}
	parse->resolution[0] = ft_atoi(str);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str > 47 && *str < 58)
		str++;
	parse->resolution[1] = ft_atoi(str);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str > 47 && *str < 58)
		str++;
	rtn = empty_line(str);
	if (rtn == -1)
	{
		display_err(7);
		exit(0);
	}
	return (0);
}

void	normed_wparam(char *str, t_player *parse)
{
	if (str[0] == 'F')
	{
		parse->f = ft_stock_trgb(str + 1);
		free(str);
	}
	else if (str[0] == 'C')
	{
		parse->c = ft_stock_trgb(str + 1);
		free(str);
	}
}

int		ft_wparam(char *str, t_player *parse)
{
	int		i;

	if (str[0] == 'R')
	{
		i = ft_resolution(str + 1, parse) == 0 ? 0 : -1;
		free(str);
		return (i);
	}
	else if (str[0] == 'N' && str[1] == 'O')
	{
		if (parse->north != NULL)
			display_err(23);
		parse->north = ft_substr(str, 2, ft_strlen(str));
	}
	else if (str[0] == 'S' && str[1] == 'O')
	{
		if (parse->south != NULL)
			display_err(23);
		parse->south = ft_substr(str, 2, ft_strlen(str));
	}
	ft_normed_param(str, parse);
	return (0);
}
