/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:51:34 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 11:12:51 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	test_parse(t_player *parse)
{
	if (parse->resolution[0] == 0 || parse->resolution[1] == 0)
		display_err(4);
	else if (parse->north == NULL || parse->south == NULL || parse->west == NULL
			|| parse->east == NULL || parse->sprite == NULL)
		display_err(5);
	else if ((int)parse->f == -1 || (int)parse->c == -1)
		display_err(6);
}

void	launcher(char *str, t_player *parse)
{
	if (n_string(str) == 1 && parse->if_map == 0)
	{
		free(str);
		return ;
	}
	if (n_string(str) == 1 && parse->if_map == 1)
	{
		free(str);
		parse->end_map = 1;
		return ;
	}
	if (parse->end_map == 1 && n_string(str) != 1)
		display_err(23);
	if (is_num(str[0]) != 1 && is_space(str[0]) != 1)
	{
		if (if_correct_line(str) == 1 && parse->tmp == NULL)
			display_err(23);
		ft_wparam(str, parse);
		return ;
	}
	test_parse(parse);
	ft_stock_map(str, parse);
	free(str);
}

int		check_xpm(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != 'm')
		return (-1);
	i--;
	if (str[i] != 'p')
		return (-1);
	i--;
	if (str[i] != 'x')
		return (-1);
	i--;
	if (str[i] != '.')
		return (-1);
	return (0);
}

void	test_xpm(t_player *parse)
{
	if (check_xpm(parse->north) == -1 || check_xpm(parse->south) == -1)
		display_err(15);
	if (check_xpm(parse->west) == -1 || check_xpm(parse->east) == -1)
		display_err(15);
	if (check_xpm(parse->sprite) == -1)
		display_err(15);
}

void	parcing(int fd, t_player *parse)
{
	int		ret;
	char	*buf;

	ft_init_struct(parse);
	while ((ret = get_next_line(fd, &buf)))
	{
		if (ret == -1)
			display_err(21);
		launcher(buf, parse);
	}
	launcher(buf, parse);
	ft_test_param(parse);
	if (parse->tmp != NULL)
	{
		parse->map = ft_split(parse->tmp, '\n');
		free(parse->tmp);
	}
	if (parse->tmp == NULL)
		display_err(14);
	test_xpm(parse);
}
