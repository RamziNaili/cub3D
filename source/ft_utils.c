/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:38:13 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/24 11:13:36 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	display_err(int code)
{
	ft_printf("Error %d : ", code);
	code == 1 ? ft_printf("There is 2 players in the map !\n") : 0;
	code == 2 ? ft_printf("Caractere invalid\n") : 0;
	code == 3 ? ft_printf("Parameter arn't valid\n") : 0;
	code == 4 ? ft_printf("Missing parameter : resolution !\n") : 0;
	code == 5 ? ft_printf("Missing textures, be sure to put them all.\n") : 0;
	code == 6 ? ft_printf("Missing trgb, ceilling or floor.\n") : 0;
	code == 7 ? ft_printf("Resolution not valid.?\n") : 0;
	code == 8 ? ft_printf("TRGB not valid.\n") : 0;
	code == 9 ? ft_printf("Textures path invalid.\n") : 0;
	code == 10 ? ft_printf("There is no player.\n") : 0;
	code == 11 ? ft_printf("Double parameter resolution.\n") : 0;
	code == 12 ? ft_printf("Double path texture.\n") : 0;
	code == 13 ? ft_printf("Do not forget to give me a map.\n") : 0;
	code == 14 ? ft_printf("texture have not xpm extension.\n") : 0;
	code == 15 ? ft_printf("There is no player.\n") : 0;
	code == 16 ? ft_printf("Impossible to open the texturre.\n") : 0;
	code == 17 ? ft_printf("No space before path text.\n") : 0;
	code == 18 ? ft_printf("Not \".cub\" extension.\n") : 0;
	code == 19 ? ft_printf("Impossible to open the argument.\n") : 0;
	code == 20 ? ft_printf("Gnl return -1.\n") : 0;
	code == 21 ? ft_printf("impossible to create bmp.\n") : 0;
	code == 22 ? ft_printf("Color must be between 0 & 255.\n") : 0;
	code == 23 ? ft_printf("File invalid.\n") : 0;
	exit(0);
}

void	ft_normed_param(char *str, t_player *parse)
{
	if (str[0] == 'W' && str[1] == 'E')
	{
		if (parse->west != NULL)
			display_err(23);
		parse->west = ft_substr(str, 2, ft_strlen(str));
	}
	else if (str[0] == 'E' && str[1] == 'A')
	{
		if (parse->east != NULL)
			display_err(23);
		parse->east = ft_substr(str, 2, ft_strlen(str));
	}
	else if (str[0] == 'S')
	{
		if (parse->sprite != NULL)
			display_err(23);
		parse->sprite = ft_substr(str, 1, ft_strlen(str));
	}
	else
		normed_wparam(str, parse);
}

int		if_correct_line(char *str)
{
	if (str[0] != 'R' && str[0] != 'N' && str[0] != 'S' &&
			str[0] != 'E' && str[0] != 'W' &&
			str[0] != 'C' && str[0] != 'F'
			&& str[0] != '\0')
		return (1);
	return (0);
}

int		is_num(char c)
{
	if (c >= 48 && c <= 58)
		return (1);
	return (0);
}

void	check_name(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		display_err(20);
	str += (ft_strlen(str) - 4);
	if (*str != '.')
		display_err(19);
	str++;
	if (*str != 'c')
		display_err(19);
	str++;
	if (*str != 'u')
		display_err(19);
	str++;
	if (*str != 'b')
		display_err(19);
}
