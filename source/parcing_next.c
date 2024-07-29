/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 09:53:29 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/18 10:25:11 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_stock_map(char *str, t_player *parse)
{
	parse->if_map = 1;
	parse->tmp = ft_strjoin(parse->tmp, str);
}

void	ft_tronc(char **str)
{
	if (**str != ' ')
		display_err(18);
	while (**str == 32 || (**str >= 9 && **str <= 9))
		*str = *str + 1;
}

void	ft_test_double(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			break ;
		i++;
	}
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return ;
	display_err(13);
	exit(0);
}

void	ft_test_param(t_player *parse)
{
	ft_tronc(&parse->north);
	ft_tronc(&parse->south);
	ft_tronc(&parse->west);
	ft_tronc(&parse->east);
	ft_tronc(&parse->sprite);
	ft_test_double(parse->north);
	ft_test_double(parse->south);
	ft_test_double(parse->west);
	ft_test_double(parse->east);
	ft_test_double(parse->sprite);
}

int		n_string(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_space(str[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}
